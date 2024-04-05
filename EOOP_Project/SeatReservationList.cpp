#include "SeatReservationList.h"

SeatReservationList::SeatReservationList() : numReservations(0) {}

bool SeatReservationList::addReservation(std::string seatID, std::string user) {
    if (numReservations >= MAX_RESERVATIONS) {
        return false; // has reaching the maximum number and cannot reserve 
    }

    for (int i = 0; i < numReservations; ++i) {
        if (reservations[i].getId() == seatID) {
            return false; // the seat is already reserved 
        }
    }

    reservations[numReservations++] = SeatReservation(seatID);
    return reservations[numReservations - 1].reserveSeat(user);
}

bool SeatReservationList::cancelReservation(std::string seatID) {
    for (int i = 0; i < numReservations; ++i) {
        if (reservations[i].getId() == seatID) {
            return reservations[i].cancelReservation();
        }
    }
    return false; // No corresponding seat reservations found
}

bool SeatReservationList::modifyReservation(const std::string& oldSeatID, const std::string& newSeatID) {
    // to check the old seat is reserved or not
    for (int i = 0; i < numReservations; ++i) {
        if (reservations[i].getId() == oldSeatID) {
            // to check the new seat is avaiable 
            for (int j = 0; j < numReservations; ++j) {
                if (reservations[j].getId() == newSeatID) {
                    return false; // the new seat is reserved 
                }
            }

            // cancel the old reservation 
            reservations[i].cancelReservation();

            // adding new reservation 
            reservations[i] = SeatReservation(newSeatID);
            return reservations[i].reserveSeat(reservations[i].getReservedBy());
        }
    }
    return false; // cannot find the old reservation 
}

SeatReservation* SeatReservationList::getAllReservations() const {
    return const_cast<SeatReservation*>(reservations);
}

int SeatReservationList::getNumReservations() const {
    return numReservations;
}
