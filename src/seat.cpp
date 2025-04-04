#include <iostream>
#include <string>
#include "../include/seat.h"
using namespace std;



	bool seat::isreserved() {
		if (isReserved == true) {
			return false;
		}
		else {
			isReserved = true;
			return true;
		}
	}
	void seat::printseatinfo() {
		cout << "Seat type: " << seattype << endl << "Status: ";
		if (isReserved == true) {
			cout << "reserved";
		}
		else {
			cout << "available";
		}
	}
