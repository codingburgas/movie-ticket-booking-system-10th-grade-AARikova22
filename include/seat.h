#pragma once
#include <iostream>
#include <string>
using namespace std;
struct Seat {
	string seattype;
	bool isReserved;
	bool isreserved();
	void printseatinfo();
}