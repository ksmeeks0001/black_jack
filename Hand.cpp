#include "Hand.h"
#include <iostream>

Hand::Hand() //Default
{
    value = 0;
}

Hand::Hand(Card card1, Card card2) // black jack constructor takes initial 2 cards
{
    cards[0] = card1;
    cards[1] = card2;
    value = 0;
    bust = false;
    set_value();
}

void Hand::set_value() // resets the value of the hand based on current cards being held
{
    value = 0;
    for(Card card:cards)
        value += card.value;
    if (value > 21)
        bust = true;

}

void Hand::receive_card(Card new_card)
{
    cards[recieving_index] = new_card;
    recieving_index++;
    set_value();
}

void Hand::show_cards() // display cards in Hand
{
    for (Card card: cards)
    {
        if (card.value > 0)
           cout << card.denom << " of " << card.suit << endl;
    }
}

