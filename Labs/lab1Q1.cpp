#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;
//Chi-Hao Tu, Yaoyao Liu
int fib (int n){
            if (n <= 1) return 1;

            return fib(n - 1) + fib (n - 2);
            
}