#include "Black_Jack.h"
#include <time.h>
#include <iomanip>
#include <time.h>

Black_Jack::Black_Jack()
{

    //set attributes
    gameover = false;
    option = 0;

    //starting deck and hands
    deck = Deck();
    player = Hand(deck.deal(), deck.deal());
    house = Hand(deck.deal(), deck.deal());

    //game play
    opening();
    check_player_value();

    if (gameover == false)
        hit_stay();
    if (gameover == false)
        house_move();

}

void Black_Jack::opening()
{
       //sleep info
        struct timespec slptm;
        slptm.tv_sec = 0;
        slptm.tv_nsec = 1000 * 1000000 * 100000;

    cout << "The cards are being dealt";
    for (int i = 0; i < 7; i++)
    {
        nanosleep(&slptm,NULL);
        cout << ".";
    }

    cout << "\n\nYour cards:" << endl;
    player.show_cards();
    cout << "\nHouse cards:" << endl;
    house.show_cards();
}

void Black_Jack::hit_stay()
{
    cout << "\nHIT or STAY" << endl;
    cin >> option;

    if (option == 1)
    {
        cout << "\nPlayer Hits!" << endl;
        player.receive_card(deck.deal());
        player.show_cards();
        check_player_value();
        if (gameover == false)
            hit_stay();
    }
    else if (option == 2)
    {
        cout << "Player Stays! House move." << endl;
    }

    else
    {
        cout << "1 = HIT / 2 = STAY" << endl;
        hit_stay();
    }
}

void Black_Jack::check_player_value()
{
    if (player.bust == true)
    {
        cout << "Player Busts!" << endl;
        gameover = true;
    }
    else if (player.value == 21)
    {
        cout << "21!! Player Wins" << endl;
        gameover = true;
    }
    else
        NULL;
}

void Black_Jack::house_move()
{
    while ((house.value < player.value) && (house.value < 22))
    {
        cout << "House Hits" << endl;
        house.receive_card(deck.deal());
    }
     house.show_cards();
    if (house.value > 21)
    {
        cout << "House busts! Player Wins!" << endl;
        gameover = true;
    }

    else // house is less than 21 and greater that player
    {
        cout << "House hits " << house.value << " Player Loses!" << endl;
        gameover = true;
    }
}
