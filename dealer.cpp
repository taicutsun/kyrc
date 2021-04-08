#include"deck.h"
#include"card.h"
#include<vector>
#include"hand.h"
#include"player.h"
#include <string>
#include"dealer.h"
using namespace std;

void Dealer::playd(Deck& fdeck) {
	//диллер берет карты пока не наберёт 17 или больше
	//пока  счёт меньше 17
	do {
		// берем карту 
		takeOneCard(fdeck);
	} while (calculateScore() < 17);
	printHand();
	cout << "dialer summ = " << calculateScore() << endl; cout << endl;

}