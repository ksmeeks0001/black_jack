#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

class Card
{
    public:
        string suit;
        string denom;
        int value;

        // Constructor takes suit and denomination
        Card(string s , string d);
        Card(); //default construct

        //sets value based on denomination
        void set_value();

};

#endif // CARD_H
