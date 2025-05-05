#include "reservation.h"

Reservation::Reservation(std::string const& from, std::string const& to)
    : from(from)
    , to(to)
{
}

bool Reservation::isEmpty() const
{
   if (from.empty() && to.empty()){
        return true;
   }
    
    return false;

    // return from.empty() && to.empty(); 
}

std::string Reservation::getDisplayText() const
{
    if (!isEmpty()){
        return from + " - " + to;
    }

    return "No reservation";
}
