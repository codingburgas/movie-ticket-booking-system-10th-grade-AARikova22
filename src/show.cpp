#include <iostream>
#include <string>
#include <vector>
#include "../include/show.h"
#include "../include/seat.h"
#include "../src/seat.cpp"
using namespace std;

	void show::printMovieInfo() {
		cout << "Title: " << title << endl << "Time: " << time << endl;
	}

	void show::printSeatsInfo() {
		cout << "Seats: " << endl;
		for (int i = 0; i < Seats.size(); i++) {
			cout << "Seat number: " << i + 1 << endl << Seats[i].printseatinfo() << endl;
		}
	}

	bool show::seatresetvation(number) {
		if ((number >= 0) && (number < Seats.size())) {
			Seats[number].isreserved();
				return isreserved();
		}
		else {
			return 0;
		}
	}