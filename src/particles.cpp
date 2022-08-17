#include "include/particles.h"

void move_balls(sf::CircleShape *ball, sf::RectangleShape *ballon,
                sf::Vector2f *velocity, sf::Time *elapsed,
                int num_of_particles)
{
        for (int count = 0; count < num_of_particles; count++) {
                sf::Vector2f pos = ball[count].getPosition();
                sf::Vector2f new_pos(pos.x + velocity[count].x * elapsed->asSeconds(),
                                     pos.y + velocity[count].y * elapsed->asSeconds());

                if (new_pos.x - RADIUS < LEFT_WALL) {
                        velocity[count].x *= -1;
                        new_pos.x = LEFT_WALL + RADIUS;
                } else if (new_pos.x + RADIUS >= RIGHT_WALL) {
                        velocity[count].x *= -1;
                        new_pos.x = RIGHT_WALL - RADIUS;
                } else if (new_pos.y - RADIUS < UPPER_WALL) {
                        velocity[count].y *= -1;
                        new_pos.y = UPPER_WALL + RADIUS;
                } else if (new_pos.y + RADIUS >= LOWER_WALL) {
                        velocity[count].y *= -1;
                        new_pos.y = LOWER_WALL - RADIUS;
                }

                static int num_of_collisions = 0;
                for (int i = count + 1; i < num_of_particles; i++)
                        if (detect_collision(&ball[count], &ball[i])) {
                                num_of_collisions++;
                                fprintf(stderr, "Collision %d.\n", num_of_collisions);

                                swap_velocity(&velocity[count], &velocity[i]);

                                sf::Vector2f position = ball[i].getPosition();
                                ball[i].setPosition(position.x + velocity[i].x * elapsed->asSeconds(),
                                                    position.y + velocity[i].y * elapsed->asSeconds());
                                new_pos.x = pos.x + velocity[count].x * elapsed->asSeconds();
                                new_pos.y = pos.y + velocity[count].y * elapsed->asSeconds();
                        }

                ball[count].setPosition(new_pos);
        }
}

bool detect_collision(sf::CircleShape *ball1, sf::CircleShape *ball2)
{
        sf::Vector2f position1 = ball1->getPosition();
        sf::Vector2f position2 = ball2->getPosition();

        float x_distance = position1.x - position2.x;
        float y_distance = position1.y - position2.y;
        float dist = sqrt(x_distance * x_distance + y_distance * y_distance);

        return (dist < 2 * RADIUS);
}

void swap_velocity(sf::Vector2f *velocity1, sf::Vector2f *velocity2)
{
        sf::Vector2f temp(0, 0);

        temp = *velocity1;
        *velocity1 = *velocity2;
        *velocity2 = temp;
}

