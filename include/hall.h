#pragma once
#include <iostream>
#include <vector>
#include "../include/show.h"

using namespace std;

struct Hall {
	int HallNumber;
	vector<Show> shows;
	void printallshows();
	int  silverSeatsCount;
	int goldSeatsCount;
	int platinumSeatsCount;
};