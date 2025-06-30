#pragma once
#include <iostream>
#include <string>
using namespace std;
class Seat {
public:
	string seattype;
	double price;
	bool isReserved;
	bool isreserved();
	void printseatinfo();
};