#include <ncurses.h>

int main(){
  initscr();
  int x, y;
  getmaxyx(stdscr, y, x);
  move(y/2, x/2);
  attron(A_REVERSE);
  printw("a");
  attroff(A_BOLD);
  refresh();
  getch();
  endwin();
return 0;
}
