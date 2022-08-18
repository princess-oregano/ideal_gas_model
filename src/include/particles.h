#ifndef PARTICLES_H
#define PARTICLES_H

#include "common.h"
#include <math.h>
#include <stdio.h>

const int LOWER_WALL = (WINDOW_HEIGHT + BALLON_HEIGHT) / 2;
const int UPPER_WALL = (WINDOW_HEIGHT - BALLON_HEIGHT) / 2;
const int  LEFT_WALL = (WINDOW_WIDTH - BALLON_WIDTH) / 2;
const int RIGHT_WALL = (WINDOW_WIDTH + BALLON_WIDTH) / 2;

// Moves a ball.
void move_balls(particle_t *particles, sf::Time *elapsed, int num_of_particles);
// Detects and manages collisions between ballon and balls.
void collide_walls(particle_t *particles, sf::Vector2f *new_pos, int count);
// Detects and manages collisions between balls.
void collide_balls(particle_t *particles, sf::Time *elapsed,
                   int count, int num_of_particles);
// Detects collisions of particles.
bool detect_collision(sf::CircleShape *ball1, sf::CircleShape *ball2);
// Changes velocities of particles in case of collision.
void swap_velocity(sf::Vector2f *velocity1, sf::Vector2f *velocity2);

#endif // PARTICLES_H

