#include <iostream>
#include "Hand.h"
Hand::Hand() //Default
{
    value = 0;
}

Hand::Hand(Card card1, Card card2) // black jack constructor takes initial 2 cards
{
    recieving_index=2;
    cards[0] = card1;
    cards[1] = card2;
    value = 0;
    bust = false;
    set_value();
}

void Hand::set_value() // resets the value of the hand based on current cards being held
{
    bool reset = false; //if an ace was reset and set_value needs called again
    value = 0;
    for(int i=0; i<recieving_index+1; i++)
        value += cards[i].value;
    if (value > 21)
    {
	for (int i=0; i<recieving_index+1; i++)
	{
		if( cards[i].value == 11)
		{	cards[i].value =1;
			reset = true;
			break;
		}
	}
	if (reset == true)
		set_value();
	else
        bust = true;
    }
}

void Hand::receive_card(Card new_card)
{
    cards[recieving_index] = new_card;
    recieving_index++;
    set_value();
}

void Hand::show_cards() // display cards in Hand
{
    for (int i=0; i<recieving_index+1; i++)
    {
        if (cards[i].value > 0)
           cout << cards[i].denom << " of " << cards[i].suit << endl;
    }
}

