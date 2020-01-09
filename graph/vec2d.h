#ifndef VEC2D_H
#define VEC2D_H

#include <ostream>

struct Vec2D
{
  unsigned x, y;

  // Constructeurs
  Vec2D(const unsigned & x_ = 0, const unsigned & y_ = 0)
      : x(x_)
      , y(y_)
  {}

  Vec2D(const Vec2D & pos_)
      : x (pos_.x)
      , y (pos_.y)
  {}

  // Décalage
  Vec2D operator + (const Vec2D & pos_) const
  {
      return Vec2D (x + pos_.x, y + pos_.y);
  }

  // Réduction
  Vec2D operator * (const float & reductionRation) const
  {
      return Vec2D (x * reductionRation, y * reductionRation);
  }

  friend Vec2D operator *(const float & reductionRation, const Vec2D & pos_)
  {
      return pos_ * (reductionRation);
  }

  // Égalité
  bool operator == (const Vec2D & pos_) const
  {
      return pos_.x == x && pos_.y == y;
  }

  // Assignement
  Vec2D& operator = (const Vec2D & pos_)
  {
      x = pos_.x;
      y = pos_.y;

      return *this;
  }

  // Le min
  static Vec2D min (const Vec2D & p1, const Vec2D & p2)
  {
      if (p1.x < p2.x) return p1;
      else if (p1.x == p2.x && p1.y < p2.y) return p1;
      return p2;
  }

  // Pointeur de fonction sur min
  static bool minf (const Vec2D & p1, const Vec2D & p2)
  {
      return (p1 == min(p1, p2));
  }

  unsigned & getAbs()
  {
      return x;
  }

  unsigned & getOrd()
  {
      return y;
  }

  friend std::ostream &operator <<(std::ostream &os, const Vec2D &vec)
  {
      os << "X: " << vec.x << ", Y: " << vec.y;
      return os;
  }

};

#endif // VEC2D_H
