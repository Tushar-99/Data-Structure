#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

int main()
{

struct Gun
{
    string name;
    int damage;
    int cost;
    bool purchased;
    bool equipped;

} M4A1, FAMAS;

//WEAPONS INFO
M4A1.cost = 50;
M4A1.damage = 5;
M4A1.purchased = false;
M4A1.equipped = false;

FAMAS.cost = 300;
FAMAS.damage = 10;
FAMAS.purchased = false;
FAMAS.equipped = false;
//WEAPONS INFO

//-----PLAYER(BEGIN)-----

struct Player
{
    int health;
    string name;
    int money;
    int energy;

    string l_a;
    string r_a;
    string l_l;
    string r_l;

    string rank;

} Player;

//GAME PLAYER BEGIN

Player.l_a = "Normal";
Player.r_a = "Normal";
Player.l_l = "Normal";
Player.r_l = "Normal";

Player.health = 100;
Player.money = 100;
Player.energy = 100;

string plyrname;
string rank = "Private";

Player.name = plyrname;

//GAME PLAYER END

//-----PLAYER(END)-----

cout << "What is your name? ";
cin >> plyrname;

goto mmenu;


mmenu:

//-----MAIN MENU(BEGIN)-----
system("CLS");
if (Player.l_a == "Damaged")
{
    cout << "Your Left Arm is damaged! Sleep for a while to fix it!";
    Sleep(1600);
}
if (Player.r_a == "Damaged")
{
    cout << "Your Right Arm is damaged! Sleep for a while to fix it!";
    Sleep(1600);
}
if (Player.l_l == "Damaged")
{
    cout << "Your Left Leg is damaged! Sleep for a while to fix it!";
    Sleep(1600);
}
if (Player.r_l == "Damaged")
{
    cout << "Your Right Leg is damaged! Sleep for a while to fix it!";
    Sleep(1600);
}


if (Player.money >= 500 && Player.rank == "Private")
{
    system("CLS");
    cout << "You have been promoted to Private 2!";
    Player.rank = "Private 2";
    Sleep(1600);

}

if (Player.money >= 1000 && Player.rank == "Private 2")
{
    system("CLS");
    cout << "You have been promoted to Private First Class!";
    Player.rank = "Private First Class";
    Sleep(1600);
}


system("CLS");
cout << "Health: " << Player.health << ". Money: " << Player.money << " dollars." << "   Energy: " << Player.energy;
if (M4A1.equipped)
    cout << "\nGun: M4A1";
if (FAMAS.equipped)
    cout << "\nGun: FAMAS";

cout << "\n\nRank: " << Player.rank;
cout << "\n\n1) Go to Gunstore\n2) Sleep\n3) Fight\n\nAction: ";
int mmenuch1;
cin >> mmenuch1;

if (mmenuch1 == 1)
{
    goto gunstore;
}

if (mmenuch1 == 2)
{
    system("CLS");
    cout << "You sleep, restoring your energy.";
    Player.energy = 100;

    if (Player.l_a == "Damaged")
    {
        cout << "\n\nYour Left Arm was healed.";
        Player.l_a = "Normal";
    }
    if (Player.r_a == "Damaged")
    {
        cout << "\n\nYour Right Arm was healed.";
        Player.r_a = "Normal";
    }
    if (Player.l_l == "Damaged")
    {
        cout << "\n\nYour Left Leg was healed.";
        Player.l_l = "Normal";
    }
    if (Player.r_l == "Damaged")
    {
        cout << "Your Right Leg was healed.";
    }


    Sleep(1400);
    goto mmenu;
}

if (mmenuch1 == 3)
{
    system("CLS");
    goto fight;
}

//-----MAIN MENU(END)-----


fight:
srand(time(0));

system("CLS");

if (Player.r_a == "Damaged" || Player.r_l == "Damaged" || Player.l_a == "Damaged" || Player.l_l == "Damaged")
{
    cout << "You're injured, sleep to heal.";
    Sleep(1400);
    goto mmenu;
}

if (Player.energy < 40)
{
    cout << "You don't have enough energy to fight.";
    Sleep(1400);
    goto mmenu;
}

if (M4A1.equipped == false && FAMAS.equipped == false)
{
    cout << "You don't have a gun equipped.";
    Sleep(1400);
    goto gunstore;
}

if (M4A1.equipped == true && Player.energy > 40)
{

    int randnum1 = rand() % (M4A1.damage - 2 + 1) + 2;
    Player.money = Player.money + (randnum1 * 15);
    Player.energy = Player.energy - 40;

    int randnum3 = rand() % (10 - 1 + 1) + 1;
    if (randnum3 < 4)
    {

        int randnum4 = rand() % (13 - 1 + 1) + 1;

        if (randnum4 < 3)
        {
            Player.l_a = "Damaged";
        }
        if (randnum4 <= 6 && randnum4 >= 4)
        {
            Player.r_a = "Damaged";
        }
        if (randnum4 <= 9 && randnum4 >= 7)
        {
            Player.l_l = "Damaged";
        }
        if (randnum4 <= 13 && randnum4 >= 10)
        {
            Player.r_l = "Damaged";
        }



    }


    cout << "You fight, killing " << randnum1 << " enemies, making " << randnum1 * 15 << " dollars!";
    Sleep(1600);
    goto mmenu;





}




if (FAMAS.equipped == true && Player.energy > 40)
{
    int randnum2 = rand() % (FAMAS.damage - 4 + 1) + 4;
    Player.money = Player.money + (randnum2 * 15);
    Player.energy = Player.energy - 40;




    int randnum5 = rand() % (10 - 1 + 1) + 1;
    if (randnum5 < 4)
    {

        int randnum6 = rand() % (13 - 1 + 1) + 1;

        if (randnum6 < 3)
        {
            Player.l_a = "Damaged";
        }
        if (randnum6 <= 6 && randnum6 >= 4)
        {
            Player.r_a = "Damaged";
        }
        if (randnum6 <= 9 && randnum6 >= 7)
        {
            Player.l_l = "Damaged";
        }
        if (randnum6 <= 13 && randnum6 >= 10)
        {
            Player.r_l = "Damaged";
        }



    }



    cout << "You fight, killing " << randnum2 << " enemies, making " << randnum2 * 15 << " dollars!";
    Sleep(1600);
    goto mmenu;
}



//-----GUNSTORE(BEGIN)-----
gunstore:
system("CLS");
cout << "Welcome to the gunstore! You have " << Player.money << " dollars.";
cout << "\n\n1)M4A1 | Assault Rifle | $50\n2)FAMAS | Assault Rifle | $300\n\n3)Back\n\nAction: ";

int gschoice1;

cin >> gschoice1;

if (gschoice1 == 1)
{
    goto prchs_M4A1;
}
else if (gschoice1 == 2)
{
    goto prchs_FAMAS;
}
else if (gschoice1 == 3)
{
    goto mmenu;
}


prchs_M4A1:

system("CLS");

if (M4A1.purchased == true)
{
    cout << "You already purchased the M4A1. Would you like to equip it?\n\n1)Yes\n2)No\n\nAction: ";
    int gschoice6;
    cin >> gschoice6;

    if (gschoice6 == 1)
    {
        system("CLS");
        M4A1.equipped = true;
        FAMAS.equipped = false;
        goto mmenu;
    }
    else if (gschoice6 == 2)
    {
        goto gunstore;
    }


}


if (Player.money >= 0)
{
    system("CLS");
    cout << "Would you like to buy the M4A1?";
    cout << "\n\n1)Yes\n2)No\n\nAction: ";

    int gschoice2;
    cin >> gschoice2;

    if (gschoice2 == 1)
    {
        system("CLS");
        Player.money = Player.money - M4A1.cost;
        M4A1.purchased = true;
        cout << "You've purchased the M4A1. Would you like to equip it?\n\n1)Yes\n2)No\n\nAction: ";
        int gschoice3;
        cin >> gschoice3;



        if (gschoice3 == 1)
        {
            system("CLS");
            M4A1.equipped = true;
            FAMAS.equipped = false;

            cout << "You've equipped the M4A1";
            Sleep(1400);
            goto gunstore;
        }

        if (gschoice3 == 2)
        {
            system("CLS");
            M4A1.equipped = false;
            goto gunstore;
        }


    }

    if (gschoice2 == 2)
    {
        system("CLS");
        goto gunstore;
    }

}
else if (Player.money < 0)
{
    system("CLS");
    cout << "You don't have enough money.";
    Sleep(1400);
    goto gunstore;

prchs_FAMAS:

if (FAMAS.purchased == true)
{
    cout << "You already purchased the FAMAS. Would you like to equip it?\n\n1)Yes\n2)No\n\nAction: ";
    int gschoice7;
    cin >> gschoice7;

    if (gschoice7 == 1)
    {
        system("CLS");
        FAMAS.equipped = true;
        M4A1.equipped = false;
        goto mmenu;
    }
    else if (gschoice7 == 2)
    {
        goto gunstore;
    }
}



    if (Player.money >= 100)
    {
        system("CLS");
        cout << "Would you like to buy the FAMAS?";
        cout << "\n\n1)Yes\n2)No\n\nAction: ";

        int gschoice4;
        cin >> gschoice4;

        if (gschoice4 == 1)
        {
            system("CLS");
            Player.money = Player.money - FAMAS.cost;
            FAMAS.purchased = true;
            cout << "You've purchased the FAMAS. Would you like to equip it?\n\n1)Yes\n2)No\n\nAction: ";
            int gschoice5;
            cin >> gschoice5;

            if (gschoice5 == 1)
            {
                system("CLS");
                FAMAS.equipped = true;
                M4A1.equipped = false;
                cout << "You've equipped the FAMAS";
                Sleep(1400);
                goto gunstore;
            }

            if (gschoice5 == 2)
            {
                system("CLS");
                FAMAS.equipped = false;
                goto gunstore;
            }


        }

        if (gschoice4 == 2)
        {
            system("CLS");
            goto gunstore;
        }

    }
    else if (Player.money < 100)
    {
        system("CLS");
        cout << "You don't have enough money.";
        Sleep(1400);
        goto gunstore;
    }
    //-----GUNSTORE-----




}