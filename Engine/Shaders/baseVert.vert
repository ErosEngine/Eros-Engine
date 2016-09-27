#version 430

in vec3 position;

uniform mat4 translation;
uniform mat4 perspective;
uniform mat4 modelView;

void main()
{
    gl_Position = (perspective * modelView) * (vec4(position, 1.0f));
}
