#include <iostream>
using namespace std;

void message(int times);

int main()
  {
    message(3);
  }
  
  void message(int times)
  {
      if (times > 0)
      {
        cout << "This is a recursive function.\n";
        message(times - 1);
      }
    return;
  }