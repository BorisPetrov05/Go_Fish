#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> //srand, rand
#include <ctime> //time
#include <algorithm>

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

void createDeck(Card deck[], int& deckSize)
{
    string faces[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
    string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
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
    srand(static_cast<unsigned>(time(0))); //convert time_t to unsigned int
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
        cout << hand[i].ToString() << ",  ";
    }
    cout << endl;
}

bool checkWinner(const int handSize, const int deckSize)
{
    return handSize == 0 && deckSize == 0;;
}

//Func draw requested face/take a card from enemy
//to be fixed
bool drawCard(Card fromHand[], int& fromHandSize, Card toHand[], int& toHandSize, const string& face) 
{
    bool found = false;
    for (int i = 0; i < fromHandSize; i++) 
    {
        if (fromHand[i].face == face) 
        {
            toHand[toHandSize++] = fromHand[i];
            
            for (int j = i; j < fromHandSize - 1; j++) 
            {
                fromHand[j] = fromHand[j + 1];
            }
            fromHandSize--;
            i--;
            found = true;
        }
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

void drawCardDeck(Card playerHand[], int& playerHandSize, Card deck[], int& deckSize)
{
    playerHand[playerHandSize++] = deck[--deckSize];
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

    while (true)
    {
        if (playerTurn) //players turn
        {
            cout << "\nYour Turn!\nYour hand: ";
            showHand(playerHand, playerHandSize);
            cout << "Conputer: ";
            showHand(computerHand, computerHandSize);

            cout << "Ask for a card face: ";
            cin >> requestedFace;

            if (drawCard(computerHand, computerHandSize, playerHand, playerHandSize, requestedFace))
            {
                cout << "Computer had the card(s). Your Turn!" << endl;
            }
            else
            {
                if (deckSize > 0)
                {
                    cout << "Go Fish! Drawing a card from the deck..." << endl;
                    drawCardDeck(playerHand, playerHandSize,deck, deckSize);
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

            if (computerHandSize > 0) 
            {
                string computerRequest = computerHand[rand() % computerHandSize].face;
                cout << "Computer asks for: " << computerRequest << endl;

                if (drawCard(playerHand, playerHandSize, computerHand, computerHandSize, computerRequest)) 
                {
                    cout << "Computer took your card(s)! It goes again!" << endl;
                }
                else 
                {
                    if (deckSize > 0) 
                    {
                        cout << "Computer goes fishing..." << endl;
                        computerHand[computerHandSize++] = deck[--deckSize];
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

