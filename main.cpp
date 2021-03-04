#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <thread>
#include <iostream>

#include "agtgpline.h"
#include "agtTypPoint.h"
#include "agtTypColor.h"
#include "agtgprectangle.h"
#include "agtgpdot.h"
#include "agtgpcircle.h"
#include "agtmessagebroker.h"
#include "agtobjecttree.h"
#include "tree.h"

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 900;

unsigned int shader_program;


const char* vertex_shader_source =""
        "#version 330 core\n"
        "layout (location = 0) in vec3 position;\n"
        "layout (location = 1) in vec3 color;\n"
        "out vec3 vertexColor;\n"
        "void main()\n"
        "{\n"
        "    gl_Position = vec4(position, 1.0);\n"
        "    vertexColor = color;\n"
        "}\n";

const char* fragment_shader_source =
        "#version 330 core\n"
        "out vec4 fragColor;\n"
        "in vec3 vertexColor;\n"
        "void main()\n"
        "{\n"
        "     fragColor = vec4(vertexColor, 1.0f);\n"
        "}\n";

agtObjectTree myTree = agtObjectTree();

agtTypPoint p1(-0.4, -0.3, 0.0);
agtTypPoint p2(0.4, -0.3, 0.0);
agtTypPoint p3(0.4,  0.3, 0.0);
agtTypPoint p4(-0.4, 0.3,  0.0);
agtTypPoint p5(0.4, -0.3, 0.0);
agtTypPoint p6(0.1, - 0.9, 0.0);
agtTypPoint p7(0.0, 0.0, 0.0);
agtTypPoint p8(0.0, 0.5, 0.0);
agtTypPoint p9(0.0, -0.5, 0.0);

agtTypColor rgb(1.0, 0.0, 0.0);
agtTypColor rgb2(0.9, 0.5,0.8);
agtTypColor rgb3(0.0, 0.0, 1.0);
agtTypColor rgb4(1.0, 1.0, 0.0);
agtTypColor rgb5(1.0, 0.0, 1.0);
agtTypColor rgb6(0.0, 1.0, 1.0);
agtTypColor rgb7(1.0, 1.0, 1.0);
agtTypColor rgb8(0.8, 1.0, 0.0);



agtGpDot my_agtGpDot("my_agtGpDot",p7,rgb7);
agtGpDot my_agtGpDot1("my_agtGpDot1",p1,rgb);
agtGpDot my_agtGpDot2("my_agtGpDot2",p2,rgb2);
agtGpDot my_agtGpDot3("my_agtGpDot3",p3,rgb3);
agtGpDot my_agtGpDot4("my_agtGpDot4",p4,rgb4);
agtGpDot my_agtGpDot5("my_agtGpDot5",p7,rgb5);
agtGpDot my_agtGpDot6("my_agtGpDot6",p8,rgb8);
agtGpDot my_agtGpDot7("my_agtGpDot7",p9,rgb8);

agtGpLine my_agtGpLine("my_agtGpLine",p8,p9,rgb6);
agtGpRectangle my_agtGpRectangle("my_agtGpRectangle", p1, p2 ,p3 ,p4 ,rgb);
agtGpCircle my_agtGpCircle("my_agtGpCircle", p7, rgb2,0.5);

void myinit()
{
    myTree.insert("root", &my_agtGpCircle);
    myTree.insert("root", &my_agtGpLine);

    myTree.insert("root", &my_agtGpRectangle);
    myTree.insert("root", &my_agtGpDot);
    myTree.insert("root", &my_agtGpDot1);
    myTree.insert("root", &my_agtGpDot2);
    myTree.insert("root", &my_agtGpDot3);
    myTree.insert("root", &my_agtGpDot4);
    myTree.insert("root", &my_agtGpDot5);
    myTree.insert("root", &my_agtGpDot6);
    myTree.insert("root", &my_agtGpDot7);
}

void setup_shader()
{
    unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
    glCompileShader(vertex_shader);

    unsigned int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
    glCompileShader(fragment_shader);

    shader_program = glCreateProgram();
    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
}
void MessageBroker() { agtMessageBroker myBroker; }

void display(GLFWwindow* window)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shader_program);
    my_agtGpCircle.draw();
    my_agtGpLine.draw();
    my_agtGpRectangle.draw();

    my_agtGpDot.draw();
    my_agtGpDot1.draw();
    my_agtGpDot2.draw();
    my_agtGpDot3.draw();
    my_agtGpDot4.draw();
    my_agtGpDot5.draw();
    my_agtGpDot6.draw();
    my_agtGpDot7.draw();

    glfwSwapBuffers(window);
    glfwPollEvents();
}


int main(void)
{

    std::thread Broker(MessageBroker);
    Broker.detach();

    GLFWwindow* window;

    if ( ! glfwInit() )
    {
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Proof of Concept Program", NULL, 0);
    myinit();
    if ( ! window )
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if ( ! gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) )
    {
        glfwTerminate();
        return -1;
    }

    setup_shader();


    while ( ! glfwWindowShouldClose(window) )
    {

        display(window);
        tree<agtGraphicPrimitiveIfc *>::iterator begin = myTree.obj_tree.begin();
        tree<agtGraphicPrimitiveIfc *>::iterator end = myTree.obj_tree.end();

        while (begin != end)
        {
            (*begin)->draw();
            ++begin;
        }

        
    }

    glfwTerminate();

    return 0;
}