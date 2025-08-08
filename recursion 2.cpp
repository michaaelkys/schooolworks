#include <iostream>
using namespace std;

void message(int);

int main()
  {
    message(5);
  }
  
  void message(int times)
  {
    cout << "Message called with " << times << " in times.\n";
    
    if (times > 0)
      {
        cout << "This is a recursive function.\n\n";
        message(times - 1);
      }
      cout << "Message returning with " << times;
      cout << " in times.\n";
  }