#include "include/particles.h"

int find_wall(wall wall, sf::Vector2f ballon_pos)
{
        switch (wall)
        {
                case LOWER:
                        return ballon_pos.y + (float) BALLON_HEIGHT / 2;
                case UPPER:
                        return ballon_pos.y - (float) BALLON_HEIGHT / 2;
                case LEFT:
                        return ballon_pos.x - (float) BALLON_WIDTH  / 2;
                case RIGHT:
                        return ballon_pos.x + (float) BALLON_WIDTH  / 2;
                default:
                        return -1;
        }
}

void move_balls(sf::CircleShape *ball, sf::RectangleShape *ballon,
                sf::Vector2f *velocity, sf::Time *elapsed,
                int num_of_particles)
{
        for (int count = 0; count < num_of_particles; count++) {
                sf::Vector2f pos = ball[count].getPosition();
                sf::Vector2f new_pos(pos.x + velocity[count].x * elapsed->asSeconds(),
                                     pos.y + velocity[count].y * elapsed->asSeconds());

                if (new_pos.x - RADIUS < find_wall(LEFT, ballon->getPosition())) {
                        velocity[count].x *= -1;
                        new_pos.x = find_wall(LEFT, ballon->getPosition()) + RADIUS;
                } else if (new_pos.x + RADIUS >= find_wall(RIGHT, ballon->getPosition())) {
                        velocity[count].x *= -1;
                        new_pos.x = find_wall(RIGHT, ballon->getPosition()) - RADIUS;
                } else if (new_pos.y - RADIUS < find_wall(UPPER, ballon->getPosition())) {
                        velocity[count].y *= -1;
                        new_pos.y = find_wall(UPPER, ballon->getPosition()) + RADIUS;
                } else if (new_pos.y + RADIUS >= find_wall(LOWER, ballon->getPosition())) {
                        velocity[count].y *= -1;
                        new_pos.y = find_wall(LOWER, ballon->getPosition()) - RADIUS;
                }

                static int num_of_collisions = 0;
                for (int i = count + 1; i < num_of_particles; i++)
                        if (detect_collision(&ball[count], &ball[i])) {
                                num_of_collisions++;
                                fprintf(stderr, "Collision %d.\n", num_of_collisions);

                                change_velocity(&velocity[count], &velocity[i]);

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

void change_velocity(sf::Vector2f *velocity1, sf::Vector2f *velocity2)
{
        sf::Vector2f temp(0, 0);

        temp = *velocity1;
        *velocity1 = *velocity2;
        *velocity2 = temp;
}

