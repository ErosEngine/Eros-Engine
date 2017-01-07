#version 430



struct Material
{
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
};


// --- Light definitions --- //
struct DirectionalLight
{
    bool castShadows;
    vec3 direction;
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
// ---- End Lights ---- //

uniform Material uniMaterial;
uniform vec3 uniViewPos;

in vec2 vsOutTexCoords;
in vec3 vsOutNormal;
in vec3 vsOutViewPos;
in vec3 vsOutFragPos;

out vec4 fsOutColor;


vec3 CalculateDirLight(DirectionalLight light, vec3 normal, vec3 viewDir);
vec3 CalculatePointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

void main()
{
    vec3 dir = normalize(uniViewPos - vsOutFragPos);
    vec3 norm = normalize(vsOutNormal);
    
    // Not adding lights just yet
    fsOutColor = vec4(0.3f, 0.5f, 0.2f, 1.0f);
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
    float spec = (pow(max(dot(viewDir, reflectionDir), 0.0f), uniMaterial.shininess));
    
    // Combine results
    vec3 ambientCol = light.ambientColor * vec3(texture2D(uniMaterial.diffuse, vsOutTexCoords));    
    vec3 diffuse = light.specularColor * diff * vec3(texture2D(uniMaterial.diffuse, vsOutTexCoords));
    vec3 specular = light.specularColor * spec * vec3(texture2D(uniMaterial.specular, vsOutTexCoords));
    return ambientCol + diffuse + specular;
}

vec3 CalculatePointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    
    // Calculate diffuse
    float diff = max(dot(normal, lightDir), 0.0f);
    
    // Calculate specular
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0f), uniMaterial.shininess);
    
    // Attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0f / (light.constant + light.linear * distance + 
                                light.quadratic * (distance * distance));
    
    // Apply
    vec3 ambient = light.ambientColor * vec3(texture2D(uniMaterial.diffuse, vsOutTexCoords));
    vec3 diffuse = light.diffuseColor * diff * vec3(texture2D(uniMaterial.diffuse, vsOutTexCoords));
    vec3 specular = light.specularColor * spec * vec3(texture2D(uniMaterial.specular, vsOutTexCoords));
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
}
