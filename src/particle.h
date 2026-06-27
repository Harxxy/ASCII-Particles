#pragma once
#include <vector>

struct Particle {
    float x, y;       // position
    float vx, vy;      // velocity
    char symbol;        // what character represents it on screen
};

void update(std::vector<Particle>& particles, float dt);