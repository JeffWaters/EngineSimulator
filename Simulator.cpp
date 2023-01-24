#include <iostream>
#include <ctime>

const int TICKS_PER_SEC = 60;
const double MS_PER_TICK = 1000.0 / TICKS_PER_SEC;

int main() {
    double previous_time = clock();
    double lag = 0;

    // run game loop
    while (true) {
        double current_time = clock();
        double elapsed_time = current_time - previous_time;
        previous_time = current_time;
        lag += elapsed_time;

        // handle input

        // update game state
        while (lag >= MS_PER_TICK) {
            // update game logic
            lag -= MS_PER_TICK;
        }

        // render

        // sleep
        double sleep_time = MS_PER_TICK - lag;
        if (sleep_time > 0) {
            usleep(sleep_time * 1000);
        }
    }

    return 0;
}
