#include "agtgpdot.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <sstream>
#include <vector>

agtGpDot::agtGpDot(std::string name_c, agtTypPoint get_point, agtTypColor get_rgb)
{
    this->point = get_point;
    this->rgb = get_rgb;
    this->name = name_c;
}

void agtGpDot::update(agtTypPoint get_point, agtTypColor get_rgb)
{
    this->point = get_point;
    this->rgb = get_rgb;
}

std::vector<std::string> agtGpDot::split(const std::string s, char delimiter)
{
    /*std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;*/
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    std::getline(tokenStream, token, delimiter);
    tokens.push_back(token);
    std::getline(tokenStream, token, '\0');
    tokens.push_back(token);
    return tokens;
}

void agtGpDot::update(std::string message)
{

    if (split(message, '=')[0] == ("point.xc"))
    {
        this->point.x = stof(split(message, '=')[1]);

    }
    else if(split(message, '=')[0] == ("point.yc"))
    {
        this->point.y = stof(split(message, '=')[1]);
    }
    else if (split(message, '=')[0] == ("point.x"))
    {
        this->point.x += stof(split(message, '=')[1]);

    }
    else
    {
        this->point.y += stof(split(message, '=')[1]);
    }

}

std::string agtGpDot::getName() { return this->name; }

void agtGpDot::draw()
{
    float vertices[] = {
            this->point.x, this->point.y, this->point.z, this->rgb.r, this->rgb.g, this->rgb.b

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

    glad_glPointSize(13);
    glBindVertexArray(vao3);
    glDrawArrays(GL_POINTS,0,1);
}
