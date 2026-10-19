#version 330 core
layout (location = 0) in vec3 aPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

uniform float t;

void main()
{
    gl_Position = proj * view * model *
        vec4(aPos.x - sin(t), aPos.y + sin(t), aPos.z - sin(t), 1.0);
}