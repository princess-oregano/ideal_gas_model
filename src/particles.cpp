#include "include/particles.h"

// Moves particles from each other after their collision.
static void separate_particles(particle_t *particle1, particle_t *particle2)
{
        fprintf(stderr, "Separation\n");
        sf::Vector2f distance = particle1->position - particle2->position;

        float length = sqrt(distance.x * distance.x + distance.y * distance.y);

        float x_offset = distance.x / length * (2 * PARTICLE_RADIUS - length);
        float y_offset = distance.y / length * (2 * PARTICLE_RADIUS - length);

        particle1->position.x += x_offset;
        particle1->position.y += y_offset;
}

// Detects collisions of particles.
static bool detect_collision(const particle_t *particle1, const particle_t *particle2)
{
        assert(particle1);
        assert(particle2);

        float x_distance = particle1->position.x - particle2->position.x;
        float y_distance = particle1->position.y - particle2->position.y;
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
static void collide_particle2walls(particle_t *particle)
{
        assert(particle);

        if (particle->position.x - PARTICLE_RADIUS < LEFT_WALL) {
                particle->velocity.x *= -1;
                particle->position.x = LEFT_WALL + PARTICLE_RADIUS;
        }
        if (particle->position.x + PARTICLE_RADIUS > RIGHT_WALL) {
                particle->velocity.x *= -1;
                particle->position.x = RIGHT_WALL - PARTICLE_RADIUS;
        }
        if (particle->position.y - PARTICLE_RADIUS < UPPER_WALL) {
                particle->velocity.y *= -1;
                particle->position.y = UPPER_WALL + PARTICLE_RADIUS;
        }
        if (particle->position.y + PARTICLE_RADIUS > LOWER_WALL) {
                particle->velocity.y *= -1;
                particle->position.y = LOWER_WALL - PARTICLE_RADIUS;
        }
}

void move_particles(particle_t *particles, const sf::Time elapsed, const int num_of_particles)
{
        assert(particles);

        for (int count = 0; count < num_of_particles; count++) {

                collide_particle2walls(&particles[count]);

                for (int i = count + 1; i < num_of_particles; i++)
                        collide_particle2particle(&particles[count], &particles[i]);

                particles[count].position.x += particles[count].velocity.x * elapsed.asSeconds();
                particles[count].position.y += particles[count].velocity.y * elapsed.asSeconds();
        }
}

