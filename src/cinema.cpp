#include <iostream>
#include <algorithm>
#include <cctype>
#include "../include/cinema.h"
#include "../include/hall.h"
#include "../include/show.h"

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

void Cinema::addMovie() {
    
    Movie newMovie;

    cout << "Enter movie information" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Title:" << endl;
    getline(cin, newMovie.title);

    cout << "Genre:" << endl;
    getline(cin, newMovie.genre);

    cout << "Language:" << endl;
    getline(cin, newMovie.language);

    cout << "Release date:" << endl;
    getline(cin, newMovie.releasedate);

    movies.push_back(newMovie);

    cout << "New movie successfully added!" << endl;

}

void Cinema::deleteMovie() {
    if (movies.empty() == true) {
        cout << "Movie list is empty." << endl;

    }
    else {
        for (int i = 0; i < movies.size(); i++) {
            cout << i+1 << ". " << movies[i].title << endl;
        }
        cout << "Type the number of movie you want to delete" << endl;
        int deletemoviechoice;
        cin >> deletemoviechoice;
        Movie* movieToDelete = &movies[deletemoviechoice-1]; 
        for (int i = 0; i < halls.size(); i++) {
            for (int j = halls[i].shows.size(); j >= 0; j--) {
                if (movieToDelete == halls[i].shows[j].movie){
                   
                    halls[i].shows.erase(halls[i].shows.begin() + j);
                }
            }
        }
        movies.erase(movies.begin() + deletemoviechoice);
    }
}


void Cinema::addShow(){

    if (movies.empty() == true) {
        cout << "Movie list is empty." << endl;

    }
    else {
        for (int i = 0; i < movies.size(); i++) {
            cout << i + 1 << ". " << movies[i].title << endl;

            cout << "Type the number of movie you want to select." << endl;
            int addshow_moviechoice
        }
    cout << "Add a movie:" << endl;
    getline(cin, NewShow.movie);
    cout << "Time:" << endl;
    getline(cin, NewShow.time);
    for (int i = seats.size(); i > seats.size() / 2; --i) {
        Seat seat;
        seat.seattype = "silver";
        seat.isReserved = false;
        NewShow.seats.push_back(seat);
    }
    for (int i = seats.size() / 2; i > seats.size() / 4; --i) {
        Seat seat;
        seat.seattype = "gold";
        seat.isReserved = false;
        NewShow.seats.push_back(seat);
    }
    for (int i = seats.size() / 4; i >= 1; --i) {
        Seat seat;
        seat.seattype = "platinum";
        seat.isReserved = false;
        NewShow.seats.push_back(seat);
    }
    shows.push_back(NewShow);
    cout << "New show sucessfully added!" << endl;
}

