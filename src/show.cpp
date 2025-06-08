
#include <iostream>
#include "../include/show.h"


void Show::printMovieInfo() {
    std::cout << "Title: " << movie->title << std::endl
        << "Time: " << time << std::endl;
}

void Show::printSeatsInfo() {
    std::cout << "Seats:" << std::endl;
    for (int i = 0; i < seats.size(); i++) {
        std::cout << "Seat number: " << i + 1 << std::endl;
        seats[i].printseatinfo();
        std::cout << std::endl;
    }
}

bool Show::seatReservation(int number) {
    if ((number >= 0) && (number < seats.size())) {
        return seats[number].isreserved();
    }
    else {
        return false;
    }
}