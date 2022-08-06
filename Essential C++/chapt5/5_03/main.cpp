#include "fibonacci.hpp"

int main()
{
    // Fibonacci fib;

    // cout << fib << endl;

    // Fibonacci fib2(16);
    // cout << fib2 << endl;

    // Fibonacci fib3(8, 12);
    // cout << fib3 << endl;
    
    num_sequence *pns = new Fibonacci(8,12);
    cout << *pns << endl;
    return 0;
}

