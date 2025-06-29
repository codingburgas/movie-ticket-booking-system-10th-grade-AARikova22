#pragma once
#include <iostream>
#include <vector>
#include "../include/show.h"

using namespace std;

struct Hall {
	int HallNumber;
	vector<Show> shows;
	void printallshows();
	int  silverCount;
	int goldCount;
	int platinumCount;
};