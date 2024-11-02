#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>

void framebuffer_callback_function(GLFWwindow* , int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    glfwInit();
    //initialization
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    int Swidth = 800 ,Sheight = 600;

    //creating window object
    GLFWwindow* window = glfwCreateWindow(Swidth, Sheight, "LearnOpenGL", NULL ,NULL );
    if(window == NULL ){
        std::cout<<"failed to create"<<std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);



    // => these are `glfw` functions => no need to initialize GLAD before this.
    // initializing GLAD
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout<<"couldnt initalize GLAD"<<std::endl;
        return -1;
    }
    //setting viewport
    glViewport(0, 0, 800, 600); //=> this a openGL function => need to initialize GLAD for this.
    glfwSetFramebufferSizeCallback(window,  framebuffer_callback_function);

    while(!glfwWindowShouldClose(window)){
        glfwSwapBuffers(window);
        glfwPollEvents();

    }
    glfwTerminate();

    return 0;

}
