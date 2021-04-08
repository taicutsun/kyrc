#pragma once
#include  <fstream>
#include <iostream>
class Card
{

public:
	enum CardSuits {
		CARD_DIAMONDS,//áóáíű
		CARD_HEARTS,//÷ĺđâč
		CARD_SPADES,//ďčęč
		CARD_CLUBS,//ęđĺńňč
		MAX_SUITS//ęîíĺö ďĺđĺ÷čńëĺíč˙
	};
	enum CardRank {
		CARD_2,//0
		CARD_3,//1
		CARD_4,//2
		CARD_5,//3
		CARD_6,
		CARD_7,
		CARD_8,
		CARD_9,
		CARD_10,
		CARD_J,//JACK - âŕëĺň,10
		CARD_Q,//QUEEN - äŕěŕ,11
		CARD_K,//KING - ęîđîëü,12
		CARD_A,//ACE - ňóç,13
		MAX_RANK//ęîíĺö ďĺđĺ÷čńëĺíč˙
	};
	Card();
	Card(CardRank, CardSuits);
	void print_card();
	int get_score();
	CardRank get_rank();
	CardSuits get_suits();
private:
	CardRank m_rank;
	CardSuits m_suit;

};
