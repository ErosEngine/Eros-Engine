#version 430

in vec3 position;

uniform mat4 translation;

void main()
{
    gl_Position = vec4(position, 1.0f) * translation;
}
