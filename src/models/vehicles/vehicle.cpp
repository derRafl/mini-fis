#include "vehicle.h"
#include <iostream>
#include <algorithm> // For std::find

Vehicle::Vehicle()
    : next_stop("")
{
}

void Vehicle::addCoach(Coach const& coach)
{
    coaches.push_back(coach);
    // Initialize reservations for the new coach
    reservations.emplace_back(std::unordered_map<std::string, std::vector<Reservation>>());
}

void Vehicle::addStop(std::string const& stop)
{
    route.push_back(stop);
}

void Vehicle::addReservation(size_t coachIndex, std::string const& seatId, Reservation const& reservation)
{
    // Check if from and to are valid
    bool seen = false;
    for (auto& stop : route) {
        if (reservation.from == stop)
        {
            seen = true;
        }
        if (reservation.to == stop) {
            if (seen)
            {
                reservations[coachIndex][seatId].push_back(reservation);
            } else {
                // Add empty reservation
                reservations[coachIndex][seatId].push_back(Reservation("", ""));
            }
        }
    }
    
}

void Vehicle::showAllDisplays() const
{
    for (const auto& coach : coaches) {
        coach.showAllDisplays();
    }
}

void Vehicle::showAllReservations() const
{
    // TODO
    for (size_t i = 0; i < coaches.size(); ++i) {
        for (const auto& [seatId, reservations] : reservations[i]) {
            std::cout << "Wagen " << i << ", ";
            std::cout << "Platz " << seatId << ": ";
            for (const auto& reservation : reservations) {
                std::cout << reservation.getDisplayText() << ", ";
            }
            std::cout << std::endl;
        }
    }
}

void Vehicle::setCurrentStop(size_t pos)
{
    // TODO
    if (pos < route.size()) {
        next_stop = route[pos];
    } else {
        next_stop = ""; // Set to empty string if position is invalid
    }
    // Update displays for the current stop
}

void Vehicle::arriveAtStop()
{
    // Aktualisiere die Displays für die Ankunft an der Station.
    for (auto& coach : coaches) {
        coach.updateCeilingDisplays(next_stop);
    }

    // Bestimme die Position in der Route und aktualisiere next_stop.
    auto it = std::find(route.begin(), route.end(), next_stop);
    auto current_pos = it - route.begin();
    setCurrentStop(current_pos + 1);

    // Aktualisiere die Reservierungs-Informationen auf den Sitzplatz-Displays.
    updateSeatDisplays();
}

void Vehicle::departFromStop()
{
    // Aktualisiere die Displays für die Abfahrt von der Station.
    for (auto& coach : coaches) {
        coach.updateCeilingDisplays("Nächster Halt: " + next_stop);
    }
}

void Vehicle::updateSeatDisplays()
{
    for (size_t i = 0; i < coaches.size(); ++i) {
        auto& coach = coaches[i];
        for (const auto& [seatId, reservations] : reservations[i]) {
            auto reservation = get_next_reservation(reservations, next_stop, route);
            if (!reservation.isEmpty()) {
                coach.updateSeatDisplay(seatId, reservation.getDisplayText());
            }
        }
    }
}