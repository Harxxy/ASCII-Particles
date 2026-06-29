#include "particle.h"
#include <string>
#include <iostream>
using std::string;
using std::vector;
using std::cout;

void draw(const vector<Particle>& particles, int width, int height){
    vector<string> grid(height, string(width, ' '));
    for (const auto& p : particles){
        int ix = (int)p.x, iy = (int)p.y;
        if (ix >= 0 && ix < width && iy >= 0 && iy < height) {
            grid[iy][ix] = p.symbol;
        }
    }
    for (auto& row : grid){
        cout << row << "\n";
    }
}

int main() {
    vector<Particle> particles;
    return 0;
}