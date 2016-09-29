#version 430

out vec4 color;

uniform float time;

vec4 getRandColor()
{
    return vec4(sin(time), cos(time), tan(time), cos(time));
}

void main()
{
    color = getRandColor();
}

