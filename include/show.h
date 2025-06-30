#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../include/seat.h"
#include "movie.h"
using namespace std;

class Show {
public:
    Movie* movie;
    string time;
    vector<Seat> seats;

    void printMovieInfo();
    void printSeatsInfo();
    bool seatReservation(int number);
    void unreserveSeat(int number);

};