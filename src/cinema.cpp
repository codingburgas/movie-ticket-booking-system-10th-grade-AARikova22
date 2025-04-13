#include <iostream>
#include "../include/cinema.h"

using namespace std;

void Cinema::printallshowsInHalls() {
	cout << "All halls: " << endl;
	for (int i = 0; i < halls.size(); i++) {
		cout << halls[i].HallNumber << ":" << endl; 
		halls[i].printallshows();
		cout << endl;
	}
