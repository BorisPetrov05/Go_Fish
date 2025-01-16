#include <iostream>
#include "Actions.h"

using namespace std;

void handlePlayerTurn
(Card playerHand[], int& playerHandSize, 
    Card computerHand[], int& computerHandSize, 
    Card deck[], int& deckSize, 
    string playerFacesWon[], int& playerFacesWonNumber, bool& playerTurn, string& requestedFace, Card playerLastCard)
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
            if (playerLastCard.face == requestedFace)
            {
                cout << "You drew a " << requestedFace << ". Your Turn!";
            }
            else
            {
                cout << "You drew a " << requestedFace << ". Computer's turn!";
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
    string computerFacesWon[], int& computerFacesWonNumber, bool& playerTurn, Card computerLastCard)
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
        string computerRequest = faces[rand() % 13];
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

                if (computerLastCard.face == computerRequest)
                {
                    cout << "Computer drew a " << computerRequest << ". It goes again!" << endl;
                }
                else
                {
                    cout << "Computer drew a " << computerRequest << "." << endl;
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

    string playerfacesWon[MAX_CARDS];
    int playerFacesWonNumber = 0;

    string computerFacesWon[MAX_CARDS];
    int computerFacesWonNumber = 0;

    Card playerLastCard = playerHand[playerHandSize - 1];
    Card computerLastCard = computerHand[computerHandSize - 1];

    cout << "Welcome to the game \"Go Fish\"!" << endl;

    while (true)
    {
        if (playerTurn)
        {
            handlePlayerTurn(playerHand, playerHandSize, 
                computerHand, computerHandSize, 
                deck, deckSize,
                playerfacesWon, playerFacesWonNumber, playerTurn, requestedFace, playerLastCard);
        }
        else
        {
            handleComputerTurn(computerHand, computerHandSize, 
                playerHand, playerHandSize, 
                deck, deckSize, computerFacesWon, computerFacesWonNumber, playerTurn, computerLastCard);
        }

        if (checkWinner(computerHandSize, deckSize, playerFacesWonNumber, computerFacesWonNumber))
        {
            cout << (playerTurn ? "You won!" : "Computer wins! Better luck next time!") << endl;
            break;
        }
    }
}
