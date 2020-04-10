#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main ()
{
  srand(time(NULL));

  for(int i = 0; i < 30; ++i)
  {
    const int sum = rand() % 5 + 6;  // range [6, 10]
    const int a   = rand() % sum;    // range [0, sum)
    const int b   = sum - a;

    int guess = -1;
    while (guess != sum)
    {
      cout << a << " + " << b << " = ";
      cin >> guess;
    }
  }
}
