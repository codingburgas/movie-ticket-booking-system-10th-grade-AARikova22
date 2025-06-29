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
    cout << "\n--- Deleting a movie ---\n";

    vector<int> movie_map;
    cout << "Which movie do you want to delete? (enter the number)\n";
    int display_counter = 1;
    for (int i = 0; i < movies.size(); ++i) {
        if (movies[i].title != "_DELETED_") {
            cout << display_counter << ". " << movies[i].title << endl;
            movie_map.push_back(i);
            display_counter++;
        }
    }

    if (movie_map.empty()) {
        cout << "There are no movies to delete.\n";
        return;
    }

    cout << "Your choice: ";
    int choice;
    cin >> choice;

    if (choice > 0 && choice <= movie_map.size()) {
        int indexToDelete = movie_map[choice - 1];

        Movie* movieToDeletePtr = &movies[indexToDelete];
        string title = movieToDeletePtr->title;

        cout << "First, deleting all shows for the movie '" << title << "'...\n";

        for (int i = 0; i < halls.size(); i++) {
            for (int j = halls[i].shows.size() - 1; j >= 0; j--) {
                if (halls[i].shows[j].movie == movieToDeletePtr) {
                    halls[i].shows.erase(halls[i].shows.begin() + j);
                }
            }
        }
        movies[indexToDelete].title = "_DELETED_";
        cout << "\nDone! The movie '" << title << "' and all its shows have been deleted.\n";

    }
    else {
        cout << "Error! Invalid number.\n";
    }
}



void Cinema::addShow() {
    cout << "\n--- Adding a new show ---\n";

    cout << "Which movie is this show for? (enter the number)\n";

    vector<int> movie_map;
    int display_counter = 1;
    for (int i = 0; i < movies.size(); ++i) {
        if (movies[i].title != "_DELETED_") {
            cout << display_counter << ". " << movies[i].title << endl;
            movie_map.push_back(i);
            display_counter++;
        }
    }

    if (movie_map.empty()) {
        cout << "Cannot add a show. The movie database is empty.\n";
        return;
    }

    cout << "Your choice: ";
    int movieChoice;
    cin >> movieChoice;

    if (movieChoice <= 0 || movieChoice > movie_map.size()) {
        cout << "Error! Invalid movie number.\n";
        return;
    }
    int movieIndex = movie_map[movieChoice - 1]; 

    cout << "\nWhich hall will the show be in? (enter the number)\n";
    for (int i = 0; i < halls.size(); ++i) {
        cout << i + 1 << ". Hall " << halls[i].HallNumber << endl;
    }
    cout << "Your choice: ";
    int hallChoice;
    cin >> hallChoice;
    int hallIndex = hallChoice - 1;

    if (hallIndex >= 0 && hallIndex < halls.size()) {
        string time;
        cout << "\nEnter the show time (e.g., 19:30): ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, time);

        Show newShow;
        newShow.movie = &movies[movieIndex];
        newShow.time = time;
        Hall& selectedHall = halls[hallIndex];

        const double silver_price = 10.00;
        const double gold_price = 15.00;
        const double platinum_price = 20.00;

       
        for (int i = 0; i < selectedHall.silverSeatsCount; ++i) {
            newShow.seats.push_back({ "silver", silver_price, false });
        }
        for (int i = 0; i < selectedHall.goldSeatsCount; ++i) {
            newShow.seats.push_back({ "gold", gold_price, false });
        }
        for (int i = 0; i < selectedHall.platinumSeatsCount; ++i) {
            newShow.seats.push_back({ "platinum", platinum_price, false });
        }

        halls[hallIndex].shows.push_back(newShow);
        cout << "\nSuccess! The show for '" << movies[movieIndex].title << "' at " << time << " has been added." << endl;
    }
    else {
        cout << "Error! Invalid hall number.\n";
    }
}

void Cinema::deleteShow() {
   
  
        int showCounter = 1;
        for (int i = 0; i < halls.size(); i++) {
            for (int j = 0; j < halls[i].shows.size(); j++) {
                cout << showCounter << ". Hall " << halls[i].HallNumber << halls[i].shows[j].time
                    << halls[i].shows[j].movie->title << endl;
                showCounter++;
            }
        }
        if (showCounter == 1) {
            cout << "Show list is empty." << endl;
            return;
        }
        cout << "Type the number of show you want to delete" << endl;
        int deleteshowchoice;
        cin >> deleteshowchoice;
        int findCounter = 1;
        
        for (int i = 0; i < halls.size(); i++) {
            for (int j = 0; j < halls[i].shows.size(); j++) {
                if (findCounter == deleteshowchoice) {
                    halls[i].shows.erase(halls[i].shows.begin() + j);
                    cout << "Show deleted";
                    break;
                }
            }
           

            for (int i = 0; i < halls.size(); i++) {
                halls[i].shows.erase(halls[i].shows.begin() + deleteshowchoice);
            }
    
}}

void Cinema::updateShow() {
    cout << "\n--- Updating show information ---\n";
    cout << "Which show do you want to update? (enter the number)\n";

    int showCounter = 1;
    for (int i = 0; i < halls.size(); i++) {
        for (int j = 0; j < halls[i].shows.size(); j++) {
            if (halls[i].shows[j].movie->title != "_DELETED_") {
                cout << showCounter << ". Hall " << halls[i].HallNumber
                    << " | " << halls[i].shows[j].time
                    << " | " << halls[i].shows[j].movie->title << endl;
                showCounter++;
            }
        }
    }

    if (showCounter == 1) {
        cout << "There are no shows to update.\n";
        return;
    }

    cout << "Your choice: ";
    int userChoice;
    cin >> userChoice;

    int findCounter = 1;
    bool showFound = false;
    
    for (int i = 0; i < halls.size(); i++) {
        for (int j = 0; j < halls[i].shows.size(); j++) {
            if (halls[i].shows[j].movie->title != "_DELETED_") {
                if (findCounter == userChoice) {
                    showFound = true;
                    
                    cout << "\nEnter the new time for the show: ";
                    string newTime;
                    cin >> newTime;
                    halls[i].shows[j].time = newTime;
                    cout << "\nShow time has been updated!\n";
                    break;
                }
                findCounter++;
            }
        }
        if (showFound) {
            break;
        }
    }
    if (!showFound) {
        cout << "Error! A show with that number does not exist.\n";
    }
}
