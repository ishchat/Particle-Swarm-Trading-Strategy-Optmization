#include <vector>
#include <iostream>
#include <random>
#include "MMPSO.h"
#include "particle.h"
#include "transaction.h"


extern double Global_best_fitness;
extern double Global_best_position[8];
extern double Capital ;
extern double holding_capital;
extern std::string State;

//MMPSO from:
//https://en.wikipedia.org/wiki/Particle_swarm_optimization
//http://www.cleveralgorithms.com/nature-inspired/swarm/pso.html
void MMPSO(std::vector <double> _close)
{
using namespace std;

int Number_of_particles = 50;
std::vector <particle> particles;

std::default_random_engine generator;
std::uniform_real_distribution<double> distribution(0.0,1.0);

double fitness;

//Initialize the particles
for (int i=0;i<Number_of_particles;i++)
{
particle particle1;
//cout<<"particle1.X[0]"<<particle1.X[0];
particles.push_back(particle1);
}

//Initialize Global_best_fitness as best particle best fitness

for (int j=0;j<Number_of_particles;j++)
{
fitness = transaction(_close, particles[j].X[0], particles[j].X[1], particles[j].X[2], particles[j].X[3], particles[j].X[4], particles[j].X[5], particles[j].X[6], particles[j].X[7]);
//std::cout<<"holding_capital: "<<holding_capital;
particles[j].particle_best_fitness = fitness;
if(Global_best_fitness < particles[j].particle_best_fitness)
{
Global_best_fitness = particles[j].particle_best_fitness;
for(int k=0; k<8; k++){
Global_best_position[k] = particles[j].X[k];
}
}
}

bool stopping_condition = true;
int iteration = 0;
int max_iterations = 500;
double inertia_weight=1.4;
int c1 = 2;
int c2 = 2;
double particles_best_fitness_iteration = 0;
while(stopping_condition and (++iteration < max_iterations))
{
cout<<"iteration"<<iteration<<endl<<"Global_best_fitness"<<Global_best_fitness<<"Global_best_position"<<Global_best_position[0]<<" "<<Global_best_position[1]<<endl;
//change the inertia weight w according to the number of iterations.

for(int j=0; j<Number_of_particles; j++)
{
//cout<<"particle j: "<<j;
double r1 = distribution(generator);
double r2 = distribution(generator);
for(int k=0; k<8; k++){
particles[j].V[k] = inertia_weight*particles[j].V[k]+c1*r1*(particles[j].P[k]-particles[j].X[k])+c2*r2*(Global_best_position[k]-particles[j].X[k]);
particles[j].X[k] = particles[j].X[k]+particles[j].V[k];

//Velocity clamping
if (particles[j].V[k]>80) {particles[j].V[k]=80; /*cout<<"clamped";*/}
else if (particles[j].V[k]<-80) {particles[j].V[k]=-80;}
//cout<<" k "<<k<<" particles[j].X[k]: "<<particles[j].X[k]<<" particles[j].V[k]: "<<particles[j].V[k];
}

double fitness = transaction(_close, particles[j].X[0], particles[j].X[1], particles[j].X[2], particles[j].X[3], particles[j].X[4], particles[j].X[5], particles[j].X[6], particles[j].X[7]);

if (particles[j].particle_best_fitness < fitness)
{
 particles[j].particle_best_fitness = fitness;
}

if(Global_best_fitness < particles[j].particle_best_fitness)
{
Global_best_fitness = particles[j].particle_best_fitness;
}

}//end of single particle loop
/*Linearly decreasing Inertia weight from http://www.softcomputing.net/nabic11_7.pdf
1.4 and .4 are numbers from PSO trading paper*/
inertia_weight = 1.4 - ((1.4-.4)/max_iterations)*iteration;

}//end of iteration while

}//MMPSO definition ends here

