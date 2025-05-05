#include "display.h"

#include <iostream>

Display::Display()
    : text("")
{
}

Display::Display(std::string const& initialText)
    : text { initialText }
{
}

void Display::updateText(std::string const& newText)
{
    text = newText;
}

std::string Display::getText() const
{
    return text;
}

void Display::show() const
{
    // TODO

    // Geben Sie das Ergebnis von `getText()` auf der Konsole aus.
    std::cout << "Display: " << getText() << std::endl;
    // Anmerkung: In einer echten Anwendung würde hier wahrscheinlich
    // eine grafische Benutzeroberfläche oder ein physisches Display
    // angesprochen werden, um den Text anzuzeigen.
    // Wir verwenden einfach std::cout, um den Text auf die Konsole auszugeben.
}
