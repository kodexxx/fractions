#include <bits/stdc++.h>
#include "fratcions.h"

#define endl '\n'

using namespace std;

int main()
{
  Fraction f1(2, 30, false);
  Fraction f2(1, 2, true);

  cout << f1 << " + " << f2 << " = " << f1 + f2 << " (" << (f1 + f2).getValue() << ")" << endl;
  cout << f1 << " - " << f2 << " = " << f1 - f2 << " (" << (f1 - f2).getValue() << ")" << endl;
  cout << f1 << " * " << f2 << " = " << f1 * f2 << " (" << (f1 * f2).getValue() << ")" << endl;
  cout << f1 << " / " << f2 << " = " << f1 / f2 << " (" << (f1 / f2).getValue() << ")" << endl;

  cout << '\n';
  return 0;
}