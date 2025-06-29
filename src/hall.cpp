#include <iostream>
#include <vector>
#include "../include/hall.h"

using namespace std;

void Hall::printallshows() {
	cout << "All Shows at Hall No." << HallNumber << endl;
	for (int i = 0; i < shows.size(); i++) {
		if (shows[i].movie->title != "_DELETED_") {
			cout << shows[i].movie->title << " " << shows[i].time << endl;
		}
	}
}

