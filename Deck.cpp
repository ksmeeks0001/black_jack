#include "Deck.h"
#include <iostream>
#include <cstdlib>
#include <time.h>


Deck::Deck()
{
    srand(time(NULL)); // random seed to time

    //loop through the deck of cards and set suits and denominations
    int index = 0;
    for (string suit: suits) //for each suit in suites array
    {
        for (string denom: denoms) //for each denomination in denoms array
        {
            cards[index].suit = suit;
            cards[index].denom = denom;
            cards[index].set_value();
            index += 1;
        }
    }

    cards_left = 52;
    shuffle();
    shuffle();



}
void Deck::display_cards()
{
    for (Card card: cards)
    {
        cout << card.denom << " of " << card.suit << " value is " << card.value << endl;
    }
}

void Deck::shuffle()
{

 for (int x = 0; x < 52; x++)
 {
     int random_index = (rand() % 52);
     Card temp = cards[random_index];
     cards[random_index] = cards[x];
     cards[x] = temp;
 }
}

Card Deck::deal(bool new_game)
{
    static int index = 0;
    Card deal;

    if (new_game == false)
    {
        deal = cards[index];
        index++;
        return deal;
    }
    else
    {
        index = 0;
        deal = cards[index];
        index++;
        return deal;

    }
}
