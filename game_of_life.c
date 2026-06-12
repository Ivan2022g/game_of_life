#include <stdio.h>
#inclide <stdlib.h>

// game_state structure

int process(game_state) {
    draw_field(game_state);
    wait_for_action(action);

    while (!game_over(game_state)) {
        do_one_life_cycle(game_state);

        draw_field(game_state);
    }
    wait_for_action(action);
}

int main(int argc, char *argv[]) {
    game_state;
    init();
    process(game_state);
    close();
}
