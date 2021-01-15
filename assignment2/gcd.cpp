#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int64_t gcd_fast(int64_t a , int64_t b) {

  //std::cout << "(" << a << "," << b << ")" << std::endl;
  if(a < b){
     int c = b;
     b = a;
     a = c;
  }
  
  if(b==0)
  {
    return a;
  }

  int64_t a_prime = 0;
  a_prime = a%b;

  return gcd_fast(b,a_prime);

}

int main() {
  int a, b;
  std::cin >> a >> b;
  
  //std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
