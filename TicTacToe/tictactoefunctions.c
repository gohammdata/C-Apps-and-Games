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
  int inputChar; /*Gets character input*/
  int x = 2, y = 1; /*The initial x,y coorinates in the grid*/
  int didWin = 0; /*Game won or not*/
  int canWeMove = 0; /*Preventing overwrites*/
  int nMoves = 0; /*Counts the number of moves to find if its a cat game*/

  initBoard(boardData);

  mvprintw(8, 0, "It is Player 1's turn to place an (X)");
  move(y,x);
  refresh();

  while (inputChar != 'q'){

    if(nMoves == 9){
      mvprintw(10,0,"CAT GAME");
      inputChar = getch();
      erase();
      return 3;
    }

    inputChar = getch();

    if (inputChar != ' ')
      switch (inputChar) {
        case KEY UP:
          if(y == 3 \\ y ==5){
              move(y=y-2,x);
          }
          break;
        case KEY DOWN:
          if(y == 1 || y == 3){
            move(y=y+2,x);
          }
          break;
        case KEY LEFT:
          if(x == 10 || x == 6){
            move(y, x=x-4);
          }
          break;
        case KEY RIGHT:
          if(x ==2 || x == 6){
            move(y, x=x+4);
          }
          break;
      }
  }




}
