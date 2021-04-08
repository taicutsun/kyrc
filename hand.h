#pragma once
#include"deck.h"
#include"card.h"
#include<vector>

class Hand {
private:

protected:
	std::vector<Card> m_hand;
public:

	enum GameStatus {
		GAME_CONTINUE,
		WIN_,
		LOOSE_,
		MAX_STATUS,
		GAME_SKIP
	};
	//Hand();
	void takeOneCard(Deck&);
	void printHand();
	unsigned int calculateScore();
	GameStatus checkGameStatus();

};
