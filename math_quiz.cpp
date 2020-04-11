#include <iostream>

#include "layout.h"
#include "math_quiz.h"

using namespace std;

void addition_quiz(int a, int b, int sum)
{
  int times = a == b ? 1 : 2;

  for (int i = 0; i < times; ++i)
  {
    bool graph = i == 0;
    int  guess = -1;

    // a + b = ?
    layout(a, b, sum, graph);
    while (guess != sum)
    {
      cout << a << " + " << b << " = ";
      cin >> guess;
    }

    // sum - a = ?
    layout(a, b, sum, graph);
    while (guess != b)
    {
      cout << sum << " - " << a << " = ";
      cin >> guess;
    }

    if (a != b)
    {
      // b + a = ?
      layout(a, b, sum, graph);
      while (guess != sum)
      {
        cout << b << " + " << a << " = ";
        cin >> guess;
      }

      // sum - b = ?
      layout(a, b, sum, graph);
      while (guess != a)
      {
        cout << sum << " - " << b << " = ";
        cin >> guess;
      }
    }
  }
}

