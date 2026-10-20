#version 330 core
layout (location = 0) in vec3 aPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

vec4 calculatePerspective(vec3 position) {
   return proj * view * model * vec4(position, 1.0);
}

void main()
{
   gl_Position = calculatePerspective(aPos);
}