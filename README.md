# 🎣 Go Fish Card Game

Welcome to the **Go Fish** card game implemented in C++! This project brings the classic children's card game to life, allowing you to play against a computer opponent. 🃏

---

## 🌟 Game Overview
**Go Fish** is a simple yet entertaining card game typically played by 2 to 6 players. In this version, you'll challenge a computer opponent in a battle of wits and luck. The objective? **Collect as many sets of four cards of the same rank as possible.** Players take turns asking for specific card ranks to complete their sets. If your opponent doesn't have the card you're looking for, it's time to "Go Fish!"

---

## 🎮 How to Play

### 🃏 Setup
- A standard 52-card deck is used.
- Each player (you and the computer) is dealt **6 cards**.
- The remaining cards form the **draw pile (deck)**.

### 🔄 Gameplay
The first turn is yours. On your turn:
1. **Ask for a specific rank:**
   - Choose from: `2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A` (J = Jack, Q = Queen, K = King, A = Ace).
   - Use commands like `steal` or `draw` to interact.
2. **Computer's Response:**
   - If the computer has the requested card(s), it gives all of them to you.
   - If not, it says "Go Fish," and you draw a card from the deck.
   - If you draw the card you requested, you earn another turn!
3. **Forming Sets:**
   - If you collect all four cards of a rank, you form a **set** and score a point.

### 🏆 Winning the Game
The game ends when all 52 cards have been used to form sets. The winner is the player with the most sets collected. May the best fisher win! 🎉

---

## 📂 Project Structure

- **`main.cpp`**: The main game loop and user interaction handler.
- **`Actions.h` & `Actions.cpp`**: Functions for actions like shuffling, dealing, and drawing cards.
- **`Card.h`**: Defines the `Card` structure for the game.
- **`Go_Fish.sln`, `Go_Fish.vcxproj`, `Go_Fish.vcxproj.filters`**: Visual Studio solution and project files for building the game.

---

## 🚀 Getting Started

### Prerequisites
- A C++ compiler supporting **C++11** or later.
- [Visual Studio](https://visualstudio.microsoft.com/) (optional, for using the provided solution files).

### Building the Project
1. Clone or download the project repository.
2. Open the solution file (`Go_Fish.sln`) in Visual Studio, or compile the files using your preferred C++ compiler.
3. Build the project to create the executable.

### Running the Project
Run the compiled executable and follow the prompts. Input:
- A **command**: `steal` or `draw`.
- A **rank**: `2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A`.

---

## 🎉 Enjoy Playing!
Dive into the fun of Go Fish and show your skills in collecting sets! 🐟 Good luck!
