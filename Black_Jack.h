#ifndef BLACK_JACK_H
#define BLACK_JACK_H
#include <Deck.h>
#include <Hand.h>
#include<iostream>


using namespace std;

class Black_Jack
{
    public:


        Deck deck; // deck for the game
        Hand player, house; // player hand and the house hands of cards
        int option; // option for HIT or STAY functions
        bool gameover; // true when round is over

        //constructor
        Black_Jack();

        //starting display
        void opening();

        //check if player busts or hits 21 for game over
        void check_player_value();

        //HIT or STAY
        void hit_stay();

        //house hits to win
        void house_move();


};

#endif // BLACK_JACK_H
