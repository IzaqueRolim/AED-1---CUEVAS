typedef struct complexo Complexo;

Complexo* criarComplexo(double real, double imaginario);
void destruirComplexo(Complexo* numComplexo);
Complexo* somarComplexos(Complexo* num1, Complexo* num2);
Complexo* subtrairComplexos(Complexo* num1, Complexo* num2);
Complexo* multiplicarComplexos(Complexo* num1, Complexo* num2);
Complexo* dividirComplexos(Complexo* num1, Complexo* num2);