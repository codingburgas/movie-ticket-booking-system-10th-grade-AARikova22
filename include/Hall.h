#pragma once
#include <iostream>
#include <vector>
#include "../include/show.h"

using namespace std;

struct Hall {
	int HallNumber;
	vector<show> Shows;
	void printallshows();
};