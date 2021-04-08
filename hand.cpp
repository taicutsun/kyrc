#include"deck.h"
#include"card.h"
#include<vector>
#include <iostream>
#include"hand.h"
using namespace std;

void Hand::printHand() {
	int size = m_hand.size();
	for (int i = 0; i < size; i++) {
		m_hand[i].print_card();
	}
}

void Hand::takeOneCard(Deck& fdeck) {
	Card cardTemp = fdeck.pop();
	m_hand.push_back(cardTemp);
	/*printHand(); cout << endl;*/
}


unsigned int Hand::calculateScore() {
	int size = m_hand.size();
	unsigned int score = 0;
	for (int i = 0; i < size; i++) {
		score += m_hand[i].get_score();

		if (m_hand[i].get_rank() == Card::CARD_A && score + 10 <= 21) {
			score += 10;
		}
	}
	return score;
}

Hand::GameStatus Hand::checkGameStatus() {
	int score = calculateScore();
	if (score < 21) { return Hand::GAME_CONTINUE; }
	else
		if (score == 21) { return Hand::WIN_; }
		else if (score > 21) { return Hand::LOOSE_; }

}