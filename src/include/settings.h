#ifndef SETTINGS_H
#define SETTINGS_H

#include <stdlib.h>
#include "common.h"

// Creates initial settings.
void make_settings(sf::ContextSettings *settings, sf::RenderWindow *window,
                   particle_t *particles, sf::RectangleShape *ballon);

#endif // SETTINGS_H

