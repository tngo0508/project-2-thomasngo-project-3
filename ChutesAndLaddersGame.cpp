//
//  ChutesAndLaddersGame.cpp
//

#include <iostream>
#include <string>

#include "ChutesAndLaddersGame.hpp"
#include "GameBoard.hpp"
#include "Player.hpp"

using namespace std;

// TODO: implement the constructor with all your team members
// constructor with the default value of a minimum players
ChutesAndLaddersGame::ChutesAndLaddersGame(int nPlayers) : winner("no winner") {
   // TODO: implement this function properly
   //throw std::logic_error("not implemented yet");
	Player player1("Thomas");
	Player player2("William");
	players.enqueue(player1);
	players.enqueue(player2);
}

// TODO: implement the destructor
// destructor - dequeue players from the queue
ChutesAndLaddersGame::~ChutesAndLaddersGame() {
   // TODO: implement this function properly
   //throw std::logic_error("not implemented yet");
	for (int i = 0; i < players.size(); i++)
	{
		players.dequeue();
	}
}

// TO DO: implement this function properly
// reset the game - rebuild the list of players
//        (i.e., the list should be the same as in the constructor).
//        Place all players at the figurative square zero
void ChutesAndLaddersGame::resetGame() {
   // TODO: implement this function properly
   //throw std::logic_error("not implemented yet");
	Player temp = players.front();
	temp.setPostion(0);
	players.dequeue();
	players.enqueue(temp);
	temp = players.front();
	temp.setPostion(0);
	players.dequeue();
	players.enqueue(temp);
	winner = "no name";
}

// TO DO: implement this function properly
// Play the chutes and ladders until a player reaches the winning square 100
//    - Each player takes turn to roll the die and moves to the new square by invoking rollDieAndMove.
//         If the new square is outside of the board, the player stays put
//    - Player's new position is checked against the game board's checkChutesLadders
//    - checkChutesLadders returns a different square if player lands on a chute or a ladder
//    - Player's position is then set to the new position as indicated by checkChutesLadders
//          If player lands on a chute or a ladder, player slides down or climbs up
//    - If player lands on the winning square 100, game is over
//    - playGame returns after congratulating and printing the winner's name
void ChutesAndLaddersGame::playGame() {
   // TODO: implement this function properly
   //throw std::logic_error("not implemented yet");
	
	bool found = false;
	int newPosition = 0;
	Player player1, player2;
	while (!found)
	{
		player1 = players.front();
		players.dequeue();
		newPosition = gameBoard.checkChutesLadders(player1.rollDieAndMove());
		player1.setPostion(newPosition);
		if (player1.getPostion() == WINNING_POSITION)
		{
			winner = player1.getName();
			found = true;
		}
		players.enqueue(player1);
		
		player2 = players.front();
		players.dequeue();
		newPosition = gameBoard.checkChutesLadders(player2.rollDieAndMove());
		player2.setPostion(newPosition);
		if (player2.getPostion() == WINNING_POSITION)
		{
			winner = player2.getName();
			found = true;
		}
		players.enqueue(player2);
	}
	cout << "Congratulation! Player " << winner << " win the game.\n";
}

