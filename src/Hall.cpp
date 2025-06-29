#include <iostream>
#include <vector>
#include "../include/hall.h"

using namespace std;

void Hall::printallshows() {
	cout << "All Shows at Hall №" << HallNumber << endl;
	for (int i = 0; i < shows.size(); i++) {
		cout << shows[i].movie->title << " " << shows[i].time << endl;
	}
}


