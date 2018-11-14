#include <cstdlib>
#include <iostream>
#include <time.h>
#include "Deck.h"
#include "Card.h"
Deck::Deck()
{ 

    srand(time(NULL)); // random seed to time
    suits[0] =  "Hearts";
    suits[1] =  "Diamonds";
    suits[2] =  "Spades";
    suits[3] =  "Clubs";
    denoms[0] = "A";
    denoms[1]=	"2";
    denoms[2]= "3";
    denoms[3] = "4";
    denoms[4]= "5";
    denoms[5]= "6";
    denoms[6]="7";
    denoms[7]= "8";
    denoms[8]="9";
    denoms[9]= "10";
    denoms[10]="J";
    denoms[11]= "Q";
    denoms[12] = "K";
    //loop through the deck of cards and set suits and denominations
    int index = 0;
    for (int i=0; i<4; i++) //for each suit in suites array
    {
        for (int j=0; j<13;j++) //for each denomination in denoms array
        {
            cards[index].suit = suits[i];
            cards[index].denom = denoms[j];
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
    for (int i=0; i<52;i++)
    {
        cout << cards[i].denom << " of " << cards[i].suit << " value is " <<
	 cards[i].value << endl;
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
