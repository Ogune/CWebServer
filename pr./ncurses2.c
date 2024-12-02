/* ncurses2.c */
#include <ncurses.h>

int main ( void )
{
    int x, y;

    initscr();
    clear();

    getyx(stdscr, y, x);
    printw("So  x = %d\nAnd y = %d  ", x, y);
    refresh();

    x = 10; y = 3;
    move(y, x);
    printw("over here!");
    refresh();

    getch();
    endwin();
}
