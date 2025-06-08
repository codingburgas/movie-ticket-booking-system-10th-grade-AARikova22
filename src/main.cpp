#include <iostream>
#include <vector>
#include <string>
#include <limits> 
#include "../include/cinema.h" 
using namespace std;

int main() {

    Movie movienowyouseeme = { "Now You See Me", "English", "Thriller", "2013" };

    Show nowyouseeme = { &movienowyouseeme, "20:00", {{"silver", false}, {"gold", false },{"platinum", false}} };


    Movie moviecoraline = { "Coraline", "Bulgarian", "Horror", "2009" };

    Show coraline = { &moviecoraline, "18:00",  {{"silver", false}, {"gold", false },{"platinum", false}} };

   Movie moviethebookofgenry = { "The Book of Henry", "Bulgarian", "Drama", "2017" };

    Show thebookofgenry = { &moviethebookofgenry, "12:00",  {{"silver", false}, {"gold", false },{"platinum", false}} };



    Movie movierunlolarun = { "Run Lola Run", "English", "Thriller", "1998" };

    Show runlolarun = { &movierunlolarun, "15:30", { {"silver", false},
          {"gold", false},
          {"platinum", false} } };

    Movie  moviewhatwedointheshadows = { "What We Do In The Shadows", "English", "Comedy", "2014" };
    Show whatwedointheshadows = { &moviewhatwedointheshadows,"17:30", {
        {"silver", false},
        {"gold", false},
        {"platinum", false}
    } };

    Movie  movielabyrinth = { "Labyrinth", "Bulgarian", "Fantasy", "1986" };
    Show labyrinth = { &movielabyrinth,"19:30", {
        {"silver", false},
        {"gold", false},
        {"platinum", false}
    } };


    Hall hall1;
    hall1.HallNumber = 1;
    hall1.shows = { runlolarun,nowyouseeme };

    Hall hall2;
    hall2.HallNumber = 2;
    hall2.shows = { whatwedointheshadows, thebookofgenry };

    Hall hall3;
    hall3.HallNumber = 3;
    hall3.shows = { labyrinth, coraline };

    Cinema GrandMallCinema;
    GrandMallCinema.name = "Grand Mall Cinema";
    GrandMallCinema.town = "Varna";
    GrandMallCinema.halls = {
        hall1, hall2, hall3
    };


  //GrandMallCinema.printallshowsInHalls();

    cout << "Search movie...";
    string usermovie;

  //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, usermovie);

    vector<SearchResult> results = GrandMallCinema.SearchShow(usermovie);
    if (results.empty()) {
        cout << "Not found." << endl;
    }
    else {
        cout << "\nFound shows:" << endl;
        for (int i = 0; i < results.size(); i++) {
            results[i].show->printMovieInfo();
            cout << "Hall number: " << results[i].hallNumber << endl;
            results[i].show->printSeatsInfo();
            cout << endl;
        }


        char userChoice;
        cout << "Do you want to reserve a seat? (y/n): ";
        cin >> userChoice;

        if (userChoice == 'y' || userChoice == 'Y') {
            int showNumber = 1;

            if (results.size() > 1) {
                cout << "Enter the show number you want to book (e.g., 1): ";
                cin >> showNumber;
            }

            if (showNumber > 0 && showNumber <= results.size()) {
                int seatNumber;
                cout << "Enter the seat number you wish to reserve: ";
                cin >> seatNumber;


                Show* selectedShow = results[showNumber - 1].show;

                if (selectedShow->seatReservation(seatNumber - 1)) {
                    cout << "\n===================================" << endl;
                    cout << "  Seat successfully reserved!" << endl;
                    cout << "===================================" << endl;


                    cout << "\nUpdated seat status:" << endl;
                    selectedShow->printSeatsInfo();
                }
                else {
                    cout << "\n================================================" << endl;
                    cout << "Failed to reserve seat. \nIt may already be taken, or the seat number is incorrect.";
                    cout << "\n================================================" << endl;
                }
            }
            else {
                cout << "Invalid show number selected." << endl;
            }
        }
    }

return 0;

}