#include <stdio.h>
#include "primes.h"

int main() {
    int start, end, current_prime;
    
    scanf("%d", &start); 
    scanf("%d", &end); 
    current_prime = start;
    printf("Numeros primos no intervalo de %d a %d:\n", start, end);
    for (int i = start; i <= end; i++) {
    	if (is_prime(current_prime)) {
    		printf("%d ", current_prime);	
		}
        
        current_prime = next_prime(current_prime);
        
		if (current_prime > end) {
        	break;
		}
		
        i++;
    }
    printf("\n");
    return 0;
}
