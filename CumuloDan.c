
//**********************************************
// ordenar_en_x(punto *puntos, int p, int r)
//**********************************************
// Descripción: Ordena un arreglo de puntos en 
// función de sus coordenadas X de manera 
// ascendente.
//
// Recibe:
// - puntos: puntero al arreglo de puntos.
// - p: índice de inicio del subarreglo a ordenar.
// - r: índice de fin del subarreglo a ordenar.
// Devuelve: Nada.
//**********************************************
void ordenar_en_x(punto *puntos, int p, int r) {
if(p < r) {
int q = (p + r) / 2; ordenar_en_x(puntos, p, q); ordenar_en_x(puntos, q + 1, r); mezcla(puntos, p, q, r);
}
}

//**********************************************
// mezcla(punto *A, int p, int q, int r)
//**********************************************
// Descripción: Combina dos subarreglos ordenados 
// en uno solo de manera ordenada.
//
// Recibe:
// - A: puntero al arreglo de puntos.
// - p: índice de inicio del primer subarreglo.
// - q: índice de fin del primer subarreglo.
// - r: índice de fin del segundo subarreglo.
// Devuelve: Nada.
//**********************************************
void mezcla(punto *A, int p, int q, int r) {
punto *C = (punto *)malloc(sizeof(punto) * ((r - p) + 1));
int l = r - p + 1;
int i = p;
int j = q + 1;
for(int k = 0; k <= l - 1; k++)
if(i <= q && j <= r)
if(compara(A[i], A[j])) //A[i] < A[j]
                C[k] = A[i++];
            else
                C[k] = A[j++];
        else if(i <= q)
            C[k] = A[i++];
        else
            C[k] = A[j++];
    for(int k = 0; k < l; k++)
        A[p + k] = C[k];
    free(C);
}

//**********************************************
// compara(punto a, punto b)
//**********************************************
// Descripción: Compara dos puntos según sus 
//bcoordenadas X.
//
// Recibe:
// - a: primer punto a comparar.
// - b: segundo punto a comparar.
// Devuelve: 1 si a.x < b.x, 0 en caso contrario.
//**********************************************
int compara(punto a, punto b)
{
    if(a.x < b.x)
        return 1;
return 0; }

//**********************************************
// distancia_minima(punto *puntos, int n)
//**********************************************
// Descripción: Calcula la distancia mínima 
// entre puntos en un arreglo dado.
//
// Recibe:
// - puntos: puntero al arreglo de puntos.
// - n: número de puntos en el arreglo.
// Devuelve: La distancia mínima entre puntos.
//**********************************************
double distancia_minima(punto *puntos, int n) {
if(n == 3)
return minimo(minimo(distancia(puntos[0], puntos[1]), distancia(puntos[0], puntos[2])),
distancia(puntos[1], puntos[2]));
    else if(n == 2)
return distancia(puntos[0], puntos[1]); else if(n < 2)
        return 60000;
int i = n / 2;
double distancia_minima_izq = distancia_minima(puntos, i);
double distancia_minima_der = distancia_minima(puntos + i, n - i);
double distancia_minima = minimo(distancia_minima_izq, distancia_minima_der);
int j = i - 1; int h;

while(j >= 0 && !(puntos[i].x - puntos[j].x > distancia_minima)) {
h = i;
while(h < n && !(puntos[h].x - puntos[j].x > distancia_minima)) {
if(distancia(puntos[j], puntos[h]) < distancia_minima) distancia_minima = distancia(puntos[j], puntos[h]);
h++; }
j--; }
    return distancia_minima;
}
//**********************************************
// distancia(punto a, punto b)
//**********************************************
// Descripción: Calcula la distancia Euclidiana 
//bentre dos puntos.
//
// Recibe:
// - a: primer punto.
// - b: segundo punto.
// Devuelve: La distancia entre los dos puntos.
//**********************************************
double distancia(punto a, punto b) {
return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

//**********************************************
// minimo(double a, double b)
//**********************************************
// Descripción: Calcula el mínimo entre dos 
// valores.
//
// Recibe:
// - a: primer valor.
// - b: segundo valor.
// Devuelve: El valor mínimo entre a y b.
//**********************************************
double minimo(double a, double b)
{
    if(a < b)
        return a;
return b; }