#ifndef RENDERER_H
#define RENDERER_H

#include "../util/util.h"
#include "gfx.h"
#include "shader.h"
#include "vao.h"
#include "vbo.h"

enum FillMode {
    FILL_MODE_FILL, FILL_MODE_LINE
};

#define SHADERS_LAST SHADER_BASIC_COLOR
enum ShaderType {
    SHADER_NONE = 0,
    SHADER_MPV,
    SHADER_BASIC_COLOR,
    SHADER_BASIC_TEXTURE
};

#define TEXTURE_LAST TEXTURE_HOTBAR
enum Textures {
    TEXTURE_HOTBAR
};

enum RenderPass {
    PASS_2D,
};

struct Renderer {
    struct Shader shaders[SHADERS_LAST + 1];
    enum ShaderType current_shader;
    struct Shader shader;

    struct Texture textures[TEXTURE_LAST + 1];

    vec4s clear_color;

    struct VBO vbo, ibo;
    struct VAO vao;
};

struct Renderer* renderer_create();
void renderer_init(struct Renderer *self);
void renderer_destroy(struct Renderer *self);
void renderer_update(struct Renderer *self);
void renderer_prepare(struct Renderer *self, enum RenderPass pass);
void renderer_use_shader(struct Renderer *self, enum ShaderType shader);

void renderer_quad_color(
    struct Renderer *self, vec2s size,
    vec4s color, mat4s model);

void renderer_quad_texture(
    struct Renderer *self, struct Texture texture,
    vec2s size, vec4s color,
    vec2s uv_min, vec2s uv_max,
    mat4s model);

//void renderer_aabb(
//    struct Renderer *self, AABB aabb, vec4s color,
//    mat4s model, enum FillMode fill_mode);

#endif
