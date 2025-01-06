#include <iostream>
#include <string>
#include <cstdlib> //srand, rand
#include <ctime> //time

using namespace std;

struct Card
{
    string face;
    string suit;

    string ToString() const
    {
        return face + " of " + suit;
    }
};

const int MAX_CARDS = 52;
const int START_HAND_SIZE = 6;
const string faces[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
const string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };


void createDeck(Card deck[], int& deckSize)
{
    deckSize = 0;

    for (int i = 0; i < size(faces); ++i) //13 faces
    {
        for (int j = 0; j < size(suits); ++j) //4 suits
        {
            deck[deckSize++] = { faces[i], suits[j] };
        }
    }
}

void shuffleDeck(Card deck[], int deckSize)
{
    srand(static_cast<unsigned>(time(0))); //convert time_t to unsigned int and seed
    for (int i = 0; i < deckSize; i++)
    {
        int randIndex = rand() % deckSize; //random index
        swap(deck[i], deck[randIndex]);
    }
}

void showHand(Card hand[], int handSize)
{
    for (int i = 0; i < handSize; i++)
    {
        cout << hand[i].ToString() << ' '; //temporary
    }
    cout << endl;
}

bool checkWinner(const int handSize, const int deckSize)
{
    return handSize == 0 && deckSize == 0;
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
void dealCards(Card deck[], int &deckSize, Card playerHand[], int& playerHandSize, Card computerHand[], int& computerHandSize)
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

    Card playerLastCard = playerHand[playerHandSize-1];
    Card computerLastCard = computerHand[computerHandSize-1];

    cout << "Welcome to the game \"Go Fish\"!" << endl;

    while (true)
    {
        if (playerTurn) //players turn
        {
            if (playerHandSize == 0)
            {
                if (deckSize > 0)
                {
                    cout << "You have no cards. Drawing a card from the deck..." << endl;
                    drawCardDeck(playerHand, playerHandSize, deck, deckSize);
                }
                else
                {
                    cout << "You has no cards and the deck is empty. Your turn ends." << endl;
                }
            }

            cout << "\nYour Turn!\nYour hand: ";
            showHand(playerHand, playerHandSize);

            cout << "Conputer: "; //test
            showHand(computerHand, computerHandSize);

            cout << "Ask for a card face: ";
            cin >> requestedFace;

            if (drawCard(computerHand, computerHandSize, playerHand, playerHandSize, requestedFace)) //successfully drawn card
            {
                cout << "Computer had the card(s). Your Turn!" << endl;
            }
            else
            {
                if (deckSize > 0)
                {
                    cout << "Go Fish! Drawing a card from the deck..." << endl;
                    drawCardDeck(playerHand, playerHandSize,deck, deckSize);

                    if (playerLastCard.face == requestedFace)
                    {
                        cout << "You drew a " << requestedFace << ". Your Turn!";
                    }
                    else 
                    {
                        string playerrLastCardFace = playerLastCard.face;
                        cout << "You drew a " << playerrLastCardFace << ". Computer's turn!";
                        playerTurn = false;
                    }
                }
                else
                {
                    cout << "The deck is empty. Your turn ends." << endl;
                    playerTurn = false;
                }
            }

            if (checkWinner(computerHandSize, deckSize))
            {
                cout << "You won!" << endl; break;
            }
        }
        else //computers turn
        {
            cout << "\nComputer's turn..." << endl;

            if (computerHandSize == 0)
            {
                if (deckSize > 0)
                {
                    cout << "Computer has no cards. It draws a card from the deck..." << endl;
                    drawCardDeck(computerHand, computerHandSize, deck, deckSize);
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

                if (drawCard(playerHand, playerHandSize, computerHand, computerHandSize, computerRequest)) //draws card from player
                {
                    cout << "Computer took your card(s)! It goes again!" << endl;
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
                            string computerLastCardFace = computerLastCard.face;
                            cout << "Computer drew a " << computerLastCardFace << "." << endl;
                            playerTurn = true;
                        }
                    }
                    else 
                    {
                        cout << "The deck is empty. Computer's turn ends." << endl;
                        playerTurn = true;
                    }
                }
            }

            if (checkWinner(playerHandSize, deckSize)) 
            {
                cout << "Computer wins! Better luck next time!" << endl;
                break;
            }
        }
    }
}

