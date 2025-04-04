#include <iostream>
#include <vector>
#include "../include/Hall.h"

using namespace std;

	void Hall::printallshows(){
		cout << "All Shows at Hall №" << HallNumber << endl;
		for (int i = 0; i < Shows.size(); i++) {
			cout << Shows[i].title << " " << Shows[i].time << endl;
		}
	}
