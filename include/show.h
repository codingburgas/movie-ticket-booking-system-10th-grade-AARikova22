#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../include/seat.h"
using namespace std;

struct Show {
    string title;
    string time;
    vector<Seat> seats;

    void printMovieInfo();
    void printSeatsInfo();
    bool seatReservation(int number);
};