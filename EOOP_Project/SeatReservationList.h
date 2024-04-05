#ifndef SEATRESERVATIONLIST_H
#define SEATRESERVATIONLIST_H

#include "SeatReservation.h"

const int MAX_RESERVATIONS = 100;

class SeatReservationList {
private:
    SeatReservation reservations[MAX_RESERVATIONS];
    int numReservations;

public:
    SeatReservationList();
    bool addReservation(std::string seatID, std::string user);
    bool cancelReservation(std::string seatID);
    bool modifyReservation(const std::string& oldSeatID, const std::string& newSeatID);

    SeatReservation* getAllReservations() const;
    int getNumReservations() const;
};

#endif // SEATRESERVATIONLIST_H
