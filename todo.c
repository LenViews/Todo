#include <GLFW/glfw3.h>
#include <stdio.h>

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }

    // Create a GLFW windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(1280, 780, "Todo", NULL, NULL);
    if (!window) {
        glfwTerminate();
        fprintf(stderr, "Failed to create GLFW window\n");
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    
    // Set the clear color (only needed once if it doesn't change)
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // Full alpha (1.0f)

    // Main rendering loop
    while (!glfwWindowShouldClose(window)) {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);

        // Poll events (use glfwWaitEvents() if waiting for events is preferred)
        glfwPollEvents();

        // Swap buffers
        glfwSwapBuffers(window);
    }

    // Cleanup and terminate
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

