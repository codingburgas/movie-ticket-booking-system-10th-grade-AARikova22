#include <iostream>
#include <vector>
#include <string>
#include <limits> 
#include "../include/cinema.h"
#include "../include/admin.h"
#include "../include/user_interface.h"

using namespace std;

int main() {
    Cinema GrandMallCinema;
    GrandMallCinema.name = "Grand Mall Cinema";
    GrandMallCinema.town = "Burgas";

    const double silver_price = 10.00;
    const double gold_price = 15.00;
    const double platinum_price = 20.00;

    GrandMallCinema.movies.push_back({ "Now You See Me", "English", "Thriller", "2013" });
    GrandMallCinema.movies.push_back({ "Lilo and Stitch", "Bulgarian", "Comedy", "2002" });
    GrandMallCinema.movies.push_back({ "Beetlejuice", "Bulgarian", "Fantasy", "1988" });
    GrandMallCinema.movies.push_back({ "NeverEnding Story", "Bulgarian", "Fantasy", "1984" });
    GrandMallCinema.movies.push_back({ "Secret Window", "English", "Thriller", "2004" });
    GrandMallCinema.movies.push_back({ "Coraline", "Bulgarian", "Horror", "2009" });
    GrandMallCinema.movies.push_back({ "The Book of Henry", "Bulgarian", "Drama", "2017" });
    GrandMallCinema.movies.push_back({ "Run Lola Run", "English", "Thriller", "1998" });
    GrandMallCinema.movies.push_back({ "What We Do In The Shadows", "English", "Comedy", "2014" });
    GrandMallCinema.movies.push_back({ "Labyrinth", "Bulgarian", "Fantasy", "1986" });


    Hall hall1;
    hall1.HallNumber = 1;
    hall1.silverSeatsCount = 5;
    hall1.goldSeatsCount = 3;
    hall1.platinumSeatsCount = 2;

    Hall hall2;
    hall2.HallNumber = 2;
    hall2.silverSeatsCount = 10;
    hall2.goldSeatsCount = 5;
    hall2.platinumSeatsCount = 3;

    Hall hall3;
    hall3.HallNumber = 3;
    hall3.silverSeatsCount = 15;
    hall3.goldSeatsCount = 10;
    hall3.platinumSeatsCount = 5;




    Show runlolarun = { &GrandMallCinema.movies[7], "15:30" };
    for (int i = 0; i < hall1.silverSeatsCount; ++i) runlolarun.seats.push_back({ "silver", silver_price, false });
    for (int i = 0; i < hall1.goldSeatsCount; ++i) runlolarun.seats.push_back({ "gold", gold_price, false });
    for (int i = 0; i < hall1.platinumSeatsCount; ++i) runlolarun.seats.push_back({ "platinum", platinum_price, false });

    Show nowyouseeme = { &GrandMallCinema.movies[0], "20:00" };
    for (int i = 0; i < hall1.silverSeatsCount; ++i) nowyouseeme.seats.push_back({ "silver", silver_price, false });
    for (int i = 0; i < hall1.goldSeatsCount; ++i) nowyouseeme.seats.push_back({ "gold", gold_price, false });
    for (int i = 0; i < hall1.platinumSeatsCount; ++i) nowyouseeme.seats.push_back({ "platinum", platinum_price, false });

    Show liloandstitch = { &GrandMallCinema.movies[1], "14:30" };
    for (int i = 0; i < hall1.silverSeatsCount; ++i) liloandstitch.seats.push_back({ "silver", silver_price, false });
    for (int i = 0; i < hall1.goldSeatsCount; ++i) liloandstitch.seats.push_back({ "gold", gold_price, false });
    for (int i = 0; i < hall1.platinumSeatsCount; ++i) liloandstitch.seats.push_back({ "platinum", platinum_price, false });

    hall1.shows = { runlolarun, nowyouseeme, liloandstitch };


    Show whatwedointheshadows = { &GrandMallCinema.movies[8], "17:30" };
    for (int i = 0; i < hall2.silverSeatsCount; ++i) whatwedointheshadows.seats.push_back({ "silver", silver_price, false });
    for (int i = 0; i < hall2.goldSeatsCount; ++i) whatwedointheshadows.seats.push_back({ "gold", gold_price, false });
    for (int i = 0; i < hall2.platinumSeatsCount; ++i) whatwedointheshadows.seats.push_back({ "platinum", platinum_price, false });

    Show thebookofgenry = { &GrandMallCinema.movies[6], "12:00" };
    for (int i = 0; i < hall2.silverSeatsCount; ++i) thebookofgenry.seats.push_back({ "silver", silver_price, false });
    for (int i = 0; i < hall2.goldSeatsCount; ++i) thebookofgenry.seats.push_back({ "gold", gold_price, false });
    for (int i = 0; i < hall2.platinumSeatsCount; ++i) thebookofgenry.seats.push_back({ "platinum", platinum_price, false });

    Show beetlejuice = { &GrandMallCinema.movies[2], "15:30" };
    for (int i = 0; i < hall2.silverSeatsCount; ++i) beetlejuice.seats.push_back({ "silver", silver_price, false });
    for (int i = 0; i < hall2.goldSeatsCount; ++i) beetlejuice.seats.push_back({ "gold", gold_price, false });
    for (int i = 0; i < hall2.platinumSeatsCount; ++i) beetlejuice.seats.push_back({ "platinum", platinum_price, false });

    hall2.shows = { whatwedointheshadows, thebookofgenry, beetlejuice };


    Show labyrinth = { &GrandMallCinema.movies[9], "19:30" };
    for (int i = 0; i < hall3.silverSeatsCount; ++i) labyrinth.seats.push_back({ "silver", silver_price, false });
    for (int i = 0; i < hall3.goldSeatsCount; ++i) labyrinth.seats.push_back({ "gold", gold_price, false });
    for (int i = 0; i < hall3.platinumSeatsCount; ++i) labyrinth.seats.push_back({ "platinum", platinum_price, false });

    Show coraline = { &GrandMallCinema.movies[5], "18:00" };
    for (int i = 0; i < hall3.silverSeatsCount; ++i) coraline.seats.push_back({ "silver", silver_price, false });
    for (int i = 0; i < hall3.goldSeatsCount; ++i) coraline.seats.push_back({ "gold", gold_price, false });
    for (int i = 0; i < hall3.platinumSeatsCount; ++i) coraline.seats.push_back({ "platinum", platinum_price, false });

    Show neverendingstory = { &GrandMallCinema.movies[3], "16:00" };
    for (int i = 0; i < hall3.silverSeatsCount; ++i) neverendingstory.seats.push_back({ "silver", silver_price, false });
    for (int i = 0; i < hall3.goldSeatsCount; ++i) neverendingstory.seats.push_back({ "gold", gold_price, false });
    for (int i = 0; i < hall3.platinumSeatsCount; ++i) neverendingstory.seats.push_back({ "platinum", platinum_price, false });

    Show secretwindow = { &GrandMallCinema.movies[4], "14:00" };
    for (int i = 0; i < hall3.silverSeatsCount; ++i) secretwindow.seats.push_back({ "silver", silver_price, false });
    for (int i = 0; i < hall3.goldSeatsCount; ++i) secretwindow.seats.push_back({ "gold", gold_price, false });
    for (int i = 0; i < hall3.platinumSeatsCount; ++i) secretwindow.seats.push_back({ "platinum", platinum_price, false });

    hall3.shows = { labyrinth, coraline, neverendingstory, secretwindow };


    GrandMallCinema.halls = { hall1, hall2, hall3 };

    int choice;
    do {
        cout << "============================================================\n";
        cout << "      +--------------------------------------------+\n";
        cout << "      |       WELCOME TO MOVIE BOOKING SYSTEM      |\n";
        cout << "      +--------------------------------------------+\n";
        cout << "============================================================\n\n";
        cout << "            * Where stories come to life *\n\n";
        cout << "       ---------------------------------------------\n";
        cout << "       | Please choose an option from the menu:    |\n";
        cout << "       ---------------------------------------------\n\n";
        cout << "  [1] View All Shows\n\n";
        cout << "  [2] Search and Book a Movie Ticket\n\n";
        cout << "  [3] Admin Login\n\n";
        cout << "  [0] Exit Application\n\n";
        cout << "------------------------------------------------------------\n";
        cout << "               Enter your choice (1-4): ";
        cout << "\n------------------------------------------------------------\n";

        cin >> choice;

        while (cin.fail()) {
            cout << "Error. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> choice;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            GrandMallCinema.printallshowsInHalls();
            break;
        case 2:
            searchMenu(GrandMallCinema);
            break;
        case 3: {
            Admin admin;
            if (admin.login()) {
                adminMenu(GrandMallCinema);
            }
            break;
        }
        case 0:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}