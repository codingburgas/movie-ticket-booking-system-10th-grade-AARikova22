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


    hall hall1;
    hall1.HallNumber = 1;
    hall1.shows = { runlolarun,nowyouseeme };

    hall hall2;
    hall2.HallNumber = 2;
    hall2.shows = { whatwedointheshadows, thebookofgenry };

    hall hall3;
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
    }
    
    return 0;
}