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
* header file for Actions.cpp
*
*/

#pragma once


#include "Card.h"

void createDeck(Card deck[], int& deckSize);

void shuffleDeck(Card deck[], const int& deckSize);

void showHand(Card hand[], const int& handSize);

bool checkIfSecondStage(const int& deckSize, const int& facesWon, const int& facesWonEnemy);

bool drawCard(Card fromHand[], int& fromHandSize, Card toHand[], int& toHandSize, const std::string& face);

void dealCards(Card deck[], int& deckSize, Card playerHand[], int& playerHandSize, Card computerHand[], int& computerHandSize);

void drawCardDeck(Card hand[], int& HandSize, Card deck[], int& deckSize);

bool removeSetFaceIfComplete(Card hand[], int& handSize, const std::string& face, std::string facesWon[], int& WonFaces);

void checkAndRemoveSets(Card hand[], int& handSize, std::string facesWon[], int& facesWonNumber);

bool checkIfHasCard(Card Hand[], int& HandSize, const std::string& face);

//second stage:

bool drawSet(std::string fromPlayerSets[], int& playerSetsSize, std::string toPlayerSets[], int& toPlayerSetsSize, const std::string& face);

bool checkIfHasSet(std::string playerFacesWon[], int& computerFacesWonNumber, std::string& request);

bool checkIfHasSetComp(std::string computerFacesWon[], int& playerFacesWonNumber, std::string& request);

void chooseRandFromPlayerHand(std::string& computerRequest, Card computerHand[], int& computerHandSize,
	std::string computerFacesWon[], std::string playerFacesWon[], int& computerFacesWonNumber);


