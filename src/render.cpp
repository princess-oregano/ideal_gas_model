#include "include/render.h"

void draw_frame(sf::RenderWindow *window, particle_t *particles,
                const sf::RectangleShape *ballon, const int num_of_particles)
{
        assert(window);
        assert(particles);
        assert(ballon);

        window->clear(sf::Color(DARK_BLUE));
        window->draw(*ballon);
        for (int count = 0; count < num_of_particles; count++) {
                particles[count].ball.setPosition(particles[count].position);
                window->draw(particles[count].ball);
        }
        window->display();
}

