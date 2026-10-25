#version 330 core
out vec4 FragColor;

in vec3 normal;
in vec3 currentPosition;

uniform vec4 lightColor;
uniform vec3 lightPosition;
uniform vec3 viewPosition;

void main()
{
   vec3 norm = normalize(normal);
   vec3 lightDir = normalize(lightPosition - currentPosition);

   float diff = max(dot(norm, lightDir), 0.0);
   vec3 diffuse = diff * vec3(lightColor);

   FragColor = vec4(diffuse, 1.0);
}