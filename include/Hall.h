#pragma once
#include <iostream>
#include <vector>
#include "../include/show.h"

using namespace std;

struct hall {
	int HallNumber;
	vector<Show> shows;
	void printallshows();
};