#ifndef RAND
# define RAND


const int rand_max = 32767;

template <unsigned int iter, unsigned int seed>
struct Random
{
  static const unsigned int value = (Random<iter - 1, seed>::value * 1103515245 + 12345) % (rand_max + 1);
};

template <unsigned int seed>
struct Random<0, seed>
{
  static const unsigned int value = (seed * 1103515245 + 12345)
    % (rand_max + 1);
};

#endif
