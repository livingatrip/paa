#include "generic_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 5

int readGenericData(struct GenericData *data, int *dataSize) {
    
    if (*dataSize == MAX_SIZE) {
         printf("Tamanho do vetor excedido.\n");
         return 1;
    }
    
    char input[100];
    if (scanf("%s", input) != 1) {
        printf("Erro de leitura.\n");
        return 1;
    }
    
    char *endptr;
    long int_val = strtol(input, &endptr, 10);
    if (*endptr == '\0') {
        int *intValue = malloc(sizeof(int));
        if (!intValue) {
            printf("Erro ao alocar memória.\n");
            return 1;
        }
        *intValue = (int)int_val;
        data[*dataSize].data = intValue;
        data[*dataSize].type = 0; // Tipo int
    } else {
        float float_val = strtof(input, &endptr);
        if (*endptr == '\0') {
            float *floatValue = malloc(sizeof(float));
            if (!floatValue) {
                printf("Erro ao alocar memória.\n");
                return 1;
            }
            *floatValue = float_val;
            data[*dataSize].data = floatValue;
            data[*dataSize].type = 1; // Tipo float
        } else {
            char *stringValue = malloc((strlen(input) + 1) * sizeof(char));
            if (!stringValue) {
                printf("Erro ao alocar memória.\n");
                return 1;
            }
            strcpy(stringValue, input);
            data[*dataSize].data = stringValue;
            data[*dataSize].type = 2; // Tipo string
        }
    }
    
    // data[0].data.intValue = 15;
    // data[0].type = 0; // Tipo int
    
    // (*dataSize)++;
    
    // data[1].data.intValue = 1.5;
    // data[1].type = 1; // Tipo int
    
    (*dataSize)++;

    return 0;
}

int printGenericData(struct GenericData *data, int dataSize) {
    
    // Tipo int
     int qtInteiros = 0;
     int qtFloats = 0;
     int qtChars = 0;
     
     
    // Tipo float
    for (int i = 0; i < dataSize; i++) {
        if (data[i].type == 1) { 
            if (qtFloats == 0) {
                printf("float ");
            }
            printf("%.1f ", *((float *)data[i].data));
            qtFloats++;
        }
    }
     
     for (int i = 0; i < dataSize; i++) {
        if (data[i].type == 0) { 
            if (qtInteiros == 0) {
                printf("int ");
            }
            printf("%d ", *((int *)data[i].data));
            qtInteiros++;
        }
        
        if (data[i].type == 2) { 
            if (qtChars == 0) {
                printf("string ");
            }
            printf("%s ", (char *)data[i].data);
            qtChars++;
        }
    }
    
    printf("\n");
    
    return 0;
}
