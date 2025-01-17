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
* header file for ComputerTurn.cpp and PlayerTurn.cpp
*
*/

#pragma once

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
