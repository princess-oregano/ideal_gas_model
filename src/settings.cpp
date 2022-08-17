#include "include/settings.h"

void make_settings(sf::ContextSettings *settings, sf::RenderWindow *window,
                   sf::CircleShape *ball, sf::Vector2f *velocity,
                   sf::RectangleShape *ballon)
{
        settings->antialiasingLevel = 12;

        window->setVerticalSyncEnabled(true);

        ballon->setFillColor(sf::Color(DARK_BLUE));
        ballon->setOrigin((float) BALLON_WIDTH / 2, (float) BALLON_HEIGHT / 2);
        ballon->setPosition((float) WINDOW_WIDTH / 2, (float) WINDOW_HEIGHT / 2);
        ballon->setOutlineThickness(BALLON_THICKNESS);
        ballon->setOutlineColor(sf::Color(PURPLE));

        srand(time(NULL));
        for (int count = 0; count < MAX_NUM_OF_PARTICLES; count++) {
                ball[count].setRadius(RADIUS);
                ball[count].setFillColor(sf::Color(PINK));
                ball[count].setOrigin(ball->getRadius(), ball->getRadius());
                ball[count].setPosition((float) WINDOW_WIDTH / 2, (float) WINDOW_HEIGHT / 2);

                velocity[count].x = (rand() % 1000 - 500);
                velocity[count].y = (rand() % 1000 - 500);
        }
}

