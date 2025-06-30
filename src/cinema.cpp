#include <iostream>
#include <algorithm>
#include <cctype>
#include "../include/cinema.h"
#include "../include/hall.h"
#include "../include/show.h"

using namespace std;

// Safely reads an integer from input with validation and error handling
int getIntegerInput() {
    int choice;
    cin >> choice;
    while (cin.fail()) {
        cout << "Error. Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> choice;
    }
    return choice;
}


void Cinema::printallshowsInHalls() { // Prints all shows in each cinema hall
    cout << "All halls: " << endl;
    for (int i = 0; i < halls.size(); i++) {
        
        halls[i].printallshows(); 
        cout << endl;
    }
}

// General structure: Searches for shows by title, language, genre, or release date.
// Each function converts input and stored data to lowercase for case-insensitive comparison.
vector<SearchResult> Cinema::SearchShow(string usertitle) {
    vector<SearchResult> result;
    string lower_usertitle = usertitle;
    for (char& c : lower_usertitle) {
        c = tolower(c);
    }

    for (int i = 0; i < halls.size(); i++) {
        for (int j = 0; j < halls[i].shows.size(); j++) {
            if (halls[i].shows[j].movie->title != "_DELETED_") {
                string lower_movie_title = halls[i].shows[j].movie->title;
                for (char& c : lower_movie_title) {
                    c = tolower(c);
                }

                if (lower_movie_title == lower_usertitle) {
                    SearchResult sr;
                    sr.show = &halls[i].shows[j];
                    sr.hallNumber = halls[i].HallNumber;
                    result.push_back(sr);
                }
            }
        }
    }
    return result;
}


vector <SearchResult> Cinema::SearchShowbylanguage(string userlanguage) {
    vector<SearchResult> result;
    string lower_userlanguage = userlanguage;
    for (char& c : lower_userlanguage) {
        c = tolower(c);
    }

    for (int i = 0; i < halls.size(); i++) {
        for (int j = 0; j < halls[i].shows.size(); j++) {
            if (halls[i].shows[j].movie->language != "_DELETED_") {
                string lower_movie_language = halls[i].shows[j].movie->language;
                for (char& c : lower_movie_language) {
                    c = tolower(c);
                }

                if (lower_movie_language == lower_userlanguage) {
                    SearchResult sr;
                    sr.show = &halls[i].shows[j];
                    sr.hallNumber = halls[i].HallNumber;
                    result.push_back(sr);
                }
            }
        }
    }
    return result;
}

vector <SearchResult> Cinema::SearchShowbygenre(string usergenre) {
    vector<SearchResult> result;
    string lower_usergenre = usergenre;
    for (char& c : lower_usergenre) {
        c = tolower(c);
    }

    for (int i = 0; i < halls.size(); i++) {
        for (int j = 0; j < halls[i].shows.size(); j++) {
            if (halls[i].shows[j].movie->genre != "_DELETED_") {
                string lower_movie_genre = halls[i].shows[j].movie->genre;
                for (char& c : lower_movie_genre) {
                    c = tolower(c);
                }

                if (lower_movie_genre == lower_usergenre) {
                    SearchResult sr;
                    sr.show = &halls[i].shows[j];
                    sr.hallNumber = halls[i].HallNumber;
                    result.push_back(sr);
                }
            }
        }
    }
    return result;
}


vector <SearchResult> Cinema::SearchShowbyreleasedate(string userreleasedate) {
    vector<SearchResult> result;
    string lower_userreleasedate = userreleasedate;
    for (char& c : lower_userreleasedate) {
        c = tolower(c);
    }

    for (int i = 0; i < halls.size(); i++) {
        for (int j = 0; j < halls[i].shows.size(); j++) {
            if (halls[i].shows[j].movie->releasedate != "_DELETED_") {
                string lower_movie_releasedate = halls[i].shows[j].movie->releasedate;
                for (char& c : lower_movie_releasedate) {
                    c = tolower(c);
                }

                if (lower_movie_releasedate == lower_userreleasedate) {
                    SearchResult sr;
                    sr.show = &halls[i].shows[j];
                    sr.hallNumber = halls[i].HallNumber;
                    result.push_back(sr);
                }
            }
        }
    }
    return result;
}


// Adds a new movie to the cinema's movie list
void Cinema::addMovie() {
    Movie newMovie;
    cout << "\n--- Adding a new movie ---\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cout << "Enter movie title: ";
    getline(cin, newMovie.title);
    cout << "Enter language: ";
    getline(cin, newMovie.language);
    cout << "Enter genre: ";
    getline(cin, newMovie.genre);
    cout << "Enter release date: ";
    getline(cin, newMovie.releasedate);
    movies.push_back(newMovie);
    cout << "\nSuccess! Movie '" << newMovie.title << "' has been added to the database.\n";
    cout << "\n[NOTIFICATION] A new movie, '" << newMovie.title << "', has been released!" << endl;
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
    int choice = getIntegerInput(); 

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


// Adds a new show to a selected hall for a selected movie
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
    int movieChoice = getIntegerInput(); 

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
    int hallChoice = getIntegerInput(); 
    int hallIndex = hallChoice - 1;

    if (hallIndex >= 0 && hallIndex < halls.size()) {
        string time;
        cout << "\nEnter the show time (e.g., 19:30): ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, time);

        Show newShow;
        newShow.movie = &movies[movieIndex];
        newShow.time = time;
        newShow.seats.clear();

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
        cout << "\nSuccess! The show for '" << movies[movieIndex].title << "' at " << time
            << " has been added. Total seats created: " << newShow.seats.size() << endl;

    }
    else {
        cout << "Error! Invalid hall number.\n";
    }
}

// Deletes a show based on user selection
void Cinema::deleteShow() {
    cout << "\n--- Deleting a show ---\n";
    cout << "Which show do you want to delete? (enter the number)\n";

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
        cout << "There are no shows to delete.\n";
        return;
    }

    cout << "Your choice: ";
    int userChoice = getIntegerInput();

    int findCounter = 1;
    bool showFoundAndDeleted = false;
    for (int i = 0; i < halls.size(); i++) {
        for (int j = 0; j < halls[i].shows.size(); j++) {
            if (halls[i].shows[j].movie->title != "_DELETED_") {
                if (findCounter == userChoice) {
                    halls[i].shows.erase(halls[i].shows.begin() + j);
                    cout << "\nShow successfully deleted.\n";
                    showFoundAndDeleted = true;
                    break;
                }
                findCounter++;
            }
        }
        if (showFoundAndDeleted) { break; }
    }

    if (!showFoundAndDeleted) {
        cout << "Error! A show with that number does not exist.\n";
    }
}

// Updates the time of a selected show
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
    int userChoice = getIntegerInput(); 

    int findCounter = 1;
    bool showFound = false;
    for (int i = 0; i < halls.size(); i++) {
        for (int j = 0; j < halls[i].shows.size(); j++) {
            if (halls[i].shows[j].movie->title != "_DELETED_") {
                if (findCounter == userChoice) {
                    showFound = true;
                    cout << "\nEnter the new time for the show: ";
                    string newTime;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, newTime);
                    halls[i].shows[j].time = newTime;
                    cout << "\nShow time has been updated!\n";
                    break;
                }
                findCounter++;
            }
        }
        if (showFound) { break; }
    }
    if (!showFound) {
        cout << "Error! A show with that number does not exist.\n";
    }
}
