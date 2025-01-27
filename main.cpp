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
* entry point of the program, manages turns and gameplay
*
*/

#include <iostream>
#include "Actions.h"
#include "Turns.h"

using namespace std;

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
    dealCards(deck, deckSize, playerHand, playerHandSize, computerHand, computerHandSize);

    bool playerTurn = true;
    string request;

    string playerFacesWon[MAX_CARDS];
    int playerFacesWonNumber = 0;

    string computerFacesWon[MAX_CARDS];
    int computerFacesWonNumber = 0;

    cout << "Welcome to the game \"Go Fish\"!" << endl;

    while (true)
    {
        if (playerTurn)
        {
            handlePlayerTurn(playerHand, playerHandSize, 
                computerHand, computerHandSize, 
                deck, deckSize,
                playerFacesWon, playerFacesWonNumber, playerTurn, request);
        }
        else
        {
            handleComputerTurn(computerHand, computerHandSize, 
                playerHand, playerHandSize, 
                deck, deckSize, computerFacesWon, playerFacesWon, computerFacesWonNumber, playerTurn);
        }

        if (checkIfSecondStage(deckSize, playerFacesWonNumber, computerFacesWonNumber))
        {
            cout << ("\nEntering the second stage of the game!") << endl;
            break;
        }
    }

    bool over = false;
    playerTurn = true;
    while (true) //second stage
    {
        if (over)
        {
            cout << "Game Over!";
            break;
        }
        else if (playerTurn)
        {
            handlePlayerTurnSecondStage(playerFacesWon, playerFacesWonNumber,
                computerFacesWon, computerFacesWonNumber,
                playerTurn, over);
        }
        else
        {
            handleComputerTurnSecondStage(computerFacesWon, computerFacesWonNumber,
                playerFacesWon, playerFacesWonNumber,
                playerTurn, over);
        }
    }
}
