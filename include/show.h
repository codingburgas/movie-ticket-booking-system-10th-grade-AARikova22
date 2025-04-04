#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../include/seat.h"

using namespace std;
struct show {
	string title;
	string time;
	vector<seat> Seats;
	void printMovieInfo();
	void printSeatsInfo();
	bool seatresetvation(number);
};