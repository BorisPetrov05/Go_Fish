Welcome to the Go Fish card game implemented in C++. This project simulates the classic children's card game, allowing you to play against a computer opponent.

Game Overview:
Go Fish is a simple card game typically played by 2 to 6 players. The objective is to collect as many sets of four cards of the same rank as possible. Players take turns asking opponents for specific card ranks, attempting to complete their sets. If the opponent doesn't have the requested card, the player "goes fishing" by drawing from the deck.

How to Play:

Setup:
A standard 52-card deck is used.
Playing against a computer, each player is dealt 6 cards.
The remaining cards form the draw pile/deck.

Gameplay:
The first turn is yours.
On your turn:
Ask a specific player for a particular rank: 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A (J-Jack, Q-Queen, K-King, A-Ace).
If the computer has one or more cards of the requested rank, they must give all of them to you.
If the computer doesn't have any, they say "Go Fish," and you draw a card from the draw pile.
If you draw the card you requested, you get another turn.
If you collect all four cards of a rank, you form a set and you gain a point.
After all sets are formed, the game enters the second stage: the player and computer ask each other for sets.

Winning the Game:
Whomever earns all 52 cards from the deck wins.

Project Structure:
main.cpp: Contains the main game loop and handles user interactions.
Actions.h and Actions.cpp: Define the functions for game actions such as shuffling, dealing, and drawing cards.
Card.h: Defines the Card structure used in the game.
Go_Fish.sln, Go_Fish.vcxproj, Go_Fish.vcxproj.filters: Visual Studio solution and project files for building the game.

Getting Started:
A C++ compiler supporting C++11 or later.
Visual Studio (optional, for using the provided solution files).
Building the Project
Running the Project
Input any face: 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A
