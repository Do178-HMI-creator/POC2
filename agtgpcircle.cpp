#include "agtgpcircle.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <string>
#include <iostream>

agtGpCircle::agtGpCircle(std::string name_c, agtTypPoint get_centerPoint, agtTypColor get_rgb, float r)
{
    this->centerPoint = get_centerPoint;
    this->rgb = get_rgb;
    this->r = r;
    this->name = name_c;
}

void agtGpCircle::update(agtTypPoint get_centerPoint, agtTypColor get_rgb, float r)
{
    this->centerPoint = get_centerPoint;
    this->rgb = get_rgb;
    this->r = r;
}

void agtGpCircle::draw()
{


    float vertices[360*6]={};
    int index = 0;
    for (int ii = 0; ii < 360; ii++)
    {

        float theta = 2.0f * 3.1415926f * float(ii) / float(360);     // get the current angle
        float x = this->r * cosf(theta);                                    // calculate the x component
        float y = this->r * sinf(theta);
        vertices[index] = x + this->centerPoint.x;
        vertices[index+1] = y + this->centerPoint.y;
        vertices[index+2] = this->centerPoint.z;
        vertices[index+3] = this->rgb.r;
        vertices[index+4] = this->rgb.g;
        vertices[index+5] = this->rgb.b;
        index += 6;

    }


    unsigned  vao3;
    glGenVertexArrays(1, &vao3);
    glBindVertexArray(vao3);

    unsigned int vbo3;

    glGenBuffers(1, &vbo3);
    glBindBuffer(GL_ARRAY_BUFFER, vbo3);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glad_glLineWidth(2);
    glBindVertexArray(vao3);
    glDrawArrays(GL_LINE_LOOP,0,360);

}

std::string agtGpCircle::getName() { return this->name; }

void agtGpCircle::update(std::string message)
{
    // TODO
}
