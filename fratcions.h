#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

class Fraction
{
private:
  ull up;
  ull down;
  char isMinus;
  ull gcd(ull a, ull b) const
  {
    while (b)
    {
      a %= b;
      swap(a, b);
    }
    return a;
  }
  ull lcm(ull a, ull b) const
  {
    return a / this->gcd(a, b) * b;
  }
  pair<Fraction, Fraction> toCommonDown(Fraction a, Fraction b) const
  {
    ull lcm = this->lcm(a.down, b.down);
    Fraction f1;
    Fraction f2;
    f1.up = lcm / a.down * a.up;
    f1.down = lcm;
    f1.isMinus = a.isMinus;

    f2.up = lcm / b.down * b.up;
    f2.down = lcm;
    f2.isMinus = b.isMinus;
    return make_pair(f1, f2);
  }

public:
  Fraction()
  {
    this->up = 0;
    this->down = 0;
    this->isMinus = false;
  }
  Fraction(ull up, ull down, char isMinus = false)
  {
    ull gcd = this->gcd(up, down);
    //cout << "constructor " << up << " / " << down << " : " << gcd << endl;
    this->up = up / gcd;
    this->down = down / gcd;
    this->isMinus = isMinus;
  }
  Fraction abs() const
  {
    Fraction f(this->up, this->down);
    return f;
  }
  Fraction inverte() const
  {
    Fraction f(this->up, this->down, !this->isMinus);
    return f;
  }
  double getValue() const
  {
    return (this->isMinus ? -1 : 1) * ((double)this->up / this->down);
  }
  friend ostream &operator<<(ostream &stream, const Fraction &f)
  {
    if (f.up == 0)
    {
      stream << "0";
      return stream;
    }
    if (f.isMinus)
      stream << "-";
    if (f.up / f.down > 0)
    {
      stream << f.up / f.down << " ";
    }
    if (f.up % f.down > 0)
    {
      stream << f.up % f.down << "/" << f.down;
    }

    return stream;
  }
  friend bool operator>(const Fraction &a, const Fraction &b)
  {
    pair<Fraction, Fraction> pf = a.toCommonDown(a, b);

    if (!a.isMinus && !b.isMinus)
    {
      if (pf.first.up > pf.second.up)
        return true;
    }
    else if (a.isMinus && b.isMinus)
    {
      if (pf.first.up < pf.second.up)
        return true;
    }
    else if (!a.isMinus && b.isMinus)
    {
      return true;
    }

    return false;
  }
  friend bool operator<(const Fraction &a, const Fraction &b)
  {
    pair<Fraction, Fraction> pf = a.toCommonDown(a, b);

    if (!a.isMinus && !b.isMinus)
    {
      if (pf.first.up < pf.second.up)
        return true;
    }
    else if (a.isMinus && b.isMinus)
    {
      if (pf.first.up > pf.second.up)
        return true;
    }
    else if (a.isMinus && !b.isMinus)
    {
      return true;
    }

    return false;
  }
  friend bool operator==(const Fraction &a, const Fraction &b)
  {
    if (a.up == b.up && a.down == b.down && a.isMinus == b.isMinus)
      return true;

    return false;
  }
  friend Fraction operator+(const Fraction &a, const Fraction &b)
  {
    ull lcmDown = a.lcm(a.down, b.down);
    if ((a.isMinus && b.isMinus) || (!a.isMinus && !b.isMinus))
    {
      Fraction res(lcmDown / a.down * a.up + lcmDown / b.down * b.up, lcmDown, a.isMinus);
      return res;
    }
    else
    {
      Fraction fMax = max(a.abs(), b.abs()),
               fMin = min(a.abs(), b.abs());

      ull lcmDown = a.lcm(fMin.down, fMax.down);

      Fraction f(lcmDown / fMax.down * fMax.up - lcmDown / fMin.down * fMin.up, lcmDown);

      f.isMinus = b.isMinus;
      if (a.abs() > b.abs())
        f.isMinus = a.isMinus;

      return f;
    }
  }
  friend Fraction operator-(const Fraction &a, const Fraction &b)
  {
    return a + b.inverte();
  }
  friend Fraction operator*(const Fraction &a, const Fraction &b)
  {
    Fraction res(a.up * b.up, a.down * b.down, a.isMinus ^ b.isMinus);
    return res;
  }
  friend Fraction operator/(const Fraction &a, const Fraction &b)
  {
    Fraction res(a.up * b.down, a.down * b.up, a.isMinus ^ b.isMinus);
    return res;
  }
};
