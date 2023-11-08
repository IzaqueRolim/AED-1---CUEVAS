#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

typedef struct data Data;

Data *CriaData(char dia[3], char mes[3], char ano[5]);
int AtribuiData(Data *data, char dia[3], char mes[3], char ano[5]);
DestruirData(Data *data);

#endif // PESSOA_H_INCLUDED