#pragma once
#include "cinema.h"

void adminMenu(Cinema& cinema);
void userMenu(Cinema& cinema);
void printTicket(const Cinema& cinema, const SearchResult& searchResult, int seatNumber);