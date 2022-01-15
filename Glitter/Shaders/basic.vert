#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 vColor;

out vec3 color;

uniform mat4 M; // Uniform transform matrix
uniform vec3 colorMask; // Uniform color mask

void main()
{
    gl_Position = M * vec4(aPos.x, aPos.y, aPos.z, 1.0);
    color = colorMask * vColor;
}
