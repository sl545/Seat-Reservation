#include "SeatReservation.h"

Reservation::Reservation(std::string id) : id(id), isReserved(false) {}

SeatReservation::SeatReservation() : Reservation(""), reservedBy("") {
    //You can leave it blank or add the appropriate initialisation logic.
}


bool Reservation::getIsReserved() const {
    return isReserved;
}

std::string Reservation::getId() const {
    return id;
}

SeatReservation::SeatReservation(std::string seatID) : Reservation(seatID), reservedBy("") {}

bool SeatReservation::reserveSeat(std::string user) {
    if (!isReserved) {
        isReserved = true;
        reservedBy = user;
        return true;
    }
    return false; //  the seated is reserved already 
}

bool SeatReservation::cancelReservation() {
    if (isReserved) {
        isReserved = false;
        reservedBy = "";
        return true;
    }
    return false; //  the seat is not reserved yet 
}

std::string SeatReservation::getReservedBy() const {
    return reservedBy;
}
