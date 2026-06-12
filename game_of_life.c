#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "settings.h"
#include "structures.h"
#define CANT_START_GAME "Не удалось инициализировать игру"

void process(const struct GameState game_state);
int init(int argc, char* argv[], struct GameState game_state);
void wait_for_action(int action);
int game_over(const struct GameState game_state);
void draw_field(const struct GameState game_state);
void do_one_life_cycle(const struct GameState game_state);
void finish(const struct GameState game_state);
void check_press_button(const struct GameState game_state);

int main(int argc, char* argv[]) {
    const struct GameState game_state;
    if (init(argc, argv, game_state)) {
        process(game_state);
        finish(game_state);
    } else {
        printf("%s", CANT_START_GAME);
    }
    return 0;
}

// -------------------- MAIN FUNCTION --------------------
void process(struct GameState game_state) {
    // сделать вывод правил игры или меню
    draw_field(game_state);
    wait_for_action(SPACE);

    while (!game_over(game_state)) {
        check_press_button(game_state);
        do_one_life_cycle(game_state);
        draw_field(game_state);
    }
    wait_for_action(SPACE);
}
// -------------------- END OF MAIN FUNCTION --------------------

int init(int argc, char* argv[], struct GameState game_state) {
    // инициализация
    // В потоке stdin есть строки из одного файла инициализации (.txt)
    // Нужно считать всё из потока, сохранить в state и очистить его,
    // чтобы считать нажатие SpaseBar для старта игры
    // Инициализировать ncurses и состояние
    initsrc();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);

    return 0;
}

void wait_for_action(int action) {
    // ожидает нажатия на SPASE
    while (1) {
        if (getchar() == SPACE) {
            break;
        }
    }
}

void check_press_button(struct GameState game_state) {
    // считывает нажатия
    // проверяет на рабочие клавиши (SpaceBar и A - увеличение/Z - уменьшение)
}
int game_over(struct GameState game_state) {
    // проверяет состояние игры на предмет того что игра закончилась
}
void draw_field(const struct GameState game_state) {
    // всё что делает - рисует! Ничего больше!
}

void do_one_life_cycle(const struct GameState game_state) {
    // выполняет основные операции по изменению состояния
}
void finish(struct GameState game_state) {
    // закрытие режима работы ncurses и очистка памяти
    endwin();
}