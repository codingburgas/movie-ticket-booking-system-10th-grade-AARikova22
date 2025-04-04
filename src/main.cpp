#include <iostream>
#include <string>
#include "../include/seat.h"
#include "../include/show.h"
#include "../src/seat.cpp"
#include "../src/show.cpp"
int main() {
	show runlolarun;
	runlolarun.title = " Run Lola Run";
	runlolarun.time = " 15:30";
	runlolarun.Seats { "silver", false }, { "gold", false }, { "platinum", false };
	runlolarun.printMovieInfo();
	runlolarun.printSeatsInfo();
	runlolarun.seatresetvation(2);
	runlolarun.printSeatsInfo();
}