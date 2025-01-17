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
* manages a turn of the computer
*
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Turns.h"


using namespace std;

void handleComputerTurn
(Card computerHand[], int& computerHandSize,
    Card playerHand[], int& playerHandSize,
    Card deck[], int& deckSize,
    string computerFacesWon[], string playerFacesWon[], int& computerFacesWonNumber, bool& playerTurn)
{
    string playerInput;
    cout << "\n\nComputer's turn..." << endl;
    cout << "Computer's faces won: " << computerFacesWonNumber << endl;

    if (computerHandSize == 0)
    {
        if (deckSize > 0)
        {
            cout << "Computer has no cards. It draws a card from the deck..." << endl;
            drawCardDeck(computerHand, computerHandSize, deck, deckSize);
            checkAndRemoveSets(computerHand, computerHandSize, computerFacesWon, computerFacesWonNumber);
        }
        else
        {
            cout << "Computer has no cards and the deck is empty. Computer's turn ends." << endl;
        }
    }

    if (computerHandSize > 0)
    {
        string computerRequest;

        //makes a random face until it picks a face that hasn't been won
        while (true)
        {
            bool found = false;
            computerRequest = faces[rand() % 13];
            for (int i = 0; i < computerFacesWonNumber; i++)
            {
                if (computerFacesWon[i] == computerRequest || playerFacesWon[i] == computerRequest)
                {
                    found = true;
                }
            }
            if (found == false)
            {
                break;
            }
        }

        cout << "Computer asks for: " << computerRequest << endl;

        cout << "Give " << computerRequest << " or should the computer go fish?: ";

        getline(cin, playerInput);

        if (drawCard(playerHand, playerHandSize, computerHand, computerHandSize, computerRequest))
        {
            cout << "\nComputer took your card(s)! It goes again!" << endl;
            checkAndRemoveSets(computerHand, computerHandSize, computerFacesWon, computerFacesWonNumber);
        }
        else
        {
            if (deckSize > 0)
            {
                cout << "\nComputer goes fishing..." << endl;
                drawCardDeck(computerHand, computerHandSize, deck, deckSize);

                string faceOfDrawnCard = computerHand[computerHandSize - 1].face;
                string faceOfLastCard = computerHand[computerHandSize - 2].face;

                if (faceOfDrawnCard == computerRequest)
                {
                    cout << "Computer drew a " << faceOfDrawnCard << ". It goes again!" << endl;
                }
                else
                {
                    cout << "Computer drew a " << faceOfDrawnCard << "." << endl;
                    playerTurn = true;
                }
                checkAndRemoveSets(computerHand, computerHandSize, computerFacesWon, computerFacesWonNumber);
            }
            else
            {
                cout << "The deck is empty. Computer's turn ends." << endl;
                playerTurn = true;
            }
        }
    }
}


void handleComputerTurnSecondStage
(string computerFacesWon[], int& computerFacesWonNumber,
    string playerFacesWon[], int& playerFacesWonNumber,
    bool playerTurn, bool over)
{
    cout << "\nComputer's Turn!\nComputer's faces won: " << computerFacesWonNumber << endl;

    if (computerFacesWonNumber == 0)
    {
        cout << "You Win! Good job!";
        over = true;
    }
    else
    {
        cout << "Ask for a card face: ";
        string computerRequest;

        //makes a random face until it picks a face that hasn't been won by the computer
        while (true)
        {
            bool found = false;
            computerRequest = faces[rand() % 13];
            for (int i = 0; i < computerFacesWonNumber; i++)
            {
                if (computerFacesWon[i] == computerRequest)
                {
                    found = true;
                }
            }
            if (found == false)
            {
                break;
            }
        }

        if (drawSet(playerFacesWon, playerFacesWonNumber, computerFacesWon, computerFacesWonNumber, computerRequest))
        {
            cout << "Computer stole your set! Computer's Turn!" << endl;
        }
        else
        {
            cout << "Go Fish! Your turn!" << endl;
            playerTurn = false;
        }
    }
}