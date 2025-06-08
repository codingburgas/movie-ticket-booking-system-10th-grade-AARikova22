#include <iostream>
#include <vector>
#include <string>
#include <limits> 
#include "../include/cinema.h" 
using namespace std;

int main() {

    Movie movierunlolarun = { "Run Lola Run", "English", "Thriller", "1998" };

    Show runlolarun = { &movierunlolarun, "15:30", { {"silver", false},
          {"gold", false},
          {"platinum", false} } };

    Movie  moviewhatwedointheshadows = { "What We Do In The Shadows", "English", "Horror/Comedy", "2014" };
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

    cout << "Search movie...";
    string usermovie;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, usermovie);
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