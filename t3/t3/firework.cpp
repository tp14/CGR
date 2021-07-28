// Global imports
#include <iostream>
#include <algorithm>
#include <numeric>
#include <GL/glut.h>
#include <GL/gl.h>

#include "firework.hpp"

using namespace std;

Firework::Firework(){
    this->color = {randomFloat(0, 255), randomFloat(0, 255), randomFloat(0, 255)};
    this->firework = Particle(randomFloat(-25, 25), 0, randomFloat(-25, 25), this->color);
}

bool Firework::done(){
    if (this->exploded && particles.empty())
    {
        return true;
    } else{
        return false;
    }
}

void Firework::run(){
    if (!exploded)
    {
        firework.applyForce({0.0, 0.02, 0.0});
        firework.run();
        if (firework.explode())
        {
            for (int i = 0; i < 30; i++)
            {
                particles.push_back(Particle(firework.location, this->color));
            }
            exploded = true;
        }

        for (int i = 0; i < firework.trail.size(); i++)
        {
          firework.trail[i].display();
        }
        
    }

    for (int i = particles.size()-1; i >= 0; i--) {
      Particle p = particles[i];
      p.applyForce({0.0, 0.01, 0.0});
      p.run();
      for (int i = 0; i < p.trail.size(); i++)
      {
        p.trail[i].display();
      }
      if (p.isDead()) {
        particles.erase(particles.begin() + i);
      } else{
        particles.erase(particles.begin() + i);
        particles.push_back(p);
      }
    }
}

bool Firework::dead() {
    if (particles.empty()) {
      return true;
    } else {
      return false;
    }
  }

