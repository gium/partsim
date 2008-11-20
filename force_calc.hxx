#ifndef FORCE_CALC
# define FORCE_CALC

# include "constant.hh"
# include "signe.hxx"

template <bool _infZero, class _Particule>
struct NormalizeVz
{
  static const float value = _Particule::vz;
};

template <class _Particule>
struct NormalizeVz<true, _Particule>
{
  static const float value = 0;
};


template <bool _touchTheFloor, class _Particule>
struct ForcesCalc
{
  static const float ax = -1 * G * FLOOR_COEF *
    Signe<(_Particule::vx > 0)>::value;
  static const float ay = -1 * G * FLOOR_COEF *
    Signe<(_Particule::vy > 0)>::value;
  static const float az = (-1 * (FLOOR_COEF + 1) *
			   NormalizeVz<(_Particule::vz > 0), _Particule>::value) / dt;
};

template <class _Particule>
struct ForcesCalc<false, _Particule>
{
  static const float ax = 0;
  static const float ay = 0;
  static const float az = -1 * G;
};

#endif
