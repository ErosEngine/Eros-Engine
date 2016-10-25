#version 430

out vec4 color;

in vec3 ourColor;
in vec2 texCoord;

uniform float time;

uniform sampler2D myTexture1;

vec4 getRandColor()
{
    return vec4(sin(time), cos(time), tan(time), cos(time));
}

void main()
{
    color = texture2D(myTexture1, texCoord);
}

