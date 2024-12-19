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
const int START_HAND_SIZE = 6;


//Func Creating the deck
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

//Func Shuffling the deck
void shuffleDeck(Card deck[], int deckSize)
{
    srand(static_cast<unsigned>(time(0))); //convert time_t to unsigned int
    for (int i = 0; i < deckSize; i++)
    {
        int randIndex = rand() % deckSize; //random index
        swap(deck[i], deck[randIndex]);
    }
}

//Func Shows the hand
void showHand(Card hand[], int handSize)
{
    for (int i = 0; i < handSize; i++)
    {
        cout << hand[i].ToString() << ",  ";
    }
    cout << endl;
}

//Func Checks if a player wins
bool checkWinner(int handSize)
{
    return handSize == 0;
}

//Func draw requested face
//to be fixed
bool drawCard(Card fromHand[], int& fromHandSize, Card toHand[], int& toHandSize, string& face)
{
    for (int i = 0; i < fromHandSize; i++)
    {
        if (fromHand[i].face == face)
        {
            toHand[toHandSize++] = fromHand[i];

            for (int j = i; j < fromHandSize-1; j++)
            {
                fromHand[j] = fromHand[j + 1];
            }
            fromHandSize--;
            return true;
        }
    }
    return false;
}

//to be added
//Func deal cards to players, 6 cards
bool dealCards()
{
    return true;
}

int main()
{
    Card deck[MAX_CARDS];
    int deckSize;

    Card playerHand[MAX_CARDS];
    int playerHandSize;

    Card computerHand[MAX_CARDS];
    int computerHandSize;

    createDeck(deck, deckSize);
    shuffleDeck(deck, deckSize);
    //dealCards();

    bool playerTurn = true;

    while (true)
    {
        if (checkWinner(playerHandSize))
        {
            cout << "You lose!" << endl;
            break;
        }
        else if (checkWinner(computerHandSize))
        {
            cout << "You win!" << endl;
            break;
        }
    }
}

