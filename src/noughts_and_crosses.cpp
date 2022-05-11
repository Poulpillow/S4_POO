#include "noughts_and_crosses.hpp"

void draw_board(p6::Context& context)
{
    for (float i = -0.65f; i < 0.7f; i += 0.65f) {
        for (float j = -0.65f; j < 0.7f; j += 0.65f) {
            context.fill = {i / 3.0f + 1 / 3.0f, j / 3.0f + 1 / 3.0f, 0};
            context.square(p6::Center{i, j},
                           p6::Radius{0.3f});
        }
    }
}

void play_noughts_and_crosses()
{
    auto ctx = p6::Context{{1280, 720, "Noughts and Crosses"}};
    ctx.background({0.2f, 0.2f, 0.2f});
    ctx.use_stroke = false;
    draw_board(ctx);

    // ctx.update = [&]() {
    //     ctx.background({0.5f, 0.3f, 0.8f});
    //     ctx.square(p6::Center{ctx.mouse()},
    //                p6::Radius{0.3f});
    // };

    ctx.start();
}