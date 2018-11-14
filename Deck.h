
#include <string>
#include "Card.h"


class Deck
{
    public:
        //card objects held by the deck
        Card cards[52];

        //counter for cards left to be used in the deck
        int cards_left;


        //constructor
        Deck();

        //shuffle the order of the cards
        void shuffle();

        //deals a card to the hand
        Card deal(bool new_game = false);

        //display all the cards in the deck in order (used to test the shuffle)
        void display_cards();


       	 //lists of possible card types of initialization
	string denoms[13];
		
	string suits[4];
}; // DECK
