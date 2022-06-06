#include "knots_and_crosses.hpp"

// Detect if the mouse is in the cell
bool is_in_cell(Case cell, glm::vec2 mouse_position)
{
    return mouse_position[0] >= cell.position[0] - (cell.size) && mouse_position[0] <= (cell.position[0] + cell.size) && mouse_position[1] >= cell.position[1] - (cell.size) && mouse_position[1] <= (cell.position[1] + cell.size);
}

// Draw knot or cross depending on the number of the player
{
    if (player == 1) {
        const auto image = p6::load_image("src/assets/img/cross.png");
        // context.image(image, p6::Center{cell.position},
        //               p6::RadiusY{0.2f});
        context.image(image, p6::Center{},
                      p6::RadiusY{0.2f});
    }
    else if (player == 2) {
        const auto image = p6::load_image("src/assets/img/nought.png");
        // context.image(image, p6::Center{cell.position},
        //               p6::RadiusY{0.2f});
        context.image(image, p6::Center{},
                      p6::RadiusY{0.2f});
    }
}

void play_knots_and_crosses()
{
    // Initialization
    ctx.background({0.2f, 0.2f, 0.2f});
    ctx.use_stroke = false;

    // Creation of each cells
    std::vector<Case> cells;
    for (float i = -0.65f; i < 0.7f; i += 0.65f) {
        for (float j = -0.65f; j < 0.7f; j += 0.65f) {
            cells.push_back(Case{
                glm::vec2(i, j),
                0.3f});
        }
    }

    // Draw of each cells
    ctx.fill = {0.5, 0.5, 0.5};
    for (const auto& cell : cells) {
        ctx.square(p6::Center{cell.position}, p6::Radius{cell.size});
    }

    // Loop
    //     ctx.background({0.5f, 0.3f, 0.8f});
    //     ctx.square(p6::Center{ctx.mouse()},
    //                p6::Radius{0.3f});
    // };

    int player = 1;

    ctx.update = [&]() {
        for (const auto& cell : cells) {
            if (is_in_cell(cell, ctx.mouse())) {
                ctx.fill = {0.5f, 0.5f, 0.5f};
            }
            else {
                ctx.fill = {0.8f, 0.8f, 0.8f};
            }
            ctx.square(p6::Center{cell.position}, p6::Radius{cell.size});
        }
    };

    ctx.mouse_pressed = [&](p6::MouseButton) {
        draw_icon(ctx, player);
    };
    // ctx.mouse_pressed

    // ctx.mouse_pressed = [&](p6::MouseMove mouse_pressed) {};

    ctx.start();
}