#include <iostream>

#ifndef SEED
# define SEED 1
#endif

#ifndef NB_PART
# define NB_PART 10
#endif

#ifndef NB_ITER
# define NB_ITER 300
#endif

#include "simulation.hxx"

int main()
{
  Simulation<NB_PART, NB_ITER>::display();
}
