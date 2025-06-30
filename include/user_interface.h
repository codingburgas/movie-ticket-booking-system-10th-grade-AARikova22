#pragma once
#include "cinema.h"

void adminMenu(Cinema& cinema);
void printTicket(const Cinema& cinema, const SearchResult& searchResult, int seatNumber);
void searchMenu(Cinema& cinema);
void processBooking(Cinema& cinema, SearchResult& selectedResult);