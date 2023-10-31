#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
    char dia[3]; 
    char mes[3]; 
    char ano[5]; 
};
typedef struct data Data;

Data *CriaData(char dia[3], char mes[3], char ano[5]) {
    Data *out = malloc(sizeof(Data));
    strcpy(out->dia, dia);
    strcpy(out->mes, mes);
    strcpy(out->ano, ano);
    return out;
}

int AtribuiData(Data *data, char dia[3], char mes[3], char ano[5]) {
    if (data == NULL) {
        return 0;
    }
    strcpy(data->dia, dia);
    strcpy(data->mes, mes);
    strcpy(data->ano, ano);
    return 1;
}