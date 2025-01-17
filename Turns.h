#ifndef TURNS_H
#define TURNS_H

#include "Actions.h"

void handlePlayerTurn
(Card playerHand[], int& playerHandSize, Card computerHand[], int& computerHandSize, Card deck[], int& deckSize,
    std::string playerFacesWon[], int& playerFacesWonNumber, bool& playerTurn, std::string& requestedFace);

void handlePlayerTurnSecondStage
(std::string playerFacesWon[], int& playerFacesWonNumber, std::string computerFacesWon[], int& computerFacesWonNumber,
    bool playerTurn, std::string& requestedFace, bool over);



void handleComputerTurn
(Card computerHand[], int& computerHandSize,
    Card playerHand[], int& playerHandSize,
    Card deck[], int& deckSize,
    std::string computerFacesWon[], std::string playerFacesWon[], int& computerFacesWonNumber, bool& playerTurn);

void handleComputerTurnSecondStage
(std::string computerFacesWon[], int& computerFacesWonNumber,
    std::string playerFacesWon[], int& playerFacesWonNumber,
    bool playerTurn, bool over);

#endif