#pragma once
#include "card.h"
#include <vector>
#include  <fstream>
#include <iostream>
class Deck {
private:
	const int deck_size = 52;
	std::vector<Card> m_deck;
	void swap(Card&, Card&);
public:
	Deck();
	void shuffle();//ďĺđĺňŕńîâŕňü ęîëîäó
	Card pop();//âç˙ňü âĺđőíţţ ęŕđňó
	void print_deck();//ďĺ÷ŕňü ęîëîäó

};

