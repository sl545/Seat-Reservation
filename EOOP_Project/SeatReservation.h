#ifndef SEATRESERVATION_H
#define SEATRESERVATION_H

#include <string>

class Reservation {
protected:
    std::string id;
    bool isReserved;

public:
    Reservation(std::string id);
    Reservation();  // Adding a non-parametric constructor 
    bool getIsReserved() const;
    std::string getId() const;
};

class SeatReservation : public Reservation {
private:
    std::string reservedBy;

public:
    SeatReservation();
    SeatReservation(std::string seatID);
    bool reserveSeat(std::string user);
    bool cancelReservation();
    std::string getReservedBy() const;
};

#endif // SEATRESERVATION_H
