#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
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

int64_t lcm_fast(int64_t a ,int64_t b){

  return (a*b)/gcd_fast(a,b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
