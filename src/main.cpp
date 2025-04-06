#include <iostream>
#include <string>
#include <iostream>
#include <string>
#include "../include/seat.h"
#include "../include/show.h"

int main() {
    Show runlolarun;
    runlolarun.title = "Run Lola Run";
    runlolarun.time = "15:30";

    runlolarun.seats = {
        {"silver", false},
        {"gold", false},
        {"platinum", false}
    };

    runlolarun.printMovieInfo();

    std::cout << "\nBefore reservation:\n";
    runlolarun.printSeatsInfo();

    std::cout << "\nTrying to reserve seat 3:\n";
    runlolarun.seatReservation(2); 

    std::cout << "\nAfter reservation:\n";
    runlolarun.printSeatsInfo();

    return 0;
}