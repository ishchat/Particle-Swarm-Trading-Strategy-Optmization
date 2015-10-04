#ifndef PARTICLE_H
#define PARTICLE_H


class particle
{
public:
particle();
double X[8];//8 dimensional position with each dimension corresponding to a lookback period of SMA to be optimized
double V[8];//8 dimensional velocity vector
double P[8];//8 dimensional personal best position vector
double particle_best_fitness;
};

#endif // PARTICLE_H
