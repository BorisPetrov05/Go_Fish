/**
*
* Solution to course project # 8
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2024/2025
*
* @author Boris Petrov
* @idnumber 1MI0600528
* @compiler VC
*
* header file for Card struct and some constants
*
*/

#pragma once

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

