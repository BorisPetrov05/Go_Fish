#ifndef CARD_H
#define CARD_H

#include <string>

struct Card
{
    std::string face;
    std::string suit;

    std::string ToString() const
    {
        return face + " of " + suit;
    }
};


const int MAX_CARDS = 52;
const int START_HAND_SIZE = 6;
extern const std::string faces[];
extern const std::string suits[];

#endif