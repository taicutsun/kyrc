#include "card.h"
#include <iostream>
#include "card.h"
#include <io.h>
#include <fcntl.h>



using namespace std;
Card::Card() {
	m_suit = CARD_DIAMONDS;
	m_rank = CARD_2;
}
Card::Card(CardRank f_rank, CardSuits f_suit) {
	m_rank = f_rank;
	m_suit = f_suit;
}
void Card::print_card() {
	switch (m_rank) {
	case  CARD_2:cout << 2; break;
	case  CARD_3:cout << 3; break;
	case CARD_4: cout << 4; break;
	case CARD_5: cout << 5; break;
	case CARD_6: cout << 6; break;
	case CARD_7: cout << 7; break;
	case CARD_8: cout << 8; break;
	case CARD_9: cout << 9; break;
	case CARD_10: cout << 10; break;
	case CARD_J: cout << "Ja "; break;
	case CARD_Q: cout << "Qu "; break;
	case CARD_K: cout << "Ki "; break;
	case CARD_A: cout << "A "; break;
	}
	switch (m_suit) {
	case CARD_DIAMONDS:cout << " diamonds, "; break;
	case  CARD_HEARTS: cout << " hearts, "; break;
	case CARD_SPADES: cout << " spades, "; break;
	case  CARD_CLUBS: cout << " clubs, "; break;
	}

}

int Card::get_score() {

	switch (m_rank) {
	case CARD_2: return 2;
	case CARD_3: return 3;
	case CARD_4: return 4;
	case CARD_5: return 5;
	case CARD_6: return 6;
	case CARD_7: return 7;
	case CARD_8: return 8;
	case CARD_9: return 9;
	case CARD_10:
	case CARD_J:
	case CARD_Q:
	case CARD_K: return 10;
	case CARD_A: return 1;
	}
}

Card::CardRank Card::get_rank() {

	return m_rank;
}

Card::CardSuits Card::get_suits() {

	return m_suit;
}
