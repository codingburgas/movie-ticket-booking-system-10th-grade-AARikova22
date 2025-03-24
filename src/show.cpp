#include <iostream>
#include <string>
#include <vector>
#include "../include/show.h"
using namespace std;
struct show {
	string title;
	string time;
	vector<seat> Seats[];
	void printMovieInfo() {
		cout << "Title: " << title << endl << "Time: " << time << endl;
	}

	void printSeatsInfo() {
		cout << "Seats: " << endl;
		for (int i = 0; i < Seats.size(); i++) {
			cout << "Seat number: " << i + 1 << endl << Seats[i].printseatinfo() << endl;
		}
	}

	bool seatresetvation() {
		if ((number >= 0) && (number < Seats.size())) {
			Seats[number].isreserved()
				return isreserved();
		}
		else {
			return 0;
		}
	}

};