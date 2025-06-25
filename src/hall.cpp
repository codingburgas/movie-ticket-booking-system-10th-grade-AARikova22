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



void Hall::deleteShow() {
	if (shows.empty() == true) {
		cout << "Show list is empty." << endl;

	}
	else {
		
		for (int i = 0; i < shows.size(); i++) {
			cout << i + 1 << ". " << shows[i].movie->title << endl;
		}
		cout << "Type the number of show you want to delete" << endl;
		 int deleteshowchoice;
		cin >> deleteshowchoice;
		
		shows.erase(deleteshowchoice);

	}
}

void Hall::updateShow() {
	if (shows.empty() == true) {
		cout << "Show list is empty." << endl;

	}
	else {
		for (int i = 0; i < shows.size(); i++) {
			cout << i + 1 << ". " << shows[i].movie->title << endl;
		}

		cout << "Type the number of show you want to delete" << endl;
		int uptadeshowindex;
		cin >> uptadeshowindex;

		cout << "Update..." << "1. Movie" << endl << "2. Time" << endl ;
		int updateshowchoice;
		cin >> updateshowchoice;

		if (updateshowchoice == 1) {
			if (movies.empty() == true) {
				cout << "Movie list is empty." << endl;

			}
			else {
				for (int i = 0; i < movies.size(); i++) {
					cout << i + 1 << ". " << movies[i].title << endl;
				}
				cout << "Type the number of movie you want to add" << endl;
				int updatemovieindex;
				cin >> updatemovieindex;
				shows[uptadeshowindex].movie = &movies[updatemovieindex];
				cout << "Movie successfully updated!" << endl;
		}
		

		

	}
		else if (updateshowchoice == 2) {
			cout << "Enter new time." << endl;
			string NewTime;
			getline(cin, NewTime);
			shows[uptadeshowindex].time = NewTime;
			cout << "Show time successfully updated!" << endl;

		}
		else {
			cout << "Try again.";

		}
}