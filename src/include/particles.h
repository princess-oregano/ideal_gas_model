#ifndef PARTICLES_H
#define PARTICLES_H

#include "common.h"
#include <math.h>
#include <stdio.h>

enum wall {
        LOWER = 0,
        UPPER = 1,
        LEFT  = 2,
        RIGHT = 3,
};

// Calculates coordinates of ballon walls.
int find_wall(wall wall, sf::RectangleShape *ballon);
// Moves a ball.
void move_balls(sf::CircleShape *ball, sf::RectangleShape *ballon,
               sf::Vector2f *velocity, sf::Time *elapsed,
               int num_of_particles);
// Detects collisions of particles.
bool detect_collision(sf::CircleShape *ball1, sf::CircleShape *ball2);
// Changes velocities of particles in case of collision.
void change_velocity(sf::Vector2f *velocity1, sf::Vector2f *velocity2);

#endif // PARTICLES_H

