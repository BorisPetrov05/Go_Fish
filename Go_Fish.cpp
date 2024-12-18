#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> //srand, rand
#include <ctime> //time
#include <algorithm>

using namespace std;

struct Card
{
    string face;
    string suit;

    string ToString() const
    {
        return face + " of " + suit;
    }
};

const int MAX_CARDS = 52;

//Creating the deck
void createDeck(Card deck[], int& deckSize)
{
    string faces[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
    string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    deckSize = 0;

    for (int i = 0; i < size(faces); ++i) //13 faces
    {
        for (int j = 0; j < size(suits); ++j) //4 suits
        {
            deck[deckSize++] = { faces[i], suits[j] };
        }
    }
}

int main()
{

}

