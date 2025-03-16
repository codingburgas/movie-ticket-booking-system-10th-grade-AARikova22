#include <iostream>
#include <string>
#include "../include/seat.h"
using namespace std;


struct Seat {
	string seattype;
	bool isReserved;
	bool isreserved() {
		if (isReserved == true) {
			return false;
		}
		else {
			isReserved = true;
			return true;
		}
	}
	void printseatinfo() {
		cout << "Seat type: " << seattype << endl << "Status: ";
		if (isReserved == true) {
			cout << "reserved";
		}
		else {
			cout << "available";
		}
	}
}