#include <iostream>
#include <algorithm>
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
    std::transform(lower_usertitle.begin(), lower_usertitle.end(), lower_usertitle.begin(),
        [](unsigned char c) { return std::tolower(c); });

    for (int i = 0; i < halls.size(); i++) {
        for (int j = 0; j < halls[i].shows.size(); j++) {
            string lower_movie_title = halls[i].shows[j].movie->title;
            std::transform(lower_movie_title.begin(), lower_movie_title.end(), lower_movie_title.begin(),
                [](unsigned char c) { return std::tolower(c); });

            if (lower_movie_title.find(lower_usertitle) != string::npos) {
                SearchResult sr;
                sr.show = &halls[i].shows[j];
                sr.hallNumber = halls[i].HallNumber;
                result.push_back(sr);
            }
        }
    }
    return result;
}