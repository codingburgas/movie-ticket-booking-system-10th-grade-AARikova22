#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Hall.h"
using namespace std;

struct Cinema {
	string name;
	string town;
	vector <Hall> halls;
	void printallshowsInHalls();
	
};