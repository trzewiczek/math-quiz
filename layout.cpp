#include <iostream>
#include <string>

#include "layout.h"
using namespace std;

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

