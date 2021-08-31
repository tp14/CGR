// Global imports
#include <iostream>
#include <algorithm>
#include <numeric>
#include <GL/glut.h>
#include <GL/gl.h>

#include "particle.hpp"


Particle::Particle(double x, double y, double z, vector<double> color)
{
    this->color = color;
    this->acceleration = {0, 0, 0};
    this->velocity = {0, randomFloat(-1, -0.5), 0};
    this->location = {x, y, z};
    this->initial = true;
    this->lifespan = 255.0;
}

Particle::Particle(vector<double> location, vector<double> color)
{
    this->color = color;
    this->acceleration = {0, 0, 0};
    this->velocity = {randomFloat(-0.5, 0.5), randomFloat(-0.5, 0.5), randomFloat(-0.5, 0.5)};
    // multVector(&this->velocity, randomFloat(8, 16));
    this->location = location;
    this->initial = false;
    this->lifespan = 255.0;
}

void Particle::applyForce(vector<double> force)
{
    addVector(&this->acceleration, &force);
}

void Particle::run()
{
    Particle::update();
    Particle::display();
}

bool Particle::explode()
{
    if (this->initial && this->velocity[1] >= 0)
    {
        this->lifespan = 0;
        return true;
    }
    return false;
}

Particle Particle::update()
{
    Particle p = Particle();
    p.location = this->location;
    p.color = this->color;
    p.lifespan = this->lifespan*0.5;
    this->trail.push_back(p);
    

    if (trail.size() > 5)
    {
        trail.erase(trail.begin());
    }

    addVector(&this->velocity, &this->acceleration);
    addVector(&this->location, &this->velocity);
    if (!this->initial)
    {
        this->lifespan -= 8;
        multVector(&this->velocity, 0.8);
    }
    multVector(&this->acceleration, 0);
    return *this;
}

void Particle::display()
{
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glColor4f(this->color[0] / 255.0f, this->color[1] / 255.0f, this->color[2] / 255.0f, this->lifespan / 255.0f);
    glPointSize(1);
    glBegin(GL_POINTS);
    glVertex3f(this->location[0], this->location[1], this->location[2]);
}

bool Particle::isDead()
{
    if (this->lifespan < 0.0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
