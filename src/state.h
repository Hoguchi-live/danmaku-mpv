#ifndef _STATE_H_
#define _STATE_H_

#include "gfx/gfx.h"
#include "gfx/renderer.h"
#include "gfx/window.h"
#include "util/util.h"

struct State {
    struct Window *window;
    struct Player *player;
    struct Renderer *renderer;
    size_t ticks;
};

// global state
extern struct State state;
#endif

