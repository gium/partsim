#ifndef SIMULATION
# define SIMULATION

# include "particule.hxx"

template <int nb_part, int duration>
struct Simulation
{
  typedef ParticuleHistory<nb_part, duration> particule_history;
  typedef Simulation<nb_part - 1, duration> next;

  static void display()
  {
    particule_history::display();
    std::cout << std::endl;
    next::display();
  }
};

template <int duration>
struct Simulation<0, duration>
{
  typedef ParticuleHistory<0, duration> particule_history;

  static void display()
  {
    particule_history::display();
  }
};

#endif
