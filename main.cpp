#include <iostream>
#include <string>
#include<cstdlib>
#include <time.h>
#include "Card.h"
//#include "Deck.h"
#include "Hand.h"
#include "Black_Jack.h"

using namespace std;

void play();
int main()
{   
    system("clear");
    cout << "Welcome to Black Jack! \nEnter 1 to HIT 2 to STAY" << endl;
    play();
    return 0;
}

void play()
{
    char repeat = 'y';
    Black_Jack game = Black_Jack();
    if (game.gameover == true)
    {
	cout <<"Play again? (y/n): ";
	cin >> repeat;
	if (repeat == 'y')
	    main();
	else system("clear");
    }
	   
}
