#include <iostream>
#include "SeatReservation.h"
#include "SeatReservationList.h"

int main() {
    SeatReservationList reservationList;
    int choice = 0;

    while (true) {
        std::cout << "\nSeat Reservation System\n";
        std::cout << "1. Add Reservation\n";
        std::cout << "2. Cancel Reservation\n";
        std::cout << "3. Modify Reservation\n";
        std::cout << "4. Display All Reservations\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string seatID, user;
            std::cout << "Enter Seat ID: ";
            std::cin >> seatID;
            std::cout << "Enter User Name: ";
            std::cin >> user;
            if (reservationList.addReservation(seatID, user)) {
                std::cout << "Reservation added successfully.\n";
            } else {
                std::cout << "Failed to add reservation.\n";
            }
        } else if (choice == 2) {
            std::string seatID;
            std::cout << "Enter Seat ID to cancel: ";
            std::cin >> seatID;
            if (reservationList.cancelReservation(seatID)) {
                std::cout << "Reservation cancelled successfully.\n";
            } else {
                std::cout << "Failed to cancel reservation.\n";
            }
        } else if (choice == 3) {
            std::string oldSeatID, newSeatID;
            std::cout << "Enter current Seat ID to modify: ";
            std::cin >> oldSeatID;
            std::cout << "Enter new Seat ID: ";
            std::cin >> newSeatID;
            if (reservationList.modifyReservation(oldSeatID, newSeatID)) {
                std::cout << "Reservation modified successfully.\n";
            } else {
                std::cout << "Failed to modify reservation.\n";
            }
        } else if (choice == 4) {
            for (int i = 0; i < reservationList.getNumReservations(); ++i) {
                SeatReservation res = reservationList.getAllReservations()[i];
                std::cout << "Seat ID: " << res.getId() << ", Reserved By: " << res.getReservedBy()
                          << ", Is Reserved: " << (res.getIsReserved() ? "Yes" : "No") << std::endl;
            }
        } else if (choice == 5) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
