#ifndef RENDER_H
#define RENDER_H

#include "common.h"

// Draws window and contents.
void draw_frame(sf::RenderWindow *window, particle_t *particles,
                sf::RectangleShape *ballon, int num_of_particles);

#endif // RENDER_H

