#include <iostream>
#include "Actions.h"

using namespace std;

void handlePlayerTurn
(Card playerHand[], int& playerHandSize, 
    Card computerHand[], int& computerHandSize, 
    Card deck[], int& deckSize, 
    string playerFacesWon[], int& playerFacesWonNumber, bool& playerTurn, string& requestedFace)
{
    cout << "\nYour Turn!\nYour points: " << playerFacesWonNumber << "\nYour hand:\n";
    showHand(playerHand, playerHandSize);

    if (playerHandSize == 0)
    {
        if (deckSize > 0)
        {
            cout << "You have no cards. Drawing a card from the deck..." << endl;
            drawCardDeck(playerHand, playerHandSize, deck, deckSize);
            checkAndRemoveSets(playerHand, playerHandSize, playerFacesWon, playerFacesWonNumber);
        }
        else
        {
            cout << "You have no cards and the deck is empty. Your turn ends." << endl;
        }
    }

    cout << "Ask for a card face: ";
    cin >> requestedFace;

    if (drawCard(computerHand, computerHandSize, playerHand, playerHandSize, requestedFace))
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

            string faceOfDrawnCard = playerHand[playerHandSize - 1].face;
            string faceOfLastCard = playerHand[playerHandSize - 2].face;

            if (faceOfLastCard == requestedFace)
            {
                cout << "You drew a " << faceOfLastCard << ". Your Turn!";
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

void handleComputerTurn
(Card computerHand[], int& computerHandSize,
    Card playerHand[], int& playerHandSize,
    Card deck[], int& deckSize,
    string computerFacesWon[], string playerFacesWon[], int& computerFacesWonNumber, bool& playerTurn)
{
    cout << "\n\nComputer's turn..." << endl;
    cout << "Computer's points: " << computerFacesWonNumber << endl;

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

        if (drawCard(playerHand, playerHandSize, computerHand, computerHandSize, computerRequest))
        {
            cout << "Computer took your card(s)! It goes again!" << endl;
            checkAndRemoveSets(computerHand, computerHandSize, computerFacesWon, computerFacesWonNumber);
        }
        else
        {
            if (deckSize > 0)
            {
                cout << "Computer goes fishing..." << endl;
                drawCardDeck(computerHand, computerHandSize, deck, deckSize);

                string faceOfDrawnCard = computerHand[computerHandSize - 1].face;
                string faceOfLastCard = computerHand[computerHandSize - 2].face;

                if (faceOfLastCard == computerRequest)
                {
                    cout << "Computer drew a " << faceOfLastCard << ". It goes again!" << endl;
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

void handlePlayerTurnSecondStage()
{

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
    while (true) //second stage
    {
        if (playerTurn)
        {
            cout << "second stage";
        }
        else
        {
            cout << "second stage";

        }
    }
}
