#version 430

layout (location = 0) in vec3 inPosition;
layout (location = 1) in vec3 inNormal;
layout (location = 2) in vec2 inTexCoords;

out vec2 vsOutTexCoords;
out vec3 vsOutNormal;
out vec3 vsFragPos;


uniform mat4 uniProjectionMat;
uniform mat4 uniTranslation;
uniform mat4 uniModelView;


void main(void)
{
    vsOutTexCoords = inTexCoords;
    gl_Position =  vec4(inPosition, 1.0f);
}
