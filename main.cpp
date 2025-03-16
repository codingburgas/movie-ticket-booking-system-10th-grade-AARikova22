#include <iostream>
#include <string>
#include "../include/seat.h"
int main() {
    Seat seat1{ "silver", false };
    seat1.printseatinfo();
    seat1.isreserved();
    seat1.printseatinfo();
}