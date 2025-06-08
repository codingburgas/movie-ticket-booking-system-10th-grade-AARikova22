#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "hall.h"
#include "movie.h"
using namespace std;

struct SearchResult {
	Show* show;
	int hallNumber;
};

struct Cinema {
	string name;
	string town;
	vector <Hall> halls;
	void printallshowsInHalls();
	vector <SearchResult> SearchShow(string usertitle);
	vector <Movie> movies;
};

