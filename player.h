#pragma once
#include"deck.h"
#include"card.h"
#include<vector>
#include"hand.h"


class Player :public Hand {
public:
	void playp1(Deck&);
	void playp2(Deck&);
	void playp3(Deck&);
};
