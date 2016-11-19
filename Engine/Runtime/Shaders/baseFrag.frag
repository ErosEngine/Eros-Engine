#version 430

out vec4 color;

in vec3 ourColor;
in vec2 texCoord;

uniform float time;

uniform sampler2D diffuse_texture1;
uniform sampler2D diffuse_texture2;
uniform sampler2D diffuse_texture3;
uniform sampler2D diffuse_texture4;
uniform sampler2D specular_texture1;
uniform sampler2D specular_texture2;

vec4 getRandColor()
{
    return vec4(sin(time), cos(time), tan(time), cos(time));
}

void main()
{
    color = getRandColor(); //texture2D(diffuse_texture1, texCoord);
}

