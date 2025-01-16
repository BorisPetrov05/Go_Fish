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
    string requestedFace;

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
                playerFacesWon, playerFacesWonNumber, playerTurn, requestedFace);
        }
        else
        {
            handleComputerTurn(computerHand, computerHandSize, 
                playerHand, playerHandSize, 
                deck, deckSize, computerFacesWon, playerFacesWon, computerFacesWonNumber, playerTurn);
        }

        if (checkIfSecondStage(computerHandSize, deckSize, playerFacesWonNumber, computerFacesWonNumber))
        {
            cout << ("\nEntering the second stage of the game!\n") << endl;
            break;
        }
    }

    bool over = false;
    bool winner = false;
    while (true) //second stage
    {
        if (playerTurn)
        {
            handlePlayerTurnSecondStage(playerFacesWon, playerFacesWonNumber,
                computerFacesWon, computerFacesWonNumber,
                playerTurn, requestedFace, over);
        }
        else
        {
            handleComputerTurnSecondStage(computerFacesWon, computerFacesWonNumber,
                playerFacesWon, playerFacesWonNumber,
                playerTurn, over);
        }
        if (over)
        {
            break;
        }
    }
}
