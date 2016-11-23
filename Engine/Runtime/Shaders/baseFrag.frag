#version 430

out vec4 color;

in vec3 ourColor;
in vec2 texCoord;
in vec3 Normal;
in vec3 FragPos;

uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 viewPos;

uniform float time;
uniform float ambientStrength;
uniform float specularStrength;

uniform sampler2D diffuse_texture1;

vec4 getRandColor()
{
    return vec4(sin(time), cos(time), tan(time), cos(time));
}

void main()
{
    vec3 ambient = ambientStrength * lightColor;
    vec3 normalizedVec = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectionDir = reflect(-lightDir, normalizedVec);
    float spec = pow(max(dot(viewDir, reflectionDir), 0.0f), 32);
    vec3 specular = specularStrength * spec * lightColor;
    
    float difference = max(dot(normalizedVec, lightDir), 0.0f);
    vec3 diffuse = difference * lightColor;
    vec3 result = (ambient + diffuse + specular) * vec3(texture2D(diffuse_texture1, texCoord));    
    
    color = vec4(result, 1.0f);
}

