#ifndef PARTICULE
# define PARTICULE

#include "constant.hh"
#include "force_calc.hxx"
#include "rand.hxx"

template <int id, int duration>
struct ParticuleHistory
{
  typedef  ParticuleHistory<id, duration - 1> prev;

  static void display()
  {
    prev::display();
    std::cout << qx << " " << qy << " " << qz << std::endl;
  }

  // Acceleration
#define AX (ForcesCalc<(prev::qz <= prev::radius), prev >::ax)
#define AY (ForcesCalc<(prev::qz <= prev::radius), prev >::ay)
#define AZ (ForcesCalc<(prev::qz <= prev::radius), prev >::az)

  // Velocity
#define VX (AX * dt + prev::vx)
#define VY (AY * dt + prev::vy)
#define VZ (AZ * dt + prev::vz)

  static const float vx = VX;
  static const float vy = VY;
  static const float vz = VZ;

  // Position
  static const float qx = VX * dt + prev::qx;
  static const float qy = VY * dt + prev::qy;
  static const float qz = VZ * dt + prev::qz;

  static const float radius = prev::radius;
};

template <int id>
struct ParticuleHistory<id, 0>
{
  static void display()
  {
  }

  static const float vx = Random<id * 6, SEED>::value % 20;
  static const float vy = Random<id * 6 + 1, SEED>::value % 20;
  static const float vz = Random<id * 6 + 2, SEED>::value % 20;

  static const float qx = Random<id * 6 + 3, SEED>::value % 100;
  static const float qy = Random<id * 6 + 4, SEED>::value % 100;
  static const float qz = Random<id * 6 + 5, SEED>::value % 20;

  static const float radius = 3;
};

#endif
