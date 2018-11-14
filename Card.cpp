#include <iostream>
#include <sstream>
#include "Card.h"
Card::Card(string s , string d)
{
    suit = s;
    denom = d;
    set_value();
    //constructor
}
Card::Card()
{
    suit = "Suit";
    denom = "D";
    value = 0;
}

void Card::set_value()
{
    if (denom == "A")
        {
            value = 11;
        }
    else if ((denom == "J") || (denom == "Q") || (denom == "K"))
    {
        value = 10;
    }
    else if ((denom=="2")||(denom=="3")||(denom=="4")||(denom=="5")||(denom=="6")||
             (denom=="7")||(denom=="8")||(denom=="9")||(denom=="10"))
    {
        stringstream denom_to_value(denom);
        denom_to_value >> value;
    }
    else
    {
        cout << "Denomination was not valid" << endl;

    }
}
