#include "coach.h"

#include <iostream>

Coach::Coach()
{
}

void Coach::addCeilingDisplay(Display const& display)
{
    ceiling_displays.push_back(display);

}

void Coach::addSeatDisplay(std::string const& seatId, Display const& display)
{
    seat_displays[seatId] = display;   
}

void Coach::updateCeilingDisplays(std::string const& newText)
{
    for (auto& display : ceiling_displays){
        display.updateText(newText);
    }    
}

void Coach::updateSeatDisplay(std::string const& seatId, std::string const& newText)
{
    for (auto& display : seat_displays){
        if (display.first == seatId){
            display.second.updateText(newText);
            return;
        }
    }
}

void Coach::showCeilingDisplays() const
{
    for (auto& dispaly : ceiling_displays){
        dispaly.show();
    }
}

void Coach::showSeatDisplays() const
{
    for (auto& display : seat_displays){
        display.second.show();
    }
}

void Coach::showAllDisplays() const
{
    showCeilingDisplays();
    showSeatDisplays();
}
