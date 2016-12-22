#version 430


out vec4 color;


struct Material
{
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
};

// ---- Lights ---- //
struct DirectionalLight
{
    bool castShadows;
    vec3 direction;
    // Since this should be the brightest light in the scene
    // this should be the one to hold the ambient color;
    vec3 ambientColor; 
    vec3 diffuseColor;
    vec3 specularColor;
};

struct PointLight
{
    bool castShadows;
    vec3 position;
    vec3 ambientColor;
    vec3 diffuseColor;
    vec3 specularColor;
    
    float constant;
    float linear;
    float quadratic;
};

// TODO(kiecker):
struct SpotLight
{
    int x;
};
// ---- Lights ---- //

// This is going to be data in from the framebuffer
layout (location = 0) in vec3 depthColor;


// Transformations; ie. Vertex shader data
in vec2 texCoord;
in vec3 Normal;
in vec3 FragPos;

uniform int numPointLights;
uniform int numSpotLights;
uniform int numDirectionalLights;


//uniform sampler2D mat_diffuse;
//uniform sampler2D mat_specular;
uniform float mat_shininess;

/*
layout (std140) uniform PointLights_t
{
    PointLight mLight;
} pointLights[MAX_LIGHTS];
*/


uniform PointLight pointLights[50];
uniform SpotLight spotLights[50];
layout (std140) uniform DirectionalLights_t
{
    DirectionalLight mLight;
} directionalLights;


// Old, using for testing
uniform sampler2D diffuse_texture;
uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 viewPos;
uniform float ambientStrength;
uniform float specularStrength;

uniform float time;

vec3 CalculateDirLight(DirectionalLight light, vec3 normal, vec3 viewDir);
vec3 CalculatePointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

// Test main
void nmain()
{
    color = vec4(1.0f, 0.4f, 0.4f, 1.0f);
}

// Actual main
void main()
{
    vec3 dir = normalize(viewPos - FragPos);
    vec3 norm = normalize(Normal);
    
    vec3 result;
    for (int i = 0; i < numDirectionalLights; ++i)
    {
        result += CalculateDirLight(directionalLights.mLight, norm, dir);
    }
    for (int i = 0; i < numPointLights; ++i)
    {
        result += CalculatePointLight(pointLights[i], norm, FragPos, dir);
    }
    color = vec4(result, 1.0f);
}

vec3 CalculateDirLight(DirectionalLight light, vec3 normal, vec3 viewDir)
{
    if (light.diffuseColor == vec3(0, 0, 0))
    {
        return vec3(1.0f, 0.0f, 0.0f);
    }
    
    vec3 lightDir = normalize(-light.direction);
    
    // Calculate diffuse
    float diff = max(dot(normal, lightDir), 0.0f);
    
    // Calculate specular
    vec3 reflectionDir = reflect(-lightDir, normal);
    float spec = (pow(max(dot(viewDir, reflectionDir), 0.0f), mat_shininess));
    
    // Combine results
    vec3 ambientCol = light.ambientColor * vec3(texture2D(diffuse_texture, texCoord));    
    vec3 diffuse = light.specularColor * diff * vec3(texture2D(diffuse_texture, texCoord));
    vec3 specular = light.specularColor * spec * vec3(texture2D(diffuse_texture, texCoord));
    return ambientCol + diffuse + specular;
}

vec3 CalculatePointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    
    // Calculate diffuse
    float diff = max(dot(normal, lightDir), 0.0f);
    
    // Calculate specular
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0f), mat_shininess);
    
    // Attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0f / (light.constant + light.linear * distance + 
                                light.quadratic * (distance * distance));
    
    // Apply
    vec3 ambient = light.ambientColor * vec3(texture2D(diffuse_texture, texCoord));
    vec3 diffuse = light.diffuseColor * diff * vec3(texture2D(diffuse_texture, texCoord));
    vec3 specular = light.specularColor * spec * vec3(texture2D(diffuse_texture, texCoord));
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
}
