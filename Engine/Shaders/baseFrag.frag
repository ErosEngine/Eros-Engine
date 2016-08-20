#version 430 

out vec4 color;

uniform int time;

vec4 getRandColor()
{
    return vec4(0.3f, 0.1f, 1.0f, 1.0f);
}

void main()
{
    color = getRandColor();
}

