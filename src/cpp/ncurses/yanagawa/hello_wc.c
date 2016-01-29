#include <ncurses.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");
    initscr();

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLUE);
    bkgd(COLOR_PAIR(1));

    erase();
    move(10, 20);
    addstr("こんにちWorld");
    refresh();

    timeout(-1);
    getch();

    endwin();
    return 0;
}
