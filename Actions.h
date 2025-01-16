#ifndef ACTIONS_H
#define ACTIONS_H

#include "Card.h"

void createDeck(Card deck[], int& deckSize);

void shuffleDeck(Card deck[], const int& deckSize);

void showHand(Card hand[], const int& handSize);

bool checkIfSecondStage(const int handSize, const int& deckSize, const int& facesWon, const int& facesWonEnemy);

bool drawCard(Card fromHand[], int& fromHandSize, Card toHand[], int& toHandSize, const std::string& face);

void dealCards(Card deck[], int& deckSize, Card playerHand[], int& playerHandSize, Card computerHand[], int& computerHandSize);

void drawCardDeck(Card Hand[], int& HandSize, Card deck[], int& deckSize);

bool removeSetFaceIfComplete(Card hand[], int& handSize, const std::string& face, std::string facesWon[], int& WonFaces);

void checkAndRemoveSets(Card hand[], int& handSize, std::string facesWon[], int& facesWonNumber);

//second stage:

bool drawSet(std::string fromPlayerSets[], int& playerSetsSize, std::string toEnemySets[], int& toEnemySetsSize, const std::string& face);


#endif