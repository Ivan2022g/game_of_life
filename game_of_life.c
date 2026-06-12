#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#define SPASE ' '
#define CANT_START_GAME "Не удалось инициализировать игру"
#define WIDTH 80
#define HEIGHT 25

struct GameState {
    // Текущее состояние поля (1 - живая, 0 - мёртвая)
    unsigned char current[HEIGHT][WIDTH];

    // Буфер для следующего поколения (для одновременного обновления)
    unsigned char next[HEIGHT][WIDTH];

    // Скорость смены поколений (задержка в миллисекундах)
    int delay_ms;

    // Флаги состояния игры
    int is_running;  // 1 - игра активна, 0 - завершена
    int is_stable;   // 1 - достигнута стабильная конфигурация
    int population;  // Текущее количество живых клеток

    // Статистика для определения стабильности
    unsigned long generation;              // Номер текущего поколения
    unsigned long last_population_change;  // Когда последний раз менялась популяция
};

// Вспомогательная структура для координат
struct Cell {
    int x;  // от 0 до WIDTH-1
    int y;  // от 0 до HEIGHT-1
};
int init(int argc, char* argv[], struct GameState game_state);
void wait_for_action(int action);
int game_over(struct GameState game_state);
void draw_field(struct GameState game_state);
void process(struct GameState game_state);
void do_one_life_cycle(struct GameState game_state);
void finish(struct GameState game_state);

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

int init(int argc, char* argv[], struct GameState game_state) {
    // инициализация
    // В потоке stdin есть строки из одного файла инициализации (.txt)
    // Нужно считать всё из потока и очистить его, чтобы считать нажатие SpaseBar для старта игры
    // Инициализировать ncurses и состояние
}

void wait_for_action(int action) {
    // ожидает нажатия на SPASE
    while (1) {
        if (getchar() == SPASE) {
            break;
        }
    }
}
int game_over(struct GameState game_state) {
    // do something...
}
void draw_field(struct GameState game_state) {
    // do something...
}
void process(struct GameState game_state) {
    // do something...
}
void do_one_life_cycle(const struct GameState game_state) {
    draw_field(game_state);
    wait_for_action(SPASE);

    while (!game_over(game_state)) {
        do_one_life_cycle(game_state);

        draw_field(game_state);
    }
    wait_for_action(SPASE);
}

void finish(struct GameState game_state) {}