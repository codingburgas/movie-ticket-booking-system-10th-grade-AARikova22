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
    hall1.silverCount = 20;
    hall1.goldCount = 10;
    hall1.platinumCount = 5;

    Hall hall2;
    hall2.HallNumber = 2;
    hall2.shows = { whatwedointheshadows, thebookofgenry };
    hall2.silverCount = 20;
    hall2.goldCount = 10;
    hall2.platinumCount = 5;

    Hall hall3;
    hall3.HallNumber = 3;
    hall3.shows = { labyrinth, coraline };
    hall3.silverCount = 20;
    hall3.goldCount = 10;
    hall3.platinumCount = 5;

    Cinema GrandMallCinema;
    GrandMallCinema.name = "Grand Mall Cinema";
    GrandMallCinema.town = "Varna";
    GrandMallCinema.halls = {
        hall1, hall2, hall3
    };

    
    GrandMallCinema.printallshowsInHalls();
   

    cout << "Do you want to add a movie? (y/n)" << endl;
    char usernewmoviechoice;
    cin >> usernewmoviechoice;
    if (usernewmoviechoice == 'n') {
        cout << "Back to the menu." << endl;
    }
    else if (usernewmoviechoice == 'y') {
        GrandMallCinema.addMovie();
    }
    else {
        cout << "Try again." << endl;
    }
    GrandMallCinema.printallshowsInHalls();
}
  
       









       


