#version 330 core

struct Material
{
     vec3 ambient;
     vec3 diffuse;
     vec3 specular;
     float shininess;
};

struct Light
{
     vec3 position;

     vec3 ambient;
     vec3 diffuse;
     vec3 specular;
};

out vec4 FragColor;

in vec2 TexCoords;
in vec3 Normals;
in vec3 FragPos;

uniform vec3 lightPos;
uniform vec3 viewPos;

uniform Light light;
uniform Material material;

uniform sampler2D texture_diffuse1;

void main()
{
//     vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);

     // ambient
     vec3 ambient = light.ambient * material.ambient;

     // diffuse
     vec3 norm = normalize(Normals);
     vec3 lightDir = normalize(light.position - FragPos);
     float diff = max(dot(norm, lightDir), 0.0);
     vec3 diffuse = light.diffuse * (diff * material.diffuse);

     // specular
     float specularStrength = 0.5f;
     vec3 viewDir = normalize(viewPos - FragPos);
     vec3 reflectDir = reflect(-lightDir, norm);
     float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
     vec3 specular = light.specular * (spec * material.specular);

     vec3 result = ambient + diffuse + specular;

     FragColor = vec4(result, 1.0f) * texture(texture_diffuse1, TexCoords);
}