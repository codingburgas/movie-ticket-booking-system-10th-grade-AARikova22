#pragma once
#include <iostream>
#include <string>
using namespace std;
struct Seat {
	string seattype;
	double price;
	bool isReserved;
	bool isreserved();
	void printseatinfo();
};