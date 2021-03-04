#include "agtgprectangle.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <sstream>
#include <vector>

int count = 0;
agtGpRectangle::agtGpRectangle(std::string name_c, agtTypPoint get_point1, agtTypPoint get_point2, agtTypPoint get_point3, agtTypPoint get_point4, agtTypColor get_rgb)
{
    this->point1 = get_point1;
    this->point2 = get_point2;
    this->point3 = get_point3;
    this->point4 = get_point4;
    this->rgb = get_rgb;
    this->name = name_c;
}

void agtGpRectangle::update(agtTypPoint get_point1, agtTypPoint get_point2, agtTypPoint get_point3, agtTypPoint get_point4, agtTypColor get_rgb)
{
    this->point1 = get_point1;
    this->point2 = get_point2;
    this->point3 = get_point3;
    this->point4 = get_point4;
    this->rgb = get_rgb;
}

void agtGpRectangle::draw()
{
    float vertices[] = {
            this->point1.x, this->point1.y, this->point1.z, this->rgb.r, this->rgb.g, this->rgb.b,
            this->point2.x, this->point2.y, this->point2.z, this->rgb.r, this->rgb.g, this->rgb.b,
            this->point3.x, this->point3.y, this->point3.z, this->rgb.r, this->rgb.g, this->rgb.b,
            this->point4.x, this->point4.y, this->point4.z, this->rgb.r, this->rgb.g, this->rgb.b
    };
    unsigned  vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    unsigned int vbo;

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glad_glLineWidth(2);
    glBindVertexArray(vao);
    glDrawArrays(GL_LINE_LOOP,0,4);

}

std::string agtGpRectangle::getName() { return this->name; }

std::vector<std::string> agtGpRectangle::split(const std::string s, char delimiter)
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

void agtGpRectangle::update(std::string message)
{
    // TODO

    if (split(message, '=')[0] == ("point.x1"))
    {
        this->point1.x += stof(split(message, '=')[1]);
        std::cout << "HATA\n";
    }
    else if(split(message, '=')[0] == ("point.y1"))
    {
        this->point1.y += stof(split(message, '=')[1]);
        std::cout << "HATA2\n";
    }
    else if(split(message, '=')[0] == ("point.x2"))
    {
        this->point2.x += stof(split(message, '=')[1]);
        std::cout << "HATA3\n";
    }
    else if(split(message, '=')[0] == ("point.y2"))
    {
        this->point2.y += stof(split(message, '=')[1]);
        std::cout << "HATA4\n";
    }
    else if(split(message, '=')[0] == ("point.x3"))
    {
        this->point3.x += stof(split(message, '=')[1]);
    }
    else if(split(message, '=')[0] == ("point.y3"))
    {
        this->point3.y += stof(split(message, '=')[1]);
    }
    else if(split(message, '=')[0] == ("point.x4"))
    {
        this->point4.x += stof(split(message, '=')[1]);
    }
    else
    {
        this->point4.y += stof(split(message, '=')[1]);
    }

}
