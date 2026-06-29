#pragma once
#include <vector>
using std::vector;

struct Particle {
    float x, y;       // position
    float vx, vy;      // velocity
    char symbol;        // what character represents it on screen
};

void Update(vector<Particle>& particles, float dt);