#version 330 core
layout (location = 0) in vec3 aPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

uniform float t;

vec4 calculatePerspective(vec3 position) {
    return proj * view * model * vec4(position, 1.0);
}

void main()
{
    vec3 animatedPos = aPos - vec3(sin(t));

    gl_Position = calculatePerspective(animatedPos);
}