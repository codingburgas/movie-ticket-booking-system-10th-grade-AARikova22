#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include <cctype>
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

void userMenu(Cinema& cinema) {
    string title;
    cout << "\n--- Search for a Show ---" << endl;
    cout << "Enter the title of the movie you are looking for: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, title);

    vector<SearchResult> results = cinema.SearchShowbytitle(title);

    if (results.empty()) {
        cout << "Sorry, no shows found for the movie '" << title << "'." << endl;
        return;
    }

    cout << "\nFound shows for '" << title << "':" << endl;
    for (int i = 0; i < results.size(); ++i) {
        cout << i + 1 << ". Hall " << results[i].hallNumber
            << " | Time: " << results[i].show->time << endl;
    }

    cout << "\nSelect a show number to book (or 0 to cancel): ";
    int choice;
    cin >> choice;

    if (choice > 0 && choice <= results.size()) {
        SearchResult selectedResult = results[choice - 1];
        Show* selectedShow = selectedResult.show;

        cout << "\nYou have selected the show at " << selectedShow->time << "." << endl;
        selectedShow->printSeatsInfo();

        cout << "\nEnter the seat number to book: ";
        int seatNumber;
        cin >> seatNumber;

        if (seatNumber > 0 && seatNumber <= selectedShow->seats.size()) {
            if (selectedShow->seatReservation(seatNumber - 1)) {

                cout << "\nCongratulations! You have successfully reserved seat " << seatNumber << "." << endl;

                cout << "\nPlease choose your payment method:" << endl;
                cout << "1. Pay Online (Credit Card)" << endl;
                cout << "2. Pay at the Cinema" << endl;
                cout << "Your choice: ";
                int paymentChoice;
                cin >> paymentChoice;

                switch (paymentChoice) {
                case 1: {
                    cout << "\n--- Online Payment ---" << endl;
                    string cardNumber;
                    cout << "Please enter your 16-digit card number (without spaces): ";
                    cin >> cardNumber;

                    bool isValid = cardNumber.length() == 16;
                    if (isValid) {
                        for (char const& c : cardNumber) {
                            if (isdigit(c) == 0) {
                                isValid = false;
                                break;
                            }
                        }
                    }

                    if (isValid) {
                        cout << "\nValidating card... Processing payment..." << endl;
                        cout << "Payment successful! Your booking is confirmed." << endl;

                        printTicket(cinema, selectedResult, seatNumber);
                    }
                    else {
                        cout << "\nError: Invalid card number." << endl;
                        cout << "Your reservation is on hold. Please finalize your payment at the cinema." << endl;
                    }
                    break;
                }
                case 2: {
                    cout << "\n--- Pay at the Cinema ---" << endl;
                    cout << "Your booking is confirmed." << endl;
                    cout << "Please make sure to pay and pick up your ticket at the box office." << endl;

                    printTicket(cinema, selectedResult, seatNumber);
                    break;
                }
                default: {
                    cout << "\nInvalid payment option selected. Reservation cancelled." << endl;
                    break;
                }
                }

            }
            else {
                cout << "\nError! This seat is already taken. Please try again." << endl;
            }
        }
        else {
            cout << "\nError! This seat does not exist. Please try again." << endl;
        }
    }
}


void printTicket(const Cinema& cinema, const SearchResult& searchResult, int seatNumber) {
    const Show* show = searchResult.show;
    const Seat& seat = show->seats[seatNumber - 1];

    cout << "\n\n***************************************************" << endl;
    cout << "* *" << endl;
    cout << "* YOUR MOVIE TICKET                  *" << endl;
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
    cout << "* ENJOY THE SHOW!                     *" << endl;
    cout << "***************************************************\n\n" << endl;
}