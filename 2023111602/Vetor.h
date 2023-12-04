#ifndef VETOR_H_INCLUDED
#define VETOR_H_INCLUDED


struct vetor {
    float x;
    float y;
    float z;
};

typedef struct vetor Vetor;

Vetor *CriaVetor(float x,float y, float z);
void DestroiVetor(Vetor *vetor);
void soma(Vetor* v1,Vetor* v2, Vetor* resultado);
float produto_escalar(const Vetor* v1, const Vetor* v2);

#endif // VETOR_H_INCLUDED