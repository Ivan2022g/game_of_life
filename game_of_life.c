#include <stdio.h>
#inclide <stdlib.h>

struct GameState {

};

int process(struct GameState game_state) {
    draw_field(game_state);
    wait_for_action(action);

    while (!game_over(game_state)) {
        do_one_life_cycle(game_state);

        draw_field(game_state);
    }
    wait_for_action(action);
}
int init(int argc, char *argv[], struct GameState game_state) {

}
int main(int argc, char *argv[]) {
    struct GameState game_state;
    init( argc, argv, game_state);
    process(game_state);
    close();
}
