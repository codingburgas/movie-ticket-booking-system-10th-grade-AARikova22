
#include <iostream>
#include <string>
#include "../include/show.h"

using namespace std;

// Prints basic movie information associated with the show
void Show::printMovieInfo() {
    std::cout << "Title: " << movie->title << std::endl
        << "Time: " << time << std::endl;
}

// Prints details about all seats in this show
void Show::printSeatsInfo() {
    std::cout << "Seats:" << std::endl;
    for (int i = 0; i < seats.size(); i++) {
        std::cout << "Seat number: " << i + 1 << std::endl;
        seats[i].printseatinfo();
        std::cout << std::endl;
    }
}


// Attempts to reserve a seat by its number (0-based index)
// Returns true if reservation is successful; false otherwise
bool Show::seatReservation(int number) {
    if ((number >= 0) && (number < seats.size())) {
        return seats[number].isreserved();
    }
    else {
        return false;
    }
}