#include "include/particles.h"

void move_balls(particle_t *particles, sf::RectangleShape *ballon,
                sf::Time *elapsed, int num_of_particles)
{
        for (int count = 0; count < num_of_particles; count++) {
                sf::Vector2f pos = particles[count].ball.getPosition();
                sf::Vector2f new_pos(pos.x + particles[count].velocity.x * elapsed->asSeconds(),
                                     pos.y + particles[count].velocity.y * elapsed->asSeconds());

                if (new_pos.x - RADIUS < LEFT_WALL) {
                        particles[count].velocity.x *= -1;
                        new_pos.x = LEFT_WALL + RADIUS;
                } else if (new_pos.x + RADIUS >= RIGHT_WALL) {
                        particles[count].velocity.x *= -1;
                        new_pos.x = RIGHT_WALL - RADIUS;
                } else if (new_pos.y - RADIUS < UPPER_WALL) {
                        particles[count].velocity.y *= -1;
                        new_pos.y = UPPER_WALL + RADIUS;
                } else if (new_pos.y + RADIUS >= LOWER_WALL) {
                        particles[count].velocity.y *= -1;
                        new_pos.y = LOWER_WALL - RADIUS;
                }

                static int num_of_collisions = 0;
                for (int i = count + 1; i < num_of_particles; i++)
                        if (detect_collision(&particles[count].ball,
                                             &particles[i].ball)) {
                                num_of_collisions++;
                                fprintf(stderr, "Collision %d.\n", num_of_collisions);

                                swap_velocity(&particles[count].velocity, &particles[i].velocity);

                                sf::Vector2f position = particles[i].ball.getPosition();
                                particles[i].ball.setPosition(position.x + particles[i].velocity.x * elapsed->asSeconds(),
                                                    position.y + particles[i].velocity.y * elapsed->asSeconds());
                                new_pos.x = pos.x + particles[count].velocity.x * elapsed->asSeconds();
                                new_pos.y = pos.y + particles[count].velocity.y * elapsed->asSeconds();
                        }

                particles[count].ball.setPosition(new_pos);
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

