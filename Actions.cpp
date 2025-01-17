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
* holds functions for gameplay
*
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Actions.h"

using namespace std;

const string faces[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
const string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
const int CARDS_IN_SET = 4;
const int MAX_SETS = 13;

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
    const int numFaces = sizeof(faces) / sizeof(faces[0]);
    Card groupedCards[MAX_CARDS][numFaces];
    int groupSizes[numFaces] = { 0 };

    // Group cards by face
    for (int i = 0; i < handSize; i++)
    {
        for (int j = 0; j < numFaces; j++)
        {
            if (hand[i].face == faces[j])
            {
                groupedCards[groupSizes[j]++][j] = hand[i];
                break;
            }
        }
    }

    // Display grouped cards
    for (int i = 0; i < numFaces; i++)
    {
        if (groupSizes[i] > 0)
        {
            cout << faces[i] << ": ";
            for (int k = 0; k < groupSizes[i]; k++)
            {
                cout << groupedCards[k][i].suit << " ";
            }
            cout << endl;
        }
    }
    cout << endl;
}


//Func that removes all instances of a face if there are 4 in a hand
bool removeSetFaceIfComplete(Card hand[], int& handSize, const string& face, string facesWon[], int& WonFaces)
{
    int count = 0;

    // Count the cards of the specified face
    for (int i = 0; i < handSize; i++)
    {
        if (hand[i].face == face)
        {
            count++;
        }
    }


    // If exactly 4 cards of the face are found, remove them
    if (count == CARDS_IN_SET)
    {
        int newHandSize = 0;

        for (int i = 0; i < handSize; i++)
        {
            if (hand[i].face != face)
            {
                hand[newHandSize++] = hand[i];
            }
        }

        handSize = newHandSize;

        facesWon[WonFaces++] = face;

        cout << "\nA set was won: " << face << endl;
        return true;
    }

    return false;
}

void checkAndRemoveSets(Card hand[], int& handSize, string facesWon[], int& facesWonNumber)
{
    for (const string& face : faces) 
    {
        removeSetFaceIfComplete(hand, handSize, face, facesWon, facesWonNumber);
    }
}

bool checkIfSecondStage(const int handSize, const int& deckSize, const int& facesWon, const int& facesWonEnemy)
{
    return handSize == 0 && deckSize == 0;
}

//Func checks if you have the card for after asking for a card you don't have
bool checkIfHasCard(Card Hand[], int& HandSize, const string& face)
{
    for (int i = 0; i < HandSize; i++)
    {
        if (face == Hand[i].face)
        {
            return true;
        }
    }
    return false;
}

//Func draw requested face/take a card from enemy
bool drawCard(Card fromHand[], int& fromHandSize, Card toHand[], int& toHandSize, const string& face)
{
    Card temp[MAX_CARDS];
    int tempSize = 0;
    bool found = false;

    for (int i = 0; i < fromHandSize; i++)
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

    for (int i = 0; i < tempSize; i++)
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

void drawCardDeck(Card hand[], int& HandSize, Card deck[], int& deckSize)
{
    hand[HandSize++] = deck[--deckSize];
}

//Second phase of the game:

//Func draw a set from a player/take a set from enemy
bool drawSet(string fromPlayerSets[], int& playerSetsSize, string toEnemySets[], int& toEnemySetsSize, const string& face)
{
    string temp[MAX_SETS];
    int tempSize = 0;
    bool found = false;

    for (int i = 0; i < playerSetsSize; i++)
    {
        if (fromPlayerSets[i] == face)
        {
            temp[tempSize++] = fromPlayerSets[i];
            found = true;
        }
        else
        {
            fromPlayerSets[i - tempSize] = fromPlayerSets[i];
        }
    }
    fromPlayerSets -= tempSize;

    for (int i = 0; i < tempSize; i++)
    {
        toEnemySets[toEnemySetsSize++] = temp[i];
    }

    return found;
}