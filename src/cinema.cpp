#include <iostream>
#include "../include/cinema.h"
#include "../include/Hall.h"

using namespace std;

void Cinema::printallshowsInHalls() {
	cout << "All halls: " << endl;
	for (int i = 0; i < halls.size(); i++) {
		cout << halls[i].HallNumber << ":" << endl;
		halls[i].printallshows();
		cout << endl;
	}
}


	vector <Show*> Cinema::SearchShow(string usertitle) {
		vector<Show*> result;
		for (int i = 0; i < halls.size(); i++) {
			for (int j = 0; j < halls[i].shows.size(); j++) {
				if (halls[i].shows[j].title == usertitle) {
					result.push_back(&halls[i].shows[j]);

				}

			}
		}
			return result;
	}