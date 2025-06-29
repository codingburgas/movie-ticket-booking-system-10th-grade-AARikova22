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
    
    if (movies.empty()) {
        cout << "Movie list is empty. Add a movie first.\n";
        return; 
    }
    if (halls.empty()) {
        cout << "Hall list is empty. Add a hall first.\n";
        return; 
    }

    cout << "\n--- Select a movie for the new show ---\n";
    for (int i = 0; i < movies.size(); i++) {
        cout << i + 1 << ". " << movies[i].title << endl;
    }
    cout << "Your choice: ";
    int movie_choice;
    cin >> movie_choice;
    int movieIndex = movie_choice - 1; 

    
    cout << "\n--- Select a hall ---\n";
    for (int i = 0; i < halls.size(); i++) {
        cout << i + 1 << ". Hall " << halls[i].HallNumber << endl;
    }
    cout << "Your choice: ";
    int hall_choice;
    cin >> hall_choice;
    int hallIndex = hall_choice - 1; 

   
    if (movieIndex >= 0 && movieIndex < movies.size() && hallIndex >= 0 && hallIndex < halls.size()) {

        
        cout << "\nType the time for the show (e.g., 19:30): ";
        string newShowTime;
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, newShowTime);

      
        Show newShow;
        newShow.movie = &movies[movieIndex];
        newShow.time = newShowTime;

        Hall& selectedHall = halls[hallIndex];

        
        for (int i = 0; i < selectedHall.silverCount; ++i) {
            newShow.seats.push_back({ "silver", false });
        }
        
        for (int i = 0; i < selectedHall.goldCount; ++i) {
            newShow.seats.push_back({ "gold", false });
        }
        
        for (int i = 0; i < selectedHall.platinumCount; ++i) {
            newShow.seats.push_back({ "platinum", false });
        }

       
        halls[hallIndex].shows.push_back(newShow);

        cout << "\nNew show for '" << newShow.movie->title << "' successfully added!\n";
    }
    else {
        
        cout << "\nError! Invalid movie or hall number.\n";
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

        cout << "Update..." << "1. Movie" << endl << "2. Time" << endl;
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
