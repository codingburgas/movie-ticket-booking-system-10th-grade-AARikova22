#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include <cctype>
#include <numeric>
#include "../include/user_interface.h"
using namespace std;

void adminMenu(Cinema& cinema) {
    int choice;
    do {
        cout << "\n--- Admin Menu ---" << endl;
        cout << "1. Add Movie" << endl;
        cout << "2. Delete Movie" << endl;
        cout << "3. Add Show" << endl;
        cout << "4. Delete Show" << endl;
        cout << "5. Update Show" << endl;
        cout << "0. Exit Admin Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        while (cin.fail()) {
            cout << "Error. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> choice;
        }

        switch (choice) {
        case 1: cinema.addMovie(); break;
        case 2: cinema.deleteMovie(); break;
        case 3: cinema.addShow(); break;
        case 4: cinema.deleteShow(); break;
        case 5: cinema.updateShow(); break;
        case 0: cout << "Returning to main menu..." << endl; break;
        default: cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}


void displayResultsAndBook(Cinema& cinema, vector<SearchResult>& results) {
    if (results.empty()) {
        cout << "Sorry, no shows found for your criteria." << endl;
        return;
    }

    cout << "\nFound shows:" << endl;
    for (int i = 0; i < results.size(); ++i) {
        cout << i + 1 << ". " << results[i].show->movie->title
            << " | Hall: " << results[i].hallNumber
            << " | Time: " << results[i].show->time << endl;
    }

    cout << "\nSelect a show number to book (or 0 to cancel): ";
    int choice;
    cin >> choice;

    if (choice > 0 && choice <= results.size()) {
        SearchResult selectedResult = results[choice - 1];
        processBooking(cinema, selectedResult);
    }
}

void searchMenu(Cinema& cinema) {
    int choice;
    cout << "\n--- Search for a show ---" << endl;
    cout << "1. Search by Title" << endl;
    cout << "2. Search by Genre" << endl;
    cout << "3. Search by Language" << endl;
    cout << "4. Search by Release Year" << endl;
    cout << "0. Back to Main Menu" << endl;
    cout << "Your choice: ";
    cin >> choice;

    string query;
    vector<SearchResult> results;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice) {
    case 1:
        cout << "Enter movie title: ";
        getline(cin, query);
        results = cinema.SearchShow(query);
        break;
    case 2:
        cout << "Enter genre: ";
        getline(cin, query);
        results = cinema.SearchShowbygenre(query);
        break;
    case 3:
        cout << "Enter language: ";
        getline(cin, query);
        results = cinema.SearchShowbylanguage(query);
        break;
    case 4:
        cout << "Enter release year: ";
        getline(cin, query);
        results = cinema.SearchShowbyreleasedate(query);
        break;
    case 0:
        return;
    default:
        cout << "Invalid choice. Please try again." << endl;
        return;
    }

    displayResultsAndBook(cinema, results);
}


void processBooking(Cinema& cinema, SearchResult& selectedResult) {
    Show* selectedShow = selectedResult.show;

    cout << "\nYou have selected the show: " << selectedShow->movie->title
        << " at " << selectedShow->time << "." << endl;

    selectedShow->printSeatsInfo();

    int numToBook;
    cout << "\nHow many seats would you like to book? ";
    cin >> numToBook;

    if (numToBook <= 0) {
        cout << "Invalid number of seats." << endl;
        return;
    }

    vector<int> selectedSeats; 
    vector<int> seatIndices;   
    cout << "Please enter the seat numbers one by one:" << endl;
    for (int i = 0; i < numToBook; ++i) {
        int seatNum;
        cout << "Seat " << i + 1 << ": ";
        cin >> seatNum;
        selectedSeats.push_back(seatNum);
        seatIndices.push_back(seatNum - 1); 
    }

    bool allSeatsAreValid = true;
    double totalPrice = 0.0;

    for (int index : seatIndices) {
        if (index < 0 || index >= selectedShow->seats.size() || selectedShow->seats[index].isReserved) {
            cout << "Error: Seat " << index + 1 << " is invalid or already taken." << endl;
            allSeatsAreValid = false;
            break;
        }
    }

    if (allSeatsAreValid) {
        for (int index : seatIndices) {
            selectedShow->seatReservation(index);
            totalPrice += selectedShow->seats[index].price;
        }

        cout << "\nCongratulations! You have successfully reserved " << numToBook << " seat(s)." << endl;
        cout << "Total price: " << fixed << setprecision(2) << totalPrice << " USD." << endl;

        cout << "\nPlease choose your payment method:" << endl;
        cout << "1. Pay Online (Credit Card)" << endl;
        cout << "2. Pay at the Cinema" << endl;
        cout << "Your choice: ";
        int paymentChoice;
        cin >> paymentChoice;

        auto printAllTickets = [&]() {
            cout << "\n\nPrinting your ticket(s)...";
            for (int seatNum : selectedSeats) {
                printTicket(cinema, selectedResult, seatNum);
            }
            cout << "\n";
            };

        switch (paymentChoice) {
        case 1: {
            cout << "\n--- Online Payment ---" << endl;
            string cardNumber;
            cout << "Please enter your 16-digit card number (without spaces): ";
            cin >> cardNumber;

            bool isValid = cardNumber.length() == 16 && all_of(cardNumber.begin(), cardNumber.end(), ::isdigit);
            if (isValid) {
                cout << "\nPayment successful! Your booking is confirmed." << endl;
                printAllTickets();
                cout << "[NOTIFICATION] A new booking for " << numToBook << " ticket(s) has been made for '" << selectedShow->movie->title << "'." << endl;
            }
            else {
                cout << "\nError: Invalid card number." << endl;
                cout << "[NOTIFICATION] Booking for '" << selectedShow->movie->title << "' was cancelled." << endl;
                for (int index : seatIndices) selectedShow->unreserveSeat(index);
            }
            break;
        }
        case 2: {
            cout << "\n--- Pay at the Cinema ---" << endl;
            cout << "Your booking is confirmed." << endl;
            printAllTickets();
            cout << "[NOTIFICATION] A new booking for " << numToBook << " ticket(s) has been made for '" << selectedShow->movie->title << "'." << endl;
            break;
        }
        default: {
            cout << "\nInvalid payment option selected. Reservation cancelled." << endl;
            cout << "[NOTIFICATION] Booking for '" << selectedShow->movie->title << "' was cancelled." << endl;
            for (int index : seatIndices) selectedShow->unreserveSeat(index);
            break;
        }
        }
    }
    else {
        cout << "\nBooking failed. Please try again." << endl;
    }
}

void printTicket(const Cinema& cinema, const SearchResult& searchResult, int seatNumber) {
    const Show* show = searchResult.show;
    const Seat& seat = show->seats[seatNumber - 1];

    cout << "\n\n***************************************************" << endl;
    cout << "* *" << endl;
    cout << "* YOUR MOVIE TICKET                    *" << endl;
    cout << "* *" << endl;
    cout << "***************************************************" << endl;
    cout << "  CINEMA: " << cinema.name << ", " << cinema.town << endl;
    cout << "  HALL:   " << searchResult.hallNumber << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "  MOVIE:  " << show->movie->title << endl;
    cout << "  TIME:   " << show->time << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "  SEAT:   " << seatNumber << " (" << seat.seattype << ")" << endl;
    cout << "  PRICE:  " << fixed << setprecision(2) << seat.price << " USD" << endl;
    cout << "***************************************************" << endl;
    cout << "* ENJOY THE SHOW!                   *" << endl;
    cout << "***************************************************";
}