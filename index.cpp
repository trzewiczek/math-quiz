#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void test_math(int a, int b, int sum);

int main ()
{
  srand(time(NULL));

  for (int i = 0; i < 30; ++i)
  {
    const int sum = rand() % 5 + 6;          // range [6, 10]
    const int a   = rand() % (sum - 1) + 1;  // range [1, sum)
    const int b   = sum - a;

    test_math(a, b, sum);
  }
}

void test_math(int a, int b, int sum)
{
  int times = a == b ? 1 : 2;

  for (int i = 0; i < times; ++i)
  {
    int guess = -1;
    while (guess != sum)
    {
      cout << a << " + " << b << " = ";
      cin >> guess;
    }

    while (guess != b)
    {
      cout << sum << " - " << a << " = ";
      cin >> guess;
    }

    if (a != b)
    {
      while (guess != sum)
      {
        cout << b << " + " << a << " = ";
        cin >> guess;
      }

      while (guess != a)
      {
        cout << sum << " - " << b << " = ";
        cin >> guess;
      }
    }
  }
}
