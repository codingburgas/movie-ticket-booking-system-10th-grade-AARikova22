#include <iostream>
#include <vector>
#include <string>
#include <limits> 
#include "../include/cinema.h" 
using namespace std;

int main() {

    Movie movienowyouseeme = { "Now You See Me", "English", "Thriller", "2013" };

    Show nowyouseeme = { &movienowyouseeme, "20:00", {{"silver", false}, {"gold", false },{"platinum", false}} };


    Movie moviecoraline = { "Coraline", "Bulgarian", "Horror", "2009" };

    Show coraline = { &moviecoraline, "18:00",  {{"silver", false}, {"gold", false },{"platinum", false}} };

    Movie moviethebookofgenry = { "The Book of Henry", "Bulgarian", "Drama", "2017" };

    Show thebookofgenry = { &moviethebookofgenry, "12:00",  {{"silver", false}, {"gold", false },{"platinum", false}} };



    Movie movierunlolarun = { "Run Lola Run", "English", "Thriller", "1998" };

    Show runlolarun = { &movierunlolarun, "15:30", { {"silver", false},
          {"gold", false},
          {"platinum", false} } };

    Movie  moviewhatwedointheshadows = { "What We Do In The Shadows", "English", "Comedy", "2014" };
    Show whatwedointheshadows = { &moviewhatwedointheshadows,"17:30", {
        {"silver", false},
        {"gold", false},
        {"platinum", false}
    } };

    Movie  movielabyrinth = { "Labyrinth", "Bulgarian", "Fantasy", "1986" };
    Show labyrinth = { &movielabyrinth,"19:30", {
        {"silver", false},
        {"gold", false},
        {"platinum", false}
    } };


    Hall hall1;
    hall1.HallNumber = 1;
    hall1.shows = { runlolarun,nowyouseeme };

    Hall hall2;
    hall2.HallNumber = 2;
    hall2.shows = { whatwedointheshadows, thebookofgenry };

    Hall hall3;
    hall3.HallNumber = 3;
    hall3.shows = { labyrinth, coraline };

    Cinema GrandMallCinema;
    GrandMallCinema.name = "Grand Mall Cinema";
    GrandMallCinema.town = "Varna";
    GrandMallCinema.halls = {
        hall1, hall2, hall3
    };

    
    //GrandMallCinema.printallshowsInHalls();
    int usersearchchoice;
    cout << "Search by..." << endl << "1. Title" << endl << "2. Language" << endl << "3. Genre" << endl << "4. Realese date" << endl;
    cin >> usersearchchoice;

    if (usersearchchoice == 1) {
        cout << "Search..." << endl;
        string usermovie;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, usermovie);

        vector<SearchResult> results = GrandMallCinema.SearchShowbytitle(usermovie);
        if (results.empty()) {
            cout << "Not found." << endl;
        }
        else {
            cout << "\nFound shows:" << endl;
            for (int i = 0; i < results.size(); i++) {
                results[i].show->printMovieInfo();

            }



        }
    }

    else if (usersearchchoice == 2) {
        cout << "Search...";
        string userlanguage;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, userlanguage);

        vector<SearchResult> result = GrandMallCinema.SearchShowbylanguage(userlanguage);
        if (result.empty()) {
            cout << "Not found." << endl;
        }

        else {
            cout << "\nFound shows:" << endl;
            for (int i = 0; i < result.size(); i++) {
                result[i].show->printMovieInfo();

                cout << endl;
            }
        }

    }


    else if (usersearchchoice == 3) {

        cout << "Search...";
        string usergenre;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, usergenre);

        vector<SearchResult> result = GrandMallCinema.SearchShowbygenre(usergenre);
        if (result.empty()) {
            cout << "Not found." << endl;
        }

        else {
            cout << "\nFound shows:" << endl;
            for (int i = 0; i < result.size(); i++) {
                result[i].show->printMovieInfo();

                cout << endl;
            }
        }

    }

    else if (usersearchchoice == 4) {


        cout << "Search...";
        string userreleasedate;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, userreleasedate);

        vector<SearchResult> result = GrandMallCinema.SearchShowbyreleasedate(userreleasedate);
        if (result.empty()) {
            cout << "Not found." << endl;
        }

        else {
            cout << "\nFound shows:" << endl;
            for (int i = 0; i < result.size(); i++) {
                result[i].show->printMovieInfo();

                cout << endl;
            }
        }
    }

    else {
        cout << "Choose another search method" << endl;
    }

}
  
       









       


