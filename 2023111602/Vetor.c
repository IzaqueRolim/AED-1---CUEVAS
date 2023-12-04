#include <stdio.h>
#include <stdlib.h>

#include <Vetor.h>

typedef struct vetor Vetor;

Vetor *CriaVetor(float x,float y, float z){
    
    Vetor *out = malloc(sizeof(Vetor));
    
    out->x = x;
    out->y = y;
    out->z = z;
}

void DestroiVetor(Vetor *vetor){
    free(vetor);
}

void soma(Vetor* v1,Vetor* v2, Vetor* resultado) {
    resultado->x = v1->x + v2->x;
    resultado->y = v1->y + v2->y;
    resultado->z = v1->z + v2->z;
}


float produto_escalar(const Vetor* v1, const Vetor* v2) {
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}