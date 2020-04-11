#include <iostream>
#include <cstdlib>
#include <ctime>

#include "layout.h"
#include "math_quiz.h"

using namespace std;

int main ()
{
  srand(time(NULL));

  int lower;
  int upper;

  cout << "Podaj zakres" << endl;
  cout << "Od: ";
  cin >> lower;
  cout << "Do: ";
  cin >> upper;

  for (int i = 0; i < 30; ++i)
  {
    const int sum = rand() % (upper - lower + 1) + lower;  // [lower, upper]
    const int a   = rand() % (sum - 1) + 1;                // [1, sum)
    const int b   = sum - a;

    addition_quiz(a, b, sum);
  }
}

