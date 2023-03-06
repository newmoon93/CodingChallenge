#include <iostream>
#include "BOJ.h"
using namespace std;

int BOJ_10250(void) {
  int t;
  int h, w, n;
  int room;

  cin >> t;

  for(int i = 0; i < t; i++) {
    cin >> h >> w >> n;
    if (h >= n) {
      room = n*100 + 1;
    }
    else {
      if (n%h == 0) {
        room = h*100 + n/h;
      }
      else {
        room = (n%h)*100 + n/h + 1;
      }
    }

    cout << room << endl;
  }

  return 0;
}