// hello

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "player.h"
#include <ncurses.h>

int main(int argc, char ** argv)
{
    // making the window
    initscr();
    cbreak();
    noecho();
    curs_set(0);

    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);
    
    int yCenter = (yMax / 2) - 20;
    // int xCenter = (xMax / 2) - 33;

    WINDOW * playwin = newwin(55, 150, 0, 31);
    wborder(playwin, '#', '#', '#', '#', '#', '#', '#', '#');
    
    WINDOW * info = newwin(15, 30, yCenter - 8, (xMax / 2) - 90);
    wborder(info, '|', '|', '-', '-', '+', '+', '+', '+');
    mvwprintw(info, 1, 6, "MentalSoft - Paint");
    mvwprintw(info, 2, 1, " ");
    mvwprintw(info, 3, 2, "INFO:");
    mvwprintw(info, 4, 1, "----------------------------");
    mvwprintw(info, 5, 2, "- x: to leave (or CTRL-C)");
    mvwprintw(info, 6, 2, "- d: delete mode");
    mvwprintw(info, 7, 2, "- e: draw mode");
    mvwprintw(info, 8, 2, "- c: clear all");

    /* decided not to implement, but *could* in the future
    mvwprintw(info, 8, 2, "- colors:");
    mvwprintw(info, 9, 4, "- 1: red");
    mvwprintw(info, 10, 4, "- 2: blue");
    mvwprintw(info, 11, 4, "- 3: white");
    mvwprintw(info, 12, 4, "- 4: yellow");
    mvwprintw(info, 13, 4, "- 5: green");
    mvwprintw(info, 14, 4, "- 6: magenta (pink-ish)");
    mvwprintw(info, 15, 4, "- 7: cyan (kinda bluish i guess)");
    */

    refresh();
    wrefresh(playwin);
    wrefresh(info);



    
    Player * p = new Player(playwin, (yMax / 2), (xMax / 2) - 15, '/', '|');
    do
    {
        p -> display();
        wrefresh(playwin);
    }while(p -> getmv() != 'x');
    




    endwin();

    return 0;
}

