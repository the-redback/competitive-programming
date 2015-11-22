#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector

int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  std::vector<int>::iterator low,up;

  low=std::lower_bound (v.begin(), v.end(), 20); // 0 index system
  up= std::upper_bound (v.begin(), v.end(), 20); // 0 index system

  std::cout << "lower_bound at position " << (low- v.begin()) << '\n'; //ans: 3
  std::cout << "upper_bound at position " << (up - v.begin()) << '\n'; //ans: 6

  low=std::lower_bound (v.begin(), v.end(), 25); //
  up= std::upper_bound (v.begin(), v.end(), 25); //

  std::cout << "lower_bound at position " << (low- v.begin()) << '\n'; //ans: 6
  std::cout << "upper_bound at position " << (up - v.begin()) << '\n'; //ans: 6

  low=std::lower_bound (v.begin(), v.end(), 50); //
  up= std::upper_bound (v.begin(), v.end(), 50); //

  std::cout << "lower_bound at position " << (low- v.begin()) << '\n'; //ans: 8
  std::cout << "upper_bound at position " << (up - v.begin()) << '\n'; //ans: 8

  return 0;
}



// Alternate

int m=lower_bound(v.begin,v.end(),30) - v.begin();

int m=lower_bound(v,v+10,30)-v;