#ifndef SETTINGS_H
#define SETTINGS_H

#include <stdlib.h>
#include "common.h"

// Makes initial frame settings.
void init_frame(sf::ContextSettings *settings, sf::RenderWindow *window,
                sf::RectangleShape *ballon);
// Initializes array of particle_t structures.
void set_particles(particle_t *particles);

#endif // SETTINGS_H

