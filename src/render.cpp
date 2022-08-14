#include "include/render.h"

void draw_frame(sf::RenderWindow *window, sf::CircleShape *ball,
                sf::RectangleShape *ballon)
{
        window->clear(sf::Color DARK_BLUE);
        window->draw(*ballon);
        for (int count = 0; count < NUM_OF_PARTICLES; count++)
                window->draw(ball[count]);
        window->display();
}

