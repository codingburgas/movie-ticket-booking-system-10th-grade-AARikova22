#include <iostream>
#include <algorithm>
#include <cctype>
#include "../include/cinema.h"
#include "../include/hall.h"

using namespace std;

void Cinema::printallshowsInHalls() {
    cout << "All halls: " << endl;
    for (int i = 0; i < halls.size(); i++) {
        cout << halls[i].HallNumber << ":" << endl;
        halls[i].printallshows();
        cout << endl;
    }
}

vector<SearchResult> Cinema::SearchShow(string usertitle) {
    vector<SearchResult> result;

    string lower_usertitle = usertitle;
    for (int i = 0; i < usertitle.size(); i++) {
        lower_usertitle[i] = tolower(usertitle[i]);
    }

    for (int i = 0; i < halls.size(); i++) {
        for (int j = 0; j < halls[i].shows.size(); j++) {
            string lower_movie_title = halls[i].shows[j].movie->title;
            for (int k = 0; k < halls[i].shows[j].movie->title.size(); k++) {
                lower_movie_title[k] = tolower(halls[i].shows[j].movie->title[k]);
            }

            if (lower_movie_title == lower_usertitle) {
                SearchResult sr;
                sr.show = &halls[i].shows[j];
                sr.hallNumber = halls[i].HallNumber;
                result.push_back(sr);
            }
        }
    }
    return result;
}