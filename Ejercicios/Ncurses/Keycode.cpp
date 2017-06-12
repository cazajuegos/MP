//Saber que tecla estas pulsando
#include <ncurses.h>

int main(){
  initscr();
  int c;
  printw("Write something (ESC to escape): ");
  while((c=getch())!=27){
    move(10,0);
    printw("Keycode: %d, and the character: %c",c,c);
    move(0,0);
    printw("Write something (ESC to escape): ");
  }
  endwin();
  return 0;
}
