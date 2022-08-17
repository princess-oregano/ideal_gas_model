#include "include/render.h"

void draw_frame(sf::RenderWindow *window, sf::CircleShape *ball,
                sf::RectangleShape *ballon, int num_of_particles)
{
        window->clear(sf::Color(DARK_BLUE));
        window->draw(*ballon);
        for (int count = 0; count < num_of_particles; count++)
                window->draw(ball[count]);
        window->display();
}

