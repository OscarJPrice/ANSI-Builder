#define FORCE_IN_PLACE
#define EXTEND_ANSI_COLORS_256
#include "ansi.h"
#include <cmath>
#include <thread>
#include <chrono>
#include <iostream>

// Define constants for circle properties and mathematical constants
#define CIRCLE_RADIUS 5 // Radius of the circle
#define VERT_SCALE .56 // Vertical scaling factor for the circle
#define PIx2 (2*3.1415) // Two times Pi for full circle in radians
#define rotation_step(a) (int)(((a)/PIx2)*11) // Macro to calculate rotation steps, should produce values from 0 to 9

int main() {
    ERASE_DISPLAY(MODE_ALL);

    // Array of characters to be used in the animation
    const char *levels[] = {
        " ",  
        FAINT COLOR_256_FG(115) ".", //115 is some shade of green
        FAINT COLOR_256_FG(115) ".", 
        COLOR_256_FG(115) ":", 
        COLOR_256_FG(115) "-", 
        BOLD COLOR_256_FG(115) "=", 
        BOLD COLOR_256_FG(115) "#", 
        BOLD COLOR_256_FG(115) "%", 
        BOLD COLOR_256_FG(115) "@",
        COLOR_256_BG(115) " ",
        BRIGHT_WHITE_BG " "
    };

    // Infinite loop to create an animation
    while(true)
        // Outer loop for one rotation cycle
        for (double k = 0; k < PIx2; k+=PIx2/64) {
            // Inner loop for drawing the circle
            for (double a = k; a < k+PIx2; a+=PIx2/64){
                // Move the cursor to the position calculated for the circle's outline
                CURSOR_TO(round(CIRCLE_RADIUS+2 +CIRCLE_RADIUS*VERT_SCALE*cos(a)), round(CIRCLE_RADIUS+2+CIRCLE_RADIUS*sin(a)));

                // Output different characters with different styles based on the rotation step
                std::cout << levels[rotation_step(a-k)] << ANSI_NORMAL;
            }
            // Flush the output to ensure it's displayed
            std::flush(std::cout);
            // Pause for a short duration to control the speed of the animation
            std::this_thread::sleep_for(std::chrono::milliseconds(15));
        }
    return 0;
}