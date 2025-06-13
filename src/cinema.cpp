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

vector<SearchResult> Cinema::SearchShowbytitle(string usertitle) {
    vector<SearchResult> results;

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
                results.push_back(sr);
            }
        }
    }
    return results;
}



vector <SearchResult> Cinema::SearchShowbylanguage(string userlanguage) {
    vector<SearchResult> results;
    string lower_userlanguage = userlanguage;
    for (int i = 0; i < userlanguage.size(); i++) {
        lower_userlanguage[i] = tolower(userlanguage[i]);
    }
    for (int i = 0; i < halls.size(); i++) {
        for (int j = 0; j < halls[i].shows.size(); j++) {
            string lower_movie_language = halls[i].shows[j].movie->language;
            for (int k = 0; k < halls[i].shows[j].movie->language.size(); k++) {
                lower_movie_language[k] = tolower(halls[i].shows[j].movie->language[k]);
            }

            if (lower_movie_language == lower_userlanguage) {
                SearchResult sr;
                sr.show = &halls[i].shows[j];
                sr.hallNumber = halls[i].HallNumber;
                results.push_back(sr);
            }
        }
    }
    return results;
}

vector <SearchResult> Cinema::SearchShowbygenre(string usergenre) {
    vector<SearchResult> results;
    string lower_usergenre = usergenre;
    for (int i = 0; i < usergenre.size(); i++) {
        lower_usergenre[i] = tolower(usergenre[i]);
    }
    for (int i = 0; i < halls.size(); i++) {
        for (int j = 0; j < halls[i].shows.size(); j++) {
            string lower_movie_genre = halls[i].shows[j].movie->genre;
            for (int k = 0; k < halls[i].shows[j].movie->genre.size(); k++) {
                lower_movie_genre[k] = tolower(halls[i].shows[j].movie->genre[k]);
            }

            if (lower_movie_genre == lower_usergenre) {
                SearchResult sr;
                sr.show = &halls[i].shows[j];
                sr.hallNumber = halls[i].HallNumber;
                results.push_back(sr);
            }
        }
    }
    return results;
}


vector <SearchResult> Cinema::SearchShowbyreleasedate(string userreleasedate) {
    vector<SearchResult> results;
    string lower_userreleasedate = userreleasedate;
    for (int i = 0; i < userreleasedate.size(); i++) {
        lower_userreleasedate[i] = tolower(userreleasedate[i]);
    }
    for (int i = 0; i < halls.size(); i++) {
        for (int j = 0; j < halls[i].shows.size(); j++) {
            string lower_movie_releasedate = halls[i].shows[j].movie->releasedate;
            for (int k = 0; k < halls[i].shows[j].movie->releasedate.size(); k++) {
                lower_movie_releasedate[k] = tolower(halls[i].shows[j].movie->releasedate[k]);
            }

            if (lower_movie_releasedate == lower_userreleasedate) {
                SearchResult sr;
                sr.show = &halls[i].shows[j];
                sr.hallNumber = halls[i].HallNumber;
                results.push_back(sr);
            }
        }
    }
    return results;
}