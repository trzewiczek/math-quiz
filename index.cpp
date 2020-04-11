#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void test_math(int a, int b, int sum);
void layout(int a, int b, int sum, bool graph);

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

    test_math(a, b, sum);
  }
}

void test_math(int a, int b, int sum)
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

void layout(int a, int b, int sum, bool graph)
{
  cout << "\033c";
  cout << "\n\n";

  if (graph)
  {
    //   3   4      3    7
    //    \ /   or   \  /
    //     7          10

    const string gap = sum > 9
      ? "  "
      : " ";

    cout << " " << a << " " << gap << " " << b << endl;
    cout << "  \\" << gap << "/" << endl;
    cout << "   " << sum << endl;
  }
  else
  {
    // empty space
    cout << "\n\n\n";
  }

  cout << "\n\n";
}

