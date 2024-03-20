#include <stdio.h>

int main() {
    
    float valorEntrada; 

    printf("Digite um valor float: ");
    scanf("%f", &valorEntrada); 
    
    valorEntrada += 10;
    
    printf("O novo valor da variável é: %.2f\n", valorEntrada);

    return 0;
}
