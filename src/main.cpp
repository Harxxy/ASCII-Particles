#include "particle.h"
#include <string>
#include <iostream>
#include <thread>
#include <chrono>
using std::string;
using std::vector;
using std::cout;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

void clearScreen() {
    std::cout << "\x1B[H"; // move cursor home, don't erase
}

void draw(const std::vector<Particle>& particles, int width, int height) {
    std::vector<std::string> grid(height, std::string(width, ' '));
    for (const auto& p : particles) {
        int ix = (int)p.x, iy = (int)p.y;
        if (ix >= 0 && ix < width && iy >= 0 && iy < height)
            grid[iy][ix] = p.symbol;
    }

    std::string frame = "\x1B[H";
    for (auto& row : grid) {
        frame += row;
        frame += "\n";
    }
    std::cout << frame << std::flush;
}

int main() {
    std::vector<Particle> particles = {
        {10.0f,  10.0f,  2.0f,  0.0f, '*'},   // moving right
        {20.0f, 4.0f,  0.0f,  2.0f, 'o'},   // moving down
        {40.0f, 20.0f, -2.0f, -1.0f, '#'},  // moving up-left
        {30.0f, 30.0f, 1.0f,  -2.0f, 'o'},  // moving up-right, slow
        {60.0f, 16.0f,  -0.6f, 0.6f, '#'},   // slow diagonal drift
    };
    while (true) {
        clearScreen();
        Update(particles, 0.1f);
        draw(particles, 80, 40);
        sleep_for(milliseconds(40));
    }
    return 0;
}