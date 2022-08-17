#include "include/common.h"
#include "include/settings.h"
#include "include/particles.h"
#include "include/render.h"
#include <SFML/Window/Keyboard.hpp>

int main()
{
        sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Particles");
        sf::ContextSettings settings;
        sf::RectangleShape ballon(sf::Vector2f(BALLON_WIDTH, BALLON_HEIGHT));
        particle_t particles[MAX_NUM_OF_PARTICLES];
        sf::Clock clock;

        int num_of_particles = 1;

        init_frame(&settings, &window, &ballon);
        set_particles(particles);

        while (window.isOpen()) {
                sf::Event event;
                while (window.pollEvent(event)) {
                        if (event.type == sf::Event::Closed)
                                window.close();
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
                                && num_of_particles < MAX_NUM_OF_PARTICLES)
                                num_of_particles++;
                        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
                                && num_of_particles > 0)
                                num_of_particles--;
                }

                sf::Time elapsed = clock.restart();

                move_balls(particles, &ballon, &elapsed, num_of_particles);

                draw_frame(&window, particles, &ballon, num_of_particles);
        }

        return 0;
}

