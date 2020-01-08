#ifndef VEC2D_H
#define VEC2D_H

#include <ostream>

struct Vec2D
{
  unsigned abs, ord;

  // Constructeurs
  Vec2D(const unsigned & abs_ = 0, const unsigned & ord_ = 0)
      : abs(abs_)
      , ord (ord_)
  {}

  Vec2D(const Vec2D & pos_)
      : abs (pos_.abs)
      , ord (pos_.ord)
  {}

  // Décalage
  Vec2D operator + (const Vec2D & pos_) const
  {
      return Vec2D (abs + pos_.abs, ord + pos_.ord);
  }

  // Réduction
  Vec2D operator * (const float & reductionRation) const
  {
      return Vec2D (abs * reductionRation, ord * reductionRation);
  }

  friend Vec2D operator *(const float & reductionRation, const Vec2D & pos_)
  {
      return pos_ * (reductionRation);
  }

  // Égalité
  bool operator == (const Vec2D & pos_) const
  {
      return pos_.abs == abs && pos_.ord == ord;
  }

  // Assignement
  Vec2D& operator = (const Vec2D & pos_)
  {
      abs = pos_.abs;
      ord = pos_.ord;

      return *this;
  }

  // Le min
  static Vec2D min (const Vec2D & p1, const Vec2D & p2)
  {
      if (p1.abs < p2.abs) return p1;
      else if (p1.abs == p2.abs && p1.ord < p2.ord) return p1;
      return p2;
  }

  // Pointeur de fonction sur min
  static bool minf (const Vec2D & p1, const Vec2D & p2)
  {
      return (p1 == min(p1, p2));
  }

  unsigned & getAbs()
  {
      return abs;
  }

  unsigned & getOrd()
  {
      return ord;
  }

  friend std::ostream &operator <<(std::ostream &os, const Vec2D &vec)
  {
      os << "X: " << vec.abs << ", Y: " << vec.ord;
      return os;
  }

};

#endif // VEC2D_H
