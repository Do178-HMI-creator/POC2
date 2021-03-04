#include "agtgpline.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <sstream>
#include <vector>

agtGpLine::agtGpLine(std::string name_c, agtTypPoint get_point1, agtTypPoint get_point2, agtTypColor get_rgb)
{
    this->point1 = get_point1;
    this->point2 = get_point2;
    this->rgb = get_rgb;
    this->name = name_c;
}

void agtGpLine::update(agtTypPoint get_point1, agtTypPoint get_point2, agtTypColor get_rgb)
{
    this->point1 = get_point1;
    this->point2 = get_point2;
    this->rgb = get_rgb;
}

void agtGpLine::draw()
{
    float vertices[] = {
            this->point1.x, this->point1.y, this->point1.z, this->rgb.r, this->rgb.g, this->rgb.b,
            this->point2.x, this->point2.y, this->point2.z, this->rgb.r, this->rgb.g, this->rgb.b
    };
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
    glDrawArrays(GL_LINES,0,2);
}
std::string agtGpLine::getName() { return this->name; }
std::vector<std::string> agtGpLine::split(const std::string s, char delimiter)
{

    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    std::getline(tokenStream, token, delimiter);
    tokens.push_back(token);
    std::getline(tokenStream, token, '\0');
    tokens.push_back(token);
    return tokens;
}

void agtGpLine::update(std::string message)
{

    if (split(message, '=')[0] == ("point.x"))
    {
        this->point1.x = stof(split(message, '=')[1]);

    }
    else if(split(message, '=')[0] == ("point.y"))
    {
        this->point1.y = stof(split(message, '=')[1]);
    }
    else
        {

        }
}
