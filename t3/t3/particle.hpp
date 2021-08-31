#pragma once

#include <cstdlib>
#include <vector>

#include "functions.hpp"

using namespace std;

class Particle
{
    public:
        Particle(double, double, double, vector<double>);
        Particle(vector<double>, vector<double>);
        Particle() = default;
        void applyForce(vector<double>);
        void run();
        Particle update();
        void display();
        bool explode();
        bool isDead();
        vector<double> location; 
        float lifespan;
        vector<Particle> trail;
    private:
        vector<double> velocity;
        vector<double> acceleration;
        vector<double> color;
        bool initial = false;
        
};
