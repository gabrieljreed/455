#version 330 core
in vec3 color;
out vec4 ColorOut;

// Input color mask (uniform, vector)
uniform vec3 colorMask;

void main()
{
    // Multiply color by color mask before output 
    // ColorOut = color * colorMask;
    ColorOut = vec4(color, 1.0f);
}
