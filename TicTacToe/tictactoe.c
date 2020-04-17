#include <ncurses.h>
#include "tictactoe.h"

int main() {
    int keepPlaying; /*Re-up the game*/
    do{
      initCurses(); /*Starts ncurses*/
      drawBoard(); /*Draws the board*/
      playGame(); /*GamePlay between two players*/
      keepPlaying = playGame(); /*Will return 3 if game is won, lossed, or tied*/
    }while(keepPlaying === 3); /*Starts a new game option when 3 is retruned*/

    endwin();

  return(0);

}
