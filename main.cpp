/*
 *       _   _   _   _
 *     _/ \_/ \_/ \_/ `-<>~
 *
 */
#include<curses.h>
#include <ctype.h>
#include<iostream>
#include <stdlib.h>
#include <unistd.h>

#include "game.h"

using namespace std;

void draw(Game game) {
    for(Node *current=game.snake->head; current != NULL; current=current->prev) {
        mvaddstr(current->position->y, current->position->x, "*");
    }
    mvaddstr(game.apple.y, game.apple.x, "*");
}

int main() {
    WINDOW * mainwin;

    /*  Initialize ncurses - it gives us non blocking IO */

    if ( (mainwin = initscr()) == NULL ) {
        fprintf(stderr, "Error initializing ncurses.\n");
        exit(EXIT_FAILURE);
    }
    noecho();                  /*  Turn off key echoing                 */
    keypad(mainwin, TRUE);     /*  Enable the keypad for non-char keys  */
    curs_set(0);
    cbreak();
    nodelay(mainwin, TRUE);

    /* end of ncurses init */

    char tmp, key;
    Game game(30, 30);
    while(1) {
        tmp = key = 0;
        // take last pressed key
        do {
            key = tmp;
            tmp = getch();
        } while(tmp != ERR);

        switch(key) {
            case 'w': game.snake->direction = NORTH;
                      break;
            case 's': game.snake->direction = SOUTH;
                      break;
            case 'a': game.snake->direction = WEST;
                      break;
            case 'd': game.snake->direction = EAST;
                      break;
            case 'q': exit(0);
                      break;
        }
        game.Move();
        wclear(mainwin);
        draw(game);
        refresh();
        usleep(500000);
    }

    return 0;
}
