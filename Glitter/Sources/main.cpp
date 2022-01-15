// Local Headers
#define STB_IMAGE_IMPLEMENTATION
#include "glitter.hpp"
#include "ShaderHelpers.h"
#include "ModelLoader.h"

// System Headers
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Standard Headers
#include <cstdio>
#include <cstdlib>
#include <iostream>


int main(int argc, char * argv[]) {
    
    
    
    // Load GLFW and Create a Window
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
    
    auto mWindow = glfwCreateWindow(mWidth, mHeight, "Lab 2", nullptr, nullptr);
    
    // Check for Valid Context
    if (mWindow == nullptr) {
        fprintf(stderr, "Failed to Create OpenGL Context");
        return EXIT_FAILURE;
    }
    
    // Create Context and Load OpenGL Functions
    glfwMakeContextCurrent(mWindow);
    gladLoadGL();
    fprintf(stderr, "OpenGL %s\n", glGetString(GL_VERSION));
    
    glEnable(GL_DEPTH_TEST);
    
    
    // MARK: Import my shader code
    GLuint myShader = LoadProgram("/Users/gabrieljreed/Glitter/Glitter/Shaders/basic.vert", "/Users/gabrieljreed/Glitter/Glitter/Shaders/basic.frag");
    
    
    
    // **************************************
    // Setup Vertex arrays here
    // **************************************
    
    // Create VAO
    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    // Bind VAO
    glBindVertexArray(VAO);
    
    // Create VBO
    GLuint VBO;
    glGenBuffers(1, &VBO);
    // Bind VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    float verts[] = {
        -0.2f, 0.0f, 0.0f,
        0.0f,  0.3f, 0.0f,
        0.2f, 0.0f, 0.0f,
        0.2f, -0.3f, 0.0f,
        -0.2f, -0.3f, 0.0f,
        -0.2f, 0.0f, 0.0f,
    };
    
    glBufferData(GL_ARRAY_BUFFER,
                 sizeof(verts),
                 verts,
                 GL_STATIC_DRAW);
    
    // Connect vertex data to shader
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    
    glEnableVertexAttribArray(0);
    
    // **************************************
    
    // Rendering Loop
    while (glfwWindowShouldClose(mWindow) == false) {
        if (glfwGetKey(mWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(mWindow, true);
        
        // Background Fill Color
        glClearColor(1.0f, 0.25f, 0.25f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        // **********************************
        // Add rendering code here
        
        glUseProgram(myShader);
        glBindVertexArray(VAO); // Bind VAO
        glDrawArrays(GL_TRIANGLE_FAN, 0, 6);
        glBindVertexArray(0); // Unvind VAO - you don't have to do these steps here because there's only one VAO
        
        // **********************************
        
        // Flip Buffers and Draw
        glfwSwapBuffers(mWindow);
        glfwPollEvents();
    }   glfwTerminate();
    
    return EXIT_SUCCESS;
}
