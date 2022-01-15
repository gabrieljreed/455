#version 330 core
layout (location = 0) in vec3 aPos;
// layout (location = 1) in vec4 vColor;

uniform mat4 M; // Uniform transform matrix

void main()
{
    gl_Position = M * vec4(aPos.x, aPos.y, aPos.z, 1.0);
    // gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    // color = vColor;
}
