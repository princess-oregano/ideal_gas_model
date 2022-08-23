#ifndef RENDER_H
#define RENDER_H

#include "common.h"

// Draws window and contents.
void draw_frame(sf::RenderWindow *window, const particle_t *particles,
                const sf::RectangleShape *ballon, const int num_of_particles);

#endif // RENDER_H

