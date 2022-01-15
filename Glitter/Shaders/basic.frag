#version 330 core
in vec4 color; // FIXME: How do you pass something in here?
out vec4 ColorOut;

// Input color mask (uniform, vector)
uniform vec3 colorMask;

void main()
{
    // Multiply color by color mask before output 
    // ColorOut = color * colorMask;
    ColorOut = vec4(1.0f, 1.0f, 1.0f, 1.0f);
}
