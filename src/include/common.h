#ifndef COMMON_H
#define COMMON_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <stdio.h>
#include <assert.h>

struct particle_t {
        sf::CircleShape ball {};
        sf::Vector2f velocity {};
};

const float PARTICLE_RADIUS    = 20;
const int MAX_NUM_OF_PARTICLES = 15;
const int WINDOW_WIDTH        = 800;
const int WINDOW_HEIGHT       = 600;
const int BALLON_WIDTH        = 300;
const int BALLON_HEIGHT       = 500;
const int BALLON_THICKNESS      = 4;
const sf::Color PURPLE(176, 38, 255);
const sf::Color DARK_BLUE(11,  11,  69);
const sf::Color PINK(255, 16, 240);

#endif // COMMON_H

