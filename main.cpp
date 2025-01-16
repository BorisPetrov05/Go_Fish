#include <iostream>
#include "Actions.h"

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

    Card playerLastCard = playerHand[playerHandSize - 1];
    Card computerLastCard = computerHand[computerHandSize - 1];

    string playerfacesWon[MAX_CARDS];
    int playerFacesWonNumber = 0;

    string computerFacesWon[MAX_CARDS];
    int computerFacesWonNumber = 0;


    cout << "Welcome to the game \"Go Fish\"!" << endl;

    while (true)
    {
        //players turn
        if (playerTurn) 
        {
            cout << "\nYour Turn!\nYour hand:\n";
            showHand(playerHand, playerHandSize);

            cout << "Conputer: "; //test
            showHand(computerHand, computerHandSize);

            //actions if player has no cards in hand
            if (playerHandSize == 0) 
            {
                if (deckSize > 0)
                {
                    cout << "You have no cards. Drawing a card from the deck..." << endl;
                    drawCardDeck(playerHand, playerHandSize, deck, deckSize);
                    if (removeSetFaceIfComplete(playerHand, playerHandSize, playerLastCard.face, playerfacesWon, playerFacesWonNumber))
                    {
                        cout << "You completed a set of " << requestedFace << "s!" << endl;
                    }
                }
                else
                {
                    cout << "You has no cards and the deck is empty. Your turn ends." << endl;
                    //cout << "=================================================================";
                }
            }

            //turn begins
            cout << "Ask for a card face: ";
            cin >> requestedFace;

            //successfully drawn card from computer
            if (drawCard(computerHand, computerHandSize, playerHand, playerHandSize, requestedFace)) 
            {
                cout << "Computer had the card(s). Your Turn!" << endl;
                if (removeSetFaceIfComplete(playerHand, playerHandSize, playerLastCard.face, playerfacesWon, playerFacesWonNumber))
                {
                    cout << "You completed a set of " << requestedFace << "s!" << endl;
                }
            }
            //unsuccessfully drawn card from computer
            else
            {
                if (deckSize > 0)
                {
                    cout << "Go Fish! Drawing a card from the deck..." << endl;
                    drawCardDeck(playerHand, playerHandSize, deck, deckSize);

                    if (playerLastCard.face == requestedFace) //player draws the requested card from deck
                    {
                        cout << "You drew a " << requestedFace << ". Your Turn!";
                        //cout << "=================================================================";
                    }
                    else //player draws a card from deck and ends turn
                    {
                        string playerrLastCardFace = playerLastCard.face;
                        cout << "You drew a " << playerrLastCardFace << ". Computer's turn!";
                        //cout << "=================================================================";
                        playerTurn = false;
                    }
                    if (removeSetFaceIfComplete(playerHand, playerHandSize, playerLastCard.face, playerfacesWon, playerFacesWonNumber))
                    {
                        cout << "You completed a set of " << requestedFace << "s!" << endl;
                    }
                }
                else
                {
                    cout << "The deck is empty. Your turn ends." << endl;
                    //cout << "=================================================================";
                    playerTurn = false;
                }
            }

            if (checkWinner(computerHandSize, deckSize, playerFacesWonNumber, computerFacesWonNumber))
            {
                cout << "You won!" << endl; break;
            }
        }
        //computers turn
        else
        {
            cout << "\n\nComputer's turn..." << endl;

            //actions if computer has no cards in hand
            if (computerHandSize == 0)
            {
                if (deckSize > 0)
                {
                    cout << "Computer has no cards. It draws a card from the deck..." << endl;
                    drawCardDeck(computerHand, computerHandSize, deck, deckSize);
                    if (removeSetFaceIfComplete(computerHand, computerHandSize, computerLastCard.face, computerFacesWon, computerFacesWonNumber))
                    {
                        cout << "Computer completed a set of " << requestedFace << "s!" << endl;
                    }
                }
                else
                {
                    cout << "Computer has no cards and the deck is empty. Computer's turn ends." << endl;
                    //cout << "=================================================================";
                }
            }
            
            //turn begins
            if (computerHandSize > 0)
            {
                string computerRequest = faces[rand() % 13];
                cout << "Computer asks for: " << computerRequest << endl;

                //successfully drawn card from player
                if (drawCard(playerHand, playerHandSize, computerHand, computerHandSize, computerRequest)) //draws card from player
                {
                    cout << "Computer took your card(s)! It goes again!" << endl;
                    if (removeSetFaceIfComplete(computerHand, computerHandSize, computerLastCard.face, computerFacesWon, computerFacesWonNumber))
                    {
                        cout << "Computer completed a set of " << requestedFace << "s!" << endl;
                    }
                }
                //unsuccessfully drawn card from player
                else
                {
                    if (deckSize > 0)
                    {
                        cout << "Computer goes fishing..." << endl;
                        drawCardDeck(computerHand, computerHandSize, deck, deckSize);

                        if (computerLastCard.face == computerRequest) //computer draws the requested card from deck
                        {
                            cout << "Computer drew a " << computerRequest << ". It goes again!" << endl;
                        }
                        else //computer draws card from deck and ends turn
                        {
                            string computerLastCardFace = computerLastCard.face;
                            cout << "Computer drew a " << computerLastCardFace << "." << endl;
                            //cout << "=================================================================";
                            playerTurn = true;
                        }
                        if (removeSetFaceIfComplete(computerHand, computerHandSize, computerLastCard.face, computerFacesWon, computerFacesWonNumber))
                        {
                            cout << "Computer completed a set of " << requestedFace << "s!" << endl;
                        }
                    }
                    else
                    {
                        cout << "The deck is empty. Computer's turn ends." << endl;
                        //cout << "=================================================================";
                        playerTurn = true;
                    }
                }
            }

            if (checkWinner(playerHandSize, deckSize, computerFacesWonNumber, playerFacesWonNumber))
            {
                cout << "Computer wins! Better luck next time!" << endl;
                break;
            }
        }
    }
}