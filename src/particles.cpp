#include "include/particles.h"

// Moves particles from each other after their collision.
static void separate_particles(particle_t *particle1, particle_t *particle2)
{
        sf::Vector2f position1 = particle1->ball.getPosition();
        sf::Vector2f position2 = particle2->ball.getPosition();
        sf::Vector2f distance = position1 - position2;

        float length = sqrt(distance.x * distance.x + distance.y * distance.y);

        float x_offset = distance.x / length * (2 * PARTICLE_RADIUS - length);
        float y_offset = distance.y / length * (2 * PARTICLE_RADIUS - length);

        position1.x += x_offset;
        position1.y += y_offset;

        particle1->ball.setPosition(position1);
}

// Detects collisions of particles.
static bool detect_collision(const particle_t *particle1, const particle_t *particle2)
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
static void collide_particle2particle(particle_t *particle1, particle_t *particle2)
{
        assert(particle1);
        assert(particle2);

        static int num_of_collisions = 0;

        if (detect_collision(particle1, particle2)) {
                num_of_collisions++;
                fprintf(stderr, "Collision %d.\n", num_of_collisions);

                swap_velocity(particle1, particle2);

                separate_particles(particle1, particle2);
        }
}

// Detects and manages collisions between ballon and balls.
static void collide_particle2walls(particle_t *particles, sf::Vector2f *pos)
{
        assert(particles);
        assert(pos);

        if (pos->x - PARTICLE_RADIUS < LEFT_WALL) {
                particles->velocity.x *= -1;
                pos->x = LEFT_WALL + PARTICLE_RADIUS;
        }
        if (pos->x + PARTICLE_RADIUS > RIGHT_WALL) {
                particles->velocity.x *= -1;
                pos->x = RIGHT_WALL - PARTICLE_RADIUS;
        }
        if (pos->y - PARTICLE_RADIUS < UPPER_WALL) {
                particles->velocity.y *= -1;
                pos->y = UPPER_WALL + PARTICLE_RADIUS;
        }
        if (pos->y + PARTICLE_RADIUS > LOWER_WALL) {
                particles->velocity.y *= -1;
                pos->y = LOWER_WALL - PARTICLE_RADIUS;
        }
}

void move_particles(particle_t *particles, const sf::Time elapsed, const int num_of_particles)
{
        assert(particles);

        for (int count = 0; count < num_of_particles; count++) {
                sf::Vector2f pos = particles[count].ball.getPosition();

                collide_particle2walls(&particles[count], &pos);

                for (int i = count + 1; i < num_of_particles; i++)
                        collide_particle2particle(&particles[count], &particles[i]);

                pos.x = pos.x + particles[count].velocity.x * elapsed.asSeconds();
                pos.y = pos.y + particles[count].velocity.y * elapsed.asSeconds();

                particles[count].ball.setPosition(pos);
        }
}

