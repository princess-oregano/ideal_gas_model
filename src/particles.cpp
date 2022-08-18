#include "include/particles.h"

// Detects collisions of particles.
static bool detect_collision(particle_t *particle1, particle_t *particle2)
{
        assert(particle1);
        assert(particle2);

        sf::Vector2f position1 = particle1->ball.getPosition();
        sf::Vector2f position2 = particle2->ball.getPosition();

        float x_distance = position1.x - position2.x;
        float y_distance = position1.y - position2.y;
        float dist_squared = x_distance * x_distance + y_distance * y_distance;

        return (dist_squared < (2 * PARTICLE_RADIUS) * (2 * PARTICLE_RADIUS));
}

// Changes velocities of particles in case of collision.
static void swap_velocity(particle_t *particle1, particle_t *particle2)
{
        assert(particle1);
        assert(particle2);

        sf::Vector2f temp(0, 0);

        temp = particle1->velocity;
        particle1->velocity = particle2->velocity;
        particle2->velocity = temp;
}

// Detects and manages collisions between balls.
static void collide_particle2particle(particle_t *particles, sf::Time *elapsed,
                                      int i, int count, int num_of_particles)
{
        assert(particles);
        assert(elapsed);

        static int num_of_collisions = 0;

        if (detect_collision(&particles[count], &particles[i])) {
                num_of_collisions++;
                fprintf(stderr, "Collision %d.\n", num_of_collisions);

                swap_velocity(&particles[count], &particles[i]);

                sf::Vector2f position = particles[i].ball.getPosition();
                particles[i].ball.setPosition(position.x + particles[i].velocity.x * elapsed->asSeconds(),
                                              position.y + particles[i].velocity.y * elapsed->asSeconds());
                }
}

// Detects and manages collisions between ballon and balls.
static void collide_particle2walls(particle_t *particles, sf::Vector2f *new_pos)
{
        assert(particles);
        assert(new_pos);

        if (new_pos->x - PARTICLE_RADIUS < LEFT_WALL) {
                particles->velocity.x *= -1;
                new_pos->x = LEFT_WALL + PARTICLE_RADIUS;
        }
        if (new_pos->x + PARTICLE_RADIUS >= RIGHT_WALL) {
                particles->velocity.x *= -1;
                new_pos->x = RIGHT_WALL - PARTICLE_RADIUS;
        }
        if (new_pos->y - PARTICLE_RADIUS < UPPER_WALL) {
                particles->velocity.y *= -1;
                new_pos->y = UPPER_WALL + PARTICLE_RADIUS;
        }
        if (new_pos->y + PARTICLE_RADIUS >= LOWER_WALL) {
                particles->velocity.y *= -1;
                new_pos->y = LOWER_WALL - PARTICLE_RADIUS;
        }
}

void move_particles(particle_t *particles, sf::Time *elapsed, int num_of_particles)
{
        assert(particles);
        assert(elapsed);

        for (int count = 0; count < num_of_particles; count++) {
                sf::Vector2f pos = particles[count].ball.getPosition();
                sf::Vector2f new_pos(pos.x + particles[count].velocity.x * elapsed->asSeconds(),
                                     pos.y + particles[count].velocity.y * elapsed->asSeconds());

                collide_particle2walls(&particles[count], &new_pos);

                for (int i = count + 1; i < num_of_particles; i++)
                        collide_particle2particle(particles, elapsed, i, count, num_of_particles);

                new_pos.x = pos.x + particles[count].velocity.x * elapsed->asSeconds();
                new_pos.y = pos.y + particles[count].velocity.y * elapsed->asSeconds();
                particles[count].ball.setPosition(new_pos);
        }
}

