#include "particle.h"
#include <random>

particle::particle()
{
/*http://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution */
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> disx(6, 400);//range for X given in PSO trading paper
std::uniform_real_distribution<> disv(-80, 80);//range for V given in PSO trading paper


/*https://en.wikipedia.org/wiki/Particle_swarm_optimization */
for (int i=0; i<8; i++)
{
X[i] = disx(gen);
V[i] = disv(gen);
P[i] = X[i];//Initial particle best position is it's original position
}
double particle_best_fitness=0;

}
