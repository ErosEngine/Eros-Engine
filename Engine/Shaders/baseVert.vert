#version 430

in vec3 position;

void main()
{
    gl_Position = vec4(position.xyz, 1.0f);
}
