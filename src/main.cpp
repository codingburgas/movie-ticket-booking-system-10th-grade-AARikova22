#include <iostream>
#include <string>
#include "../include/seat.h"
#include "../include/show.h"
#include "../include/Hall.h"
#include "../include/cinema.h"
using namespace std;
int main() {
    Show runlolarun;
    runlolarun.title = "Run Lola Run";
    runlolarun.time = "15:30";
    runlolarun.seats = {
        {"silver", false},
        {"gold", false},
        {"platinum", false}
    };

    Show whatwedointheshadows;
    whatwedointheshadows.title = "What We Do In The Shadows";
    whatwedointheshadows.time = "17:30";
    whatwedointheshadows.seats = {
        {"silver", false},
        {"gold", false},
        {"platinum", false}
    };

    Show labyrinth;
    labyrinth.title = "Labyrinth";
    labyrinth.time = "19:30";
    labyrinth.seats = {
        {"silver", false},
        {"gold", false},
        {"platinum", false}
    };

    Hall hall1;
    hall1.HallNumber = 1;
    hall1.shows = { runlolarun };

    Hall hall2;
    hall2.HallNumber = 2;
    hall2.shows = { whatwedointheshadows };

    Hall hall3;
    hall3.HallNumber = 3;
    hall3.shows = { labyrinth };

    Cinema GrandMallCinema;
    GrandMallCinema.name = "Grand Mall Cinema";
    GrandMallCinema.town = "Varna";
    GrandMallCinema.halls = {
        hall1, hall2, hall3
    };

    GrandMallCinema.printallshowsInHalls();
    cout << "Search movie...🖉";
        string usermovie;
    cin >> usermovie;
    vector<Show*> results = GrandMallCinema.SearchShow(usermovie);
    if (results.empty()) {
        cout << "Not found." << endl;
    }
    else {
        for (int i = 0; i < results.size(); i++) {
            (*results[i]).printMovieInfo();
        }
    }
    
    return 0;
}