#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "hall.h"
#include "movie.h"
using namespace std;

struct Cinema {
	string name;
	string town;
	vector <Hall> halls;
	void printallshowsInHalls();
	vector <Show*> SearchShow(string usertitle);
	vector <Movie> movies;
};