#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Actions.h"

using namespace std;

const string faces[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
const string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

void createDeck(Card deck[], int& deckSize)
{
    deckSize = 0;

    for (int i = 0; i < size(faces); ++i)//13 faces
    {
        for (int j = 0; j < size(suits); ++j)//4 suits
        {
            deck[deckSize++] = { faces[i], suits[j] };
        }
    }
}

void shuffleDeck(Card deck[], const int& deckSize)
{
    srand(static_cast<unsigned>(time(0))); //convert time_t to unsigned int and seed
    for (int i = 0; i < deckSize; i++)
    {
        int randIndex = rand() % deckSize; //random index
        swap(deck[i], deck[randIndex]);
    }
}

void showHand(Card hand[], const int& handSize)
{
    for (int i = 0; i < handSize; i++)
    {
        cout << hand[i].ToString() << ' '; //temporary
    }
    cout << endl;
}

//Func that removes all instances of a face if there are 4 in a hand
bool removeSetFaceIfComplete(Card hand[], int& handSize, const string& face, string facesWon[],int& WonFaces)
{
    int counter = 0;
    Card newHand[MAX_CARDS];
    int newHandSize = 0;

    for (int i = 0; i < handSize; i++)
    {
        if (hand[i].face == face)
        {
            counter++;
        }
    }
    
    if (counter == 4)
    {
        for (int i = 0; i < handSize; i++)
        {
            if (hand[i].face != face)
            {
                newHand[newHandSize++] = hand[i];
            }
        }

        handSize = newHandSize;

        for (int i = 0; i < handSize; i++)
        {
            hand[i] = newHand[i];
        }

        facesWon[WonFaces++] = face;
        return true;
    }
    return false;
    
}

bool checkWinner(const int handSize, const int& deckSize, const int& facesWon, const int& facesWonEnemy)
{
    if (handSize == 0 && deckSize == 0)
    {
        return facesWon > facesWonEnemy;
    }
    return 0;
}

//Func draw requested face/take a card from enemy
bool drawCard(Card fromHand[], int& fromHandSize, Card toHand[], int& toHandSize, const string& face)
{
    Card temp[MAX_CARDS];
    int tempSize = 0;
    bool found = false;

    for (int i = 0; i < fromHandSize; ++i)
    {
        if (fromHand[i].face == face)
        {
            temp[tempSize++] = fromHand[i];
            found = true;
        }
        else
        {
            fromHand[i - tempSize] = fromHand[i];
        }
    }

    fromHandSize -= tempSize;

    for (int i = 0; i < tempSize; ++i)
    {
        toHand[toHandSize++] = temp[i];
    }

    return found;
}

//Func deal cards to players, 6 cards
void dealCards(Card deck[], int& deckSize, Card playerHand[], int& playerHandSize, Card computerHand[], int& computerHandSize)
{
    playerHandSize = 0;
    computerHandSize = 0;

    for (int i = 0; i < START_HAND_SIZE; i++)
    {
        playerHand[playerHandSize++] = deck[--deckSize];
        computerHand[computerHandSize++] = deck[--deckSize];
    }
}

void drawCardDeck(Card Hand[], int& HandSize, Card deck[], int& deckSize)
{
    Hand[HandSize++] = deck[--deckSize];
}