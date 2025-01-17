#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Turns.h"

using namespace std;

void handlePlayerTurn
(Card playerHand[], int& playerHandSize,
    Card computerHand[], int& computerHandSize,
    Card deck[], int& deckSize,
    string playerFacesWon[], int& playerFacesWonNumber, bool& playerTurn, string& request)
{
    cout << "\nYour Turn!\nYour faces won: " << playerFacesWonNumber << "\nYour hand:\n";
    showHand(playerHand, playerHandSize);

    string faceOfDrawnCard;

    if (playerHandSize == 0)
    {
        if (deckSize > 0)
        {
            cout << "You have no cards. Drawing a card from the deck..." << endl;
            drawCardDeck(playerHand, playerHandSize, deck, deckSize);

            faceOfDrawnCard = playerHand[playerHandSize - 1].face;

            if (faceOfDrawnCard == request)
            {
                cout << "You drew a " << faceOfDrawnCard << ". Your Turn!";
            }
            else
            {
                cout << "You drew a " << faceOfDrawnCard << ". Computer's turn!";
                playerTurn = false;
            }
            checkAndRemoveSets(playerHand, playerHandSize, playerFacesWon, playerFacesWonNumber);
        }
        else
        {
            cout << "You have no cards and the deck is empty. Your turn ends." << endl;
        }
    }

    cout << "What do you want to do? Steal or draw: ";
    getline(cin, request);

    if (request == "draw")
    {
        drawCardDeck(playerHand, playerHandSize, deck, deckSize);
        faceOfDrawnCard = playerHand[playerHandSize - 1].face;

        if (faceOfDrawnCard == request)
        {
            cout << "You drew a " << faceOfDrawnCard << ". Your Turn!";
        }
        else
        {
            cout << "You drew a " << faceOfDrawnCard << ". Computer's turn!";
            playerTurn = false;
        }

        checkAndRemoveSets(playerHand, playerHandSize, playerFacesWon, playerFacesWonNumber);

    }
    else
    {
        cout << "Ask for a card face: ";
        getline(cin, request);

        if (checkIfHasCard(playerHand, playerHandSize, request))
        {
            if (drawCard(computerHand, computerHandSize, playerHand, playerHandSize, request))
            {
                cout << "Computer had the card(s). Your Turn!" << endl;
                checkAndRemoveSets(playerHand, playerHandSize, playerFacesWon, playerFacesWonNumber);
            }
            else
            {
                if (deckSize > 0)
                {
                    cout << "Go Fish! Drawing a card from the deck..." << endl;
                    drawCardDeck(playerHand, playerHandSize, deck, deckSize);

                    faceOfDrawnCard = playerHand[playerHandSize - 1].face;

                    if (faceOfDrawnCard == request)
                    {
                        cout << "You drew a " << faceOfDrawnCard << ". Your Turn!";
                    }
                    else
                    {
                        cout << "You drew a " << faceOfDrawnCard << ". Computer's turn!";
                        playerTurn = false;
                    }
                    checkAndRemoveSets(playerHand, playerHandSize, playerFacesWon, playerFacesWonNumber);
                }
                else
                {
                    cout << "The deck is empty. Your turn ends." << endl;
                    playerTurn = false;
                }
            }
        }
        else
        {
            cout << "You can't ask for a card face you don't have!";
            playerTurn = false;
        }
    }
    
}

void handlePlayerTurnSecondStage
(string playerFacesWon[], int& playerFacesWonNumber,
    string computerFacesWon[], int& computerFacesWonNumber,
    bool playerTurn, string& request, bool over)
{
    cout << "\nYour Turn!\nYour faces won: " << playerFacesWonNumber << endl;

    if (playerFacesWonNumber == 0)
    {
        cout << "You lose! Better luck next time!";
        over = true;
    }
    else
    {
        cout << "Ask for a card face: ";
        getline(cin, request);

        if (drawSet(playerFacesWon, playerFacesWonNumber, computerFacesWon, computerFacesWonNumber, request))
        {
            cout << "Computer has the set! Your Turn!" << endl;
        }
        else
        {
            cout << "Go Fish! Computer's turn!" << endl;
            playerTurn = false;
        }
    }
}