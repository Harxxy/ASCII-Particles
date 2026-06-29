#include "particle.h"
using std::vector;

void Update(vector<Particle>& particles, float dt) {
    for (auto& p : particles) {
        p.x += p.vx * dt;
        p.y += p.vy * dt;
    }
} 