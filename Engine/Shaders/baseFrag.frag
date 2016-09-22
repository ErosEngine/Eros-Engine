#version 430

out vec4 color;

uniform float time;

vec4 getRandColor()
{
    return vec4(sin(time), cos(time), tan(time), 1.0f);
}

void main()
{
    color = getRandColor();
}

