#include "primes.c"

int is_prime(int num) {
    
    int temp = 0;
    
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0) {
            temp++;
            break;
        }
    }
    
    if (temp == 0 && num != 1 && num != 0) {
        return 1;
    }
}

int next_prime(int current) {
    for(;;) {
        ++current;
        
        if (is_prime(current)) {
            break;
        }
    }
    
    return current;
}