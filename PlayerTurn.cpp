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
* manages a turn of the player
*
*/

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
    cout << "\nYour Turn!\nYour faces won: " << playerFacesWonNumber << "\nYour hand:" << endl;
    showHand(playerHand, playerHandSize);

    string faceOfDrawnCard;

    if (playerHandSize == 0)
    {
        if (deckSize > 0)
        {
            cout << "You have no cards. Drawing a card from the deck..." << endl;
            drawCardDeck(playerHand, playerHandSize, deck, deckSize);

            faceOfDrawnCard = playerHand[playerHandSize - 1].face;

            cout << "You drew a " << faceOfDrawnCard << ". Computer's turn!" << endl;
            playerTurn = false;

            checkAndRemoveSets(playerHand, playerHandSize, playerFacesWon, playerFacesWonNumber);
        }
        else
        {
            cout << "You have no cards and the deck is empty. Your turn ends." << endl;
        }
    }

    cout << "What do you want to do? Steal or draw?" << endl << "> ";
    getline(cin, request);

    if (request == "draw")
    {
        drawCardDeck(playerHand, playerHandSize, deck, deckSize);
        faceOfDrawnCard = playerHand[playerHandSize - 1].face;

        if (faceOfDrawnCard == request)
        {
            cout << "You drew a " << faceOfDrawnCard << ". Your Turn!" << endl;
        }
        else
        {
            cout << "You drew a " << faceOfDrawnCard << ". Computer's turn!" << endl;
            playerTurn = false;
        }

        checkAndRemoveSets(playerHand, playerHandSize, playerFacesWon, playerFacesWonNumber);

    }
    else if(request == "steal")
    {
        cout << "Ask for a card face:" << endl << "> ";
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
                        cout << "You drew a " << faceOfDrawnCard << ". Your Turn!" << endl;
                    }
                    else
                    {
                        cout << "You drew a " << faceOfDrawnCard << ". Computer's turn!" << endl;
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
            cout << "You can't ask for a card face you don't have!" << endl;
            playerTurn = false;
        }
    }
    else
    {
        cout << "\n--Invalid command!--" << endl;
    }
    
}



void handlePlayerTurnSecondStage
(string playerFacesWon[], int& playerFacesWonNumber,
    string computerFacesWon[], int& computerFacesWonNumber,
    bool& playerTurn, bool& over)
{
    cout << "\nYour Turn!\nYour faces won: " << playerFacesWonNumber << endl;

    if (playerFacesWonNumber == 13)
    {
        cout << "You win! Good job! " << endl;
        over = true;
    }
    else
    {       
        string request;

        cout << "Ask for a card face:" << endl << "> ";
        if (!(checkIfHasSet(playerFacesWon, computerFacesWonNumber, request)))
        {
            getline(cin, request);

            if (drawSet(computerFacesWon, computerFacesWonNumber, playerFacesWon, playerFacesWonNumber, request))
            {
                cout << "Computer has the set " << request << "! Your Turn!" << endl;
            }
            else
            {
                cout << "Go Fish! Computer's turn!" << endl;
                playerTurn = false;
            }
        }
        else
        {
            getline(cin, request);
            cout << "You already have " << request << endl;
            playerTurn = false;
        }
    }
}