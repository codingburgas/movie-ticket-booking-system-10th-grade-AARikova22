#include <iostream>
#include <string>
#include <iomanip>
#include "../include/seat.h"
using namespace std;


// Attempts to reserve the seat
// Returns true if the seat was successfully reserved
// Returns false if the seat was already reserved
bool Seat::isreserved() {
	if (isReserved == true) {
		return false;
	}
	else {
		isReserved = true;
		return true;
	}
}
void Seat::printseatinfo() {
	cout << "Seat type: " << seattype
		<< " | Price: " << fixed << setprecision(2) << price << " BGN"
		<< " | Status: ";
	if (isReserved == true) {
		cout << "reserved";
	}
	else {
		cout << "available";
	}
}