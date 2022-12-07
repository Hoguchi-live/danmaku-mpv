#include "main.h"

// global state
struct State state;

void init() {
    state.window = &window;

    state.renderer = renderer_create();
    renderer_init(state.renderer);
}

void destroy() {
    //renderer_destroy(&state.renderer);
    //ui_destroy(&state.ui);
}

void tick() {
    state.ticks++;
    //ui_tick(&state.ui);
}

void update() {
    //renderer_update(&state.renderer);
    //ui_update(&state.ui);

    //// mouse toggle (ESC)
    //if (state.window->keyboard.keys[GLFW_KEY_ESCAPE].pressed) {
    //    mouse_set_grabbed(!mouse_get_grabbed());
    //}
}

void render() {

    // MPV UPDATE HERE
    //renderer_prepare(&state.renderer, PASS_3D);
    //world_render(&state.world);

    //renderer_prepare(&state.renderer, PASS_2D);
    //renderer_push_camera(&state.renderer);
    //{
    //    renderer_set_camera(&state.renderer, CAMERA_ORTHO);
    //    ui_render(&state.ui);
    //}
    //renderer_pop_camera(&state.renderer);
}

int main(int argc, char *argv[]) {
    window_create(init, destroy, tick, update, render);
    window_loop();
}

