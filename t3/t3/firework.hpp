#pragma once

#include <cstdlib>
#include <vector>

#include "particle.hpp"


using namespace std;

class Firework
{
    public:
        Firework();
        bool done();
        void run();
        bool dead();
        Particle firework;
        vector<Particle> particles;

    private:
        vector<double> color;
        bool exploded = false;

        
};
