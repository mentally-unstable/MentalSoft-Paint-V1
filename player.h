#include <iostream>

#include <ncurses.h>

#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player
{
    public:
        Player(WINDOW *win, int y, int x, char c1, char c2);

        void mvup();
        void mvdown();
        void mvleft();
        void mvright();
        int getmv();
        void display();
        bool penup;

    private:
        int xLoc, yLoc, xMax, yMax;
        char character1;
        char character2;
        WINDOW *curwin;          
};

Player::Player(WINDOW * win, int y, int x, char c1, char c2)
{
    curwin = win;
    xLoc = x;
    yLoc = y;
    getmaxyx(curwin, yMax, xMax);
    keypad(curwin, true);
    character1 = c1;
    character2 = c2;
}

void Player::mvup()
{
    if(Player::penup == false)
    {
        mvwaddch(curwin, yLoc, xLoc, '.');
    } else if(Player::penup == true)
    {
        mvwaddch(curwin, yLoc, xLoc, ' ');
    }
    
    yLoc--;
    if(yLoc < 1)
    {
        yLoc = 1;
    }
}

void Player::mvdown()
{
    if(Player::penup == false)
    {
        mvwaddch(curwin, yLoc, xLoc, '.');
    } else if(Player::penup == true)
    {
        mvwaddch(curwin, yLoc, xLoc, ' ');
    }
    yLoc++;
    if(yLoc > yMax - 2)
    {
        yLoc = yMax - 2;
    }
}

void Player::mvleft()
{
    if(Player::penup == false)
    {
        mvwaddch(curwin, yLoc, xLoc, '.');
    } else if(Player::penup == true)
    {
        mvwaddch(curwin, yLoc, xLoc, ' ');
    }
    xLoc--;
    if(xLoc < 1)
    {
        xLoc = 1;
    }
}

void Player::mvright()
{
    if(Player::penup == false)
    {
        mvwaddch(curwin, yLoc, xLoc, '.');
    } else if(Player::penup == true)
    {
        mvwaddch(curwin, yLoc, xLoc, ' ');
    }
    xLoc++;
    if(xLoc > xMax - 2)
    {
        xLoc = xMax - 2;
    }
}

int Player::getmv()
{
    int choice = wgetch(curwin);
    switch(choice)
    {
        case 'c':
            wclear(curwin);
            wborder(curwin, '#', '#', '#', '#', '#', '#', '#', '#');
            wrefresh(curwin);
            break;
        case 'd':
            penup = true;
            break;
        case 'e':
            penup = false;
            break;
        case KEY_UP:
            mvup();
            break;
        case KEY_DOWN:
            mvdown();
            break;
        case KEY_LEFT:
            mvleft();
            break;
        case KEY_RIGHT:
            mvright();
            break;
        default:
            break;
    }
    return choice;
}

void Player::display()
{
    if(penup == false)
    {
        mvwaddch(curwin, yLoc, xLoc, character1);
    } else if(penup == true)
    {
        mvwaddch(curwin, yLoc, xLoc, character2);
    }
}

#endif

