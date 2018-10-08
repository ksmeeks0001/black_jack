#ifndef HAND_H
#define HAND_H
#include <Card.h>

using namespace std;

class Hand
{
    public:

        int value; // Value of all cards in hands added together
        Card cards[8]; // array of cards in the hand
        bool bust;

        int recieving_index = 2;


        Hand(); // Default constructor
        Hand(Card card1, Card card2); //Constructor takes first 2 cards

        void show_cards();
        void set_value(); // resets the value of the hand based on current cards being held

        void receive_card(Card);
};

#endif // HAND_H
