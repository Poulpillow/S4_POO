#pragma once

#include <p6/p6.h>

struct Case {
    glm::vec2 position;
    float     size;
};

// struct Player {
//     int number;
// };

void draw_icon(p6::Context& context, int player);
bool is_in_cell(Case cell, glm::vec2 mouse_position);
void play_knots_and_crosses();