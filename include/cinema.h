#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "hall.h"
#include "movie.h"
using namespace std;

class SearchResult {
public:
	Show* show;
	int hallNumber;
};

class Cinema {
public:
	string name;
	string town;
	vector <Hall> halls;
	void printallshowsInHalls();
	vector <SearchResult> SearchShow(string usertitle);
	vector <SearchResult> SearchShowbylanguage(string userlanguage);
	vector <SearchResult> SearchShowbygenre(string usergenre);
	vector <SearchResult> SearchShowbyreleasedate(string userreleasedate);
	vector <Movie> movies;
	void addMovie();
	void deleteMovie();
	void addShow();
	void deleteShow();
	void updateShow();
	void printAllShowsWithDetails();

};

