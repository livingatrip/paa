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
        data[*dataSize].data.intValue = (int)int_val;
        data[*dataSize].type = 0; // Tipo int
    } else {
        float float_val = strtof(input, &endptr);
        if (*endptr == '\0') {
            data[*dataSize].data.floatValue = float_val;
            data[*dataSize].type = 1; // Tipo float
        } else {
            data[*dataSize].data.stringValue = malloc((strlen(input) + 1) * sizeof(char));
            if (!data[*dataSize].data.stringValue) {
                printf("Erro ao alocar memória.\n");
                return 1;
            }
            strcpy(data[*dataSize].data.stringValue, input);
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
            printf("%.1f ", data[i].data.floatValue);
            qtFloats++;
        }
    }
     
     for (int i = 0; i < dataSize; i++) {
        if (data[i].type == 0) { 
            if (qtInteiros == 0) {
                printf("int ");
            }
            printf("%d ", data[i].data.intValue);
            qtInteiros++;
        }
        
        if (data[i].type == 2) { 
            if (qtChars == 0) {
                printf("string ");
            }
            printf("%s ", data[i].data.stringValue);
            qtChars++;
        }
    }
    
    printf("\n");
    
    return 0;
}
