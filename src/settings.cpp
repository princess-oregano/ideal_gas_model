#include "include/settings.h"

void init_frame(sf::ContextSettings *settings, sf::RenderWindow *window,
                sf::RectangleShape *ballon)
{
        assert(settings);
        assert(window);
        assert(ballon);

        settings->antialiasingLevel = 12;

        window->setVerticalSyncEnabled(true);

        ballon->setFillColor(sf::Color(DARK_BLUE));
        ballon->setOrigin((float) BALLON_WIDTH / 2, (float) BALLON_HEIGHT / 2);
        ballon->setPosition((float) WINDOW_WIDTH / 2, (float) WINDOW_HEIGHT / 2);
        ballon->setOutlineThickness(BALLON_THICKNESS);
        ballon->setOutlineColor(sf::Color(PURPLE));
}

void set_particles(particle_t *particles)
{
        assert(particles);

        srand(time(NULL));
        for (int count = 0; count < MAX_NUM_OF_PARTICLES; count++) {
                particles[count].ball.setRadius(PARTICLE_RADIUS);
                particles[count].ball.setFillColor(sf::Color(PINK));
                particles[count].ball.setOrigin(particles[count].ball.getRadius(),
                                                particles[count].ball.getRadius());
                particles[count].ball.setPosition((float) WINDOW_WIDTH / 2, (float) WINDOW_HEIGHT / 2);

                particles[count].velocity.x = (rand() % 1000 - 500);
                particles[count].velocity.y = (rand() % 1000 - 500);
        }
}

