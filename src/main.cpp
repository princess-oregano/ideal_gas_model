#include "include/common.h"
#include "include/settings.h"
#include "include/particles.h"
#include "include/render.h"

int main()
{
        sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Particles");
        sf::ContextSettings settings;
        sf::RectangleShape ballon(sf::Vector2f(BALLON_WIDTH, BALLON_HEIGHT));
        sf::CircleShape ball[NUM_OF_PARTICLES];
        sf::Vector2f velocity[NUM_OF_PARTICLES];
        sf::Clock clock;

        make_settings(&settings, &window, ball, velocity, &ballon);

        while (window.isOpen()) {
                sf::Event event;
                while (window.pollEvent(event)) {
                        if (event.type == sf::Event::Closed)
                                window.close();
                }

                sf::Time elapsed = clock.restart();

                move_balls(ball, &ballon, velocity, &elapsed);

                draw_frame(&window, ball, &ballon);
        }

        return 0;
}

