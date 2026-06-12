#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#define SPASE ' '
#define CANT_START_GAME "Не удалось инициализировать игру"
struct GameState {

};
int init(int argc, char *argv[], struct GameState game_state);
void wait_for_action(int action);
int game_over(struct GameState game_state);
void draw_field(struct GameState game_state);
void process(struct GameState game_state);
void do_one_life_cycle(struct GameState game_state);
void finish(struct GameState game_state);

int main(int argc, char *argv[]) {
    const struct GameState game_state;
    if (init( argc, argv, game_state)) {
        process(game_state);
        finish(game_state);
    } else {
        printf("%s", CANT_START_GAME);
    }
    return 0;

}
int init(int argc, char *argv[], struct GameState game_state) {

}
void wait_for_action(int action) {
    // do something...
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

void finish(struct GameState game_state) {

}