#include "tictactoe.h"
#include <ncurses.h>
#include <stdio.h>

void initCurses(){

    initscr ();
    cbreak ();
    noecho ();
    keypad (stdscr, TRUE);

}
/*Drawing Board and refresh grid*/

void drawBoard(){
  int i;
  int h;

  for(i=0; i<=6; i++){

      mvaddch(i, 0, '|');
      mvaddch(i, 4, '|');
      mvaddch(i, 8, '|');
      mvaddch(i, 4, '|');
      mvaddch(i, 8, '|');
      mvaddch(i, 12, '|');

        if(i%2 ==0){

            for(h=0; h<=12; h++){
              mvaddch(i, h, '-');
            }
        }
    move (1,2);

  }
  refresh();
}

/*Fills the array boardData to restart is someone wins*/
void initBoard(int * boardData){

  int i;
  for(i=0;i<=8;i++){
    boardData[i] = i+2;
  }
}
/*Play game function lets user move arrow keys and put a marker down (meat of this)*/

int playGame(){

  int boardData[9]; /*Holds corresponding values*/
  int playerNum = 1; /*Determines which player moves*/




}
