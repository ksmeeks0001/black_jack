#include <iostream>
#include <Card.h>
#include <Deck.h>
#include <string>
#include<cstdlib>
#include <time.h>
#include <Hand.h>
#include <Black_Jack.h>

using namespace std;

void play();
int main()
{
    cout << "Welcome to Black Jack! \nEnter 1 to HIT 2 to STAY" << endl;
    play();
    return 0;
}

void play()
{
    Black_Jack game = Black_Jack();
    if (game.gameover == true)
        play;
}
