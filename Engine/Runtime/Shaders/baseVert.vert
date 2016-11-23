#version 430

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;

uniform mat4 translation;
uniform mat4 perspective;
uniform mat4 modelView;

out vec3 ourColor;
out vec2 texCoord;
out vec3 Normal;
out vec3 FragPos;

void main()
{
    ourColor = normal;
    texCoord = texCoords;
    
    Normal = mat3(transpose(inverse(translation))) * normal;
    FragPos = vec3((translation) * (vec4(position, 1.0f)));
    
    gl_Position = (perspective * modelView * translation) * 
            (vec4(position.x + (gl_InstanceID * 5), position.y, position.z, 1.0f));
}
