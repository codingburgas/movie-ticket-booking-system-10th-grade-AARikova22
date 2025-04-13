#include <iostream>
#include <string>
#include <iostream>
#include <string>
#include "../include/seat.h"
#include "../include/show.h"
#include "../include/Hall.h"
#include "../include/cinema.h"





int main() {
    Show runlolarun;
    runlolarun.title = "Run Lola Run";
    runlolarun.time = "15:30";

    runlolarun.seats = {
        {"silver", false},
        {"gold", false},
        {"platinum", false}
    };

    runlolarun.printMovieInfo();

    Show whatwedointheshadows;
    
    whatwedointheshadows.title = "What We Do In The Shadows";
    whatwedointheshadows.time = "17:30";

    whatwedointheshadows.seats = {
        {"silver", false},
        {"gold", false},
        {"platinum", false}
    };

    whatwedointheshadows.printMovieInfo();
    Show labyrinth;

    labyrinth.title = "Labyrinth";
    labyrinth.time = "19:30";

    labyrinth.seats = {
        {"silver", false},
        {"gold", false},
        {"platinum", false}
    };

    labyrinth.printMovieInfo();


    

 


    Hall Hall1;
    Hall1.HallNumber = 1;
    Hall1.shows = {
        {runlolarun}
    };
    Hall1.printallshows();

    Hall Hall2;
    Hall2.HallNumber = 2;
    Hall2.shows = {
        {whatwedointheshadows}
    };
    Hall2.printallshows();

    Hall Hall3;
    Hall3.HallNumber = 3;
    Hall3.shows = {
        {labyrinth}
    };
    Hall3.printallshows();


    Cinema GrandMallCinema;
    GrandMallCinema.name = "Grand Mall Cinema";
    GrandMallCinema.town = "Varna";
    GrandMallCinema.halls = {
        {1},
        {2},
        {3}
    };


    return 0;
}