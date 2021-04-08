#include <iostream>
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "dealer.h"
#include "game.h"
using namespace std;


void Game::gaming(unsigned int& playerWin, unsigned int& dealerWin, unsigned int& countDraw, unsigned int& countGame, unsigned int& playerWin2, unsigned int& playerWin3) {
	Deck my_deck;
	my_deck.shuffle();
	//my_deck.print_deck();
	Player player1;
	Player player2;
	Player player3;
	Dealer dealer;

	int playerScore1 = 0; int playerScore2 = 0; int playerScore3 = 0; int dealerScore = 0;

	Hand::GameStatus currentGameStatus1 = Hand::GAME_CONTINUE;
	Hand::GameStatus currentGameStatus2 = Hand::GAME_CONTINUE;
	Hand::GameStatus currentGameStatus3 = Hand::GAME_CONTINUE;
	Hand::GameStatus currentGameStatusd = Hand::GAME_CONTINUE;

	char playing = 'a';
	bool pl1 = true; /*bool pl2 = true; bool dl = true; bool pl3 = true;*/

	//player1.takeOneCard(my_deck);
	//player2.takeOneCard(my_deck);


	while (pl1 == true) {

		cout << "Player1 your turn!" << endl; cout << endl;
		player1.playp1(my_deck);
		currentGameStatus1 = player1.checkGameStatus();

		if (currentGameStatus1 == Hand::WIN_) {
			cout << "Player1 win!" << endl; cout << endl; playerWin++;
			pl1 = false;
		}
		else if (currentGameStatus1 == Hand::LOOSE_) {
			cout << "Player1 lose!" << endl; cout << endl;
			/*pl1 = false;*/

		}

		if (currentGameStatus1 == Hand::GAME_CONTINUE || currentGameStatus1 == Hand::LOOSE_) {

			cout << "Player2 your turn!" << endl; cout << endl;
			player2.playp2(my_deck);
			currentGameStatus2 = player2.checkGameStatus();


			if (currentGameStatus2 == Hand::WIN_) {
				cout << "Player2 win!" << endl; cout << endl; playerWin2++;
				pl1 = false;
			}
			else if (currentGameStatus2 == Hand::LOOSE_) {
				cout << "Player2 lose!" << endl; cout << endl;

			}



			if (currentGameStatus2 == Hand::GAME_CONTINUE || currentGameStatus2 == Hand::LOOSE_) {

				cout << "Player3 your turn!" << endl; cout << endl;
				player3.playp3(my_deck);
				currentGameStatus3 = player3.checkGameStatus();


				if (currentGameStatus3 == Hand::WIN_) {
					cout << "Player3 win!" << endl; cout << endl; playerWin3++;
					pl1 = false;
				}
				else if (currentGameStatus3 == Hand::LOOSE_) {
					cout << "Player3 lose!" << endl; cout << endl;

				}
				if (currentGameStatus3 == Hand::LOOSE_ && currentGameStatus2 == Hand::LOOSE_ && currentGameStatus1 == Hand::LOOSE_) {
					cout << "Dealer win !" << endl; cout << endl; dealerWin++; pl1 = false;
				}

				else if (currentGameStatus3 == Hand::GAME_CONTINUE || currentGameStatus3 == Hand::LOOSE_) {

					cout << "Dealer your turn!" << endl; cout << endl;
					dealer.playd(my_deck);
					currentGameStatusd = dealer.checkGameStatus();

					int playerScore1 = player1.calculateScore(); if (playerScore1 > 21) { playerScore1 = 0; }
					int playerScore2 = player2.calculateScore(); if (playerScore2 > 21) { playerScore2 = 0; }
					int playerScore3 = player3.calculateScore(); if (playerScore3 > 21) { playerScore3 = 0; }
					int dealerScore = dealer.calculateScore(); if (dealerScore > 21) { dealerScore = 0; }


					if (currentGameStatusd == Hand::WIN_) {
						cout << "Dealer wins!" << endl; cout << endl; dealerWin++;
						pl1 = false;
					}

					//kogda vce ravny
					else  if (playerScore1 == playerScore2 && playerScore2 == dealerScore && dealerScore == playerScore3) {
						cout << "Draw!" << endl; cout << endl; countDraw++; pl1 = false;
					}

					//kogda  1 proigraal status
					else  if (playerScore1 == playerScore2 && playerScore2 == playerScore3 && currentGameStatusd == Hand::LOOSE_) {
						cout << "Draw!" << endl; cout << endl; countDraw++; pl1 = false;
					}
					else  if (playerScore1 == playerScore2 && playerScore2 == dealerScore && currentGameStatus3 == Hand::LOOSE_) {
						cout << "Draw!" << endl; cout << endl; countDraw++; pl1 = false;
					}
					else  if (playerScore1 == playerScore3 && playerScore3 == dealerScore && currentGameStatus2 == Hand::LOOSE_) {
						cout << "Draw!" << endl; cout << endl; countDraw++; pl1 = false;
					}
					else  if (playerScore2 == playerScore3 && playerScore3 == dealerScore && currentGameStatus1 == Hand::LOOSE_) {
						cout << "Draw!" << endl; cout << endl; countDraw++; pl1 = false;
					}
					//kogda 1 loose score
					else  if (playerScore1 == playerScore2 && playerScore2 == playerScore3 && dealerScore < playerScore1) {
						cout << "Draw!" << endl; cout << endl; countDraw++; pl1 = false;
					}
					else  if (playerScore1 == playerScore2 && playerScore2 == dealerScore && playerScore3 < playerScore1) {
						cout << "Draw!" << endl; cout << endl; countDraw++; pl1 = false;
					}
					else  if (playerScore1 == playerScore3 && playerScore3 == dealerScore && playerScore2 < playerScore1) {
						cout << "Draw!" << endl; cout << endl; countDraw++; pl1 = false;
					}
					else  if (playerScore2 == playerScore3 && playerScore3 == dealerScore && playerScore1 < playerScore2) {
						cout << "Draw!" << endl; cout << endl; countDraw++; pl1 = false;
					}

					//kogda 2 loose: pl1 status
					else  if (playerScore1 == playerScore2 && currentGameStatus3 == Hand::LOOSE_ && currentGameStatusd == Hand::LOOSE_) {
						cout << "Draw!" << endl; cout << endl; countDraw++; pl1 = false;
					}
					else  if (playerScore1 == playerScore3 && currentGameStatus2 == Hand::LOOSE_ && currentGameStatusd == Hand::LOOSE_) {
						cout << "Draw!" << endl; cout << endl; countDraw++; pl1 = false;
					}
					else  if (playerScore1 == dealerScore && currentGameStatus2 == Hand::LOOSE_ && currentGameStatus3 == Hand::LOOSE_) {
						cout << "Draw!" << endl; cout << endl; countDraw++; pl1 = false;
					}
					//kogda 2 loose :pl1 score 
					else  if (playerScore1 == playerScore2 && playerScore2 > playerScore3 && dealerScore < playerScore1) {
						cout << "Draw!" << endl; cout << endl; countDraw++; pl1 = false;
					}
					else  if (playerScore1 == playerScore3 && playerScore3 > dealerScore && playerScore2 < playerScore1) {
						cout << "Draw!" << endl; cout << endl; countDraw++; pl1 = false;
					}
					else  if (playerScore1 == dealerScore && playerScore1 > playerScore2 && playerScore3 < dealerScore) {
						cout << "Draw!" << endl; cout << endl; countDraw++; pl1 = false;
					}

					//kogda 2 loose :pl2 status
					else  if (playerScore2 == playerScore1 && currentGameStatus3 == Hand::LOOSE_ && currentGameStatusd == Hand::LOOSE_) {
						cout << "Draw!" << endl; cout << endl; countDraw++; pl1 = false;
					}
					else  if (playerScore2 == playerScore3 && currentGameStatus1 == Hand::LOOSE_ && currentGameStatusd == Hand::LOOSE_) {
						cout << "Draw!" << endl; cout << endl; countDraw++; pl1 = false;
					}
					else  if (playerScore2 == dealerScore && currentGameStatus1 == Hand::LOOSE_ && currentGameStatus3 == Hand::LOOSE_) {
						cout << "Draw!" << endl; cout << endl; countDraw++; pl1 = false;
					}
					//kogda 2 loose:pl2 score 
					else  if (playerScore2 == playerScore3 && playerScore3 > dealerScore && playerScore1 < playerScore2) {
						cout << "Draw!" << endl; cout << endl; countDraw++; pl1 = false;
					}
					else  if (playerScore2 == dealerScore && playerScore2 > playerScore1 && playerScore3 < dealerScore) {
						cout << "Draw!" << endl; cout << endl; countDraw++; pl1 = false;
					}

					//kogda 2 loose :pl3 status
					else  if (playerScore3 == playerScore1 && currentGameStatus2 == Hand::LOOSE_ && currentGameStatusd == Hand::LOOSE_) {
						cout << "Draw!" << endl; cout << endl; countDraw++; pl1 = false;
					}
					else  if (playerScore3 == playerScore2 && currentGameStatus1 == Hand::LOOSE_ && currentGameStatusd == Hand::LOOSE_) {
						cout << "Draw!" << endl; cout << endl; countDraw++; pl1 = false;
					}
					else  if (playerScore3 == dealerScore && currentGameStatus1 == Hand::LOOSE_ && currentGameStatus2 == Hand::LOOSE_) {
						cout << "Draw!" << endl; cout << endl; countDraw++; pl1 = false;
					}
					//kogda 2 loose:pl3 score 
					else  if (playerScore3 == dealerScore && playerScore3 > playerScore2 && playerScore1 < dealerScore) {
						cout << "Draw!" << endl; cout << endl; countDraw++; pl1 = false;
					}


					else if (dealerScore > playerScore1 && dealerScore > playerScore2 && dealerScore > playerScore3) {
						cout << "Dealer wins!" << endl; cout << endl; dealerWin++; pl1 = false;
					}
					else if (playerScore1 > dealerScore && playerScore1 > playerScore2 && playerScore1 > playerScore3) {
						cout << "Player1  wins!" << endl; cout << endl; playerWin++; pl1 = false;
					}

					else if (playerScore2 > dealerScore && playerScore2 > playerScore1 && playerScore2 > playerScore3) {
						cout << "Player2  wins!" << endl; cout << endl; playerWin2++; pl1 = false;
					}
					else if (playerScore3 > dealerScore && playerScore3 > playerScore1 && playerScore3 > playerScore2) {
						cout << "Player3  wins!" << endl; cout << endl; playerWin3++; pl1 = false;
					}

					else if (currentGameStatusd == Hand::LOOSE_) {
						cout << "Dealer lose!" << endl; cout << endl;
						pl1 = false;
					}

					else if (currentGameStatus2 == Hand::LOOSE_ && currentGameStatusd == Hand::LOOSE_ && currentGameStatus3 == Hand::LOOSE_) {
						cout << "Player1  wins!" << endl; cout << endl; playerWin++; pl1 = false;
					}

					else if (currentGameStatus1 == Hand::LOOSE_ && currentGameStatusd == Hand::LOOSE_ && currentGameStatus3 == Hand::LOOSE_) {
						cout << "Player2  wins!" << endl; cout << endl; playerWin2++; pl1 = false;
					}
					else if (currentGameStatus1 == Hand::LOOSE_ && currentGameStatusd == Hand::LOOSE_ && currentGameStatus2 == Hand::LOOSE_) {
						cout << "Player3  wins!" << endl; cout << endl; playerWin3++; pl1 = false;
					}



				}
			}





		}


		////
	}

	countGame++;

}