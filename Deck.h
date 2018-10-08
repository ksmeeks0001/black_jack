#ifndef DECK_H
#define DECK_H
#include <string>
#include <Card.h>

using namespace std;

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


    private:
        //lists of possible card types of initialization
        string suits[4] = {"Spades", "Clubs", "Diamonds", "Hearts"};
        string denoms[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
};

#endif // DECK_H
