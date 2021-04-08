#pragma once

#include"deck.h"
#include"card.h"
#include<vector>
#include"hand.h"
class Dealer :public Hand {
public:
	void playd(Deck&);
};