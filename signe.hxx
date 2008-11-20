#ifndef SIGNE
# define SIGNE


template <bool _positive>
struct Signe
{
  static const int value = 1;
};

template <>
struct Signe<false>
{
  static const int value = -1;
};

#endif
