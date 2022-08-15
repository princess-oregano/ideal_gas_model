#ifndef RENDER_H
#define RENDER_H

#include "common.h"

// Draws window and contents.
void draw_frame(sf::RenderWindow *window, sf::CircleShape *ball,
                sf::RectangleShape *ballon, int num_of_particles);

#endif // RENDER_H

