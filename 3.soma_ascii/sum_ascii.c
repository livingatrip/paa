#include "sum_ascii.h"
#include "stdio.h"

int sum_ascii(const char *str) {
    char string[100];
    int soma = 0;
    int i = 0;

    do {
        soma += (int)str[i];
        i++;
    } while (str[i] != '\0');

    return soma;
}