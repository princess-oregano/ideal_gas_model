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
void move_particles(particle_t *particles, const sf::Time elapsed, const int num_of_particles);

#endif // PARTICLES_H

