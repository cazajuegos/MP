//Dos formas de mover el texto en el terminal
#include <ncurses.h>

int main(){
  initscr();
  move(5,10);
  printw("Hello World");
  mvprintw(10, 5, "Now, I'm here!");
  refresh();
  getch();
  endwin();
}
