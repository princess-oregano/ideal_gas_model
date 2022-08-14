#ifndef SETTINGS_H
#define SETTINGS_H

#include <stdlib.h>
#include "common.h"

// Creates initial settings.
void make_settings(sf::ContextSettings *settings, sf::RenderWindow *window,
                   sf::CircleShape *ball, sf::Vector2f *velocity,
                   sf::RectangleShape *ballon);

#endif // SETTINGS_H

