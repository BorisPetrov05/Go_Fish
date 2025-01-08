#ifndef ACTIONS_H
#define ACTIONS_H

#include "Card.h"

void createDeck(Card deck[], int& deckSize);
void shuffleDeck(Card deck[], int deckSize);
void showHand(Card hand[], int handSize);
bool checkWinner(const int handSize, const int deckSize);
bool drawCard(Card fromHand[], int& fromHandSize, Card toHand[], int& toHandSize, const std::string& face);
void dealCards(Card deck[], int& deckSize, Card playerHand[], int& playerHandSize, Card computerHand[], int& computerHandSize);
void drawCardDeck(Card Hand[], int& HandSize, Card deck[], int& deckSize);

#endif