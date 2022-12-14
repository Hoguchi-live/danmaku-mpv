#version 300 es
precision mediump float;
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoords;
out vec2 TexCoords;

uniform mat4 transformation;

void main()
{
    gl_Position = transformation * vec4(aPos, 1.0);
    TexCoords = aTexCoords;
}
