#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include "texture.h"

void texture_load_pixels(char *path, u8 **pixels_out, size_t *width_out, size_t *height_out) {
    int width, height, channels;

    // OpenGL has texture coordinates with (0, 0) on bottom
    stbi_set_flip_vertically_on_load(true);
    unsigned char *image = stbi_load(path, &width, &height, &channels, STBI_rgb_alpha);
    assert(image != NULL);

    *pixels_out = malloc(width * height * 4);
    memcpy(*pixels_out, image, width * height * 4);
    *width_out = width;
    *height_out = height;

    stbi_image_free(image);
}

struct Texture texture_create_from_pixels(u8 *pixels, size_t width, size_t height) {
    struct Texture self = {
        .size = (ivec2s) {{ width, height }}
    };

    glGenTextures(1, &self.handle);
    glBindTexture(GL_TEXTURE_2D, self.handle);

    // No interpolation
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
    return self;
}

struct Texture texture_create_from_path(char *path) {
    u8 *pixels;
    size_t width, height;
    texture_load_pixels(path, &pixels, &width, &height);
    struct Texture self = texture_create_from_pixels(pixels, width, height);
    free(pixels);
    return self;
}

void texture_destroy(struct Texture self) {
    glDeleteTextures(1, &self.handle);
}

void texture_bind(struct Texture self) {
    glBindTexture(GL_TEXTURE_2D, self.handle);
}
