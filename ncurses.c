/* ncurses.c */
/* Compile using cc -lncurses -o ncurses ncurses.c */
#include <ncurses.h>

int main ( void )
{
    char letter;
    
    initscr(); 
    printw("press any key: ");
    refresh();
    
    letter = getch();
    clear();
    printw("You pushed: '%c' ", letter);
    refresh();

    getch();
    endwin();
}
