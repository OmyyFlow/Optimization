#include <stdio.h>
#include <stdlib.h>

int comparar(const void* a, const void* b);
int creciente(const void* a, const void* b);
void imprimir_array(int array[], int tam); 
void min_C_m(int C_m[]);

int main (){
    int n = 9;
    int m = 3;
    int p[] = {8,5,7,9,1,4,2,3,6};
    //int nn = sizeof(p) / sizeof(p[0]);
    qsort(p, n, sizeof(int), comparar);
    //imprimir_array(p, n);
    
    int c_t[n]; //Tiempo de completés de cada trabajo
    int C_m[m]; //Tiempo de completés de cada máquina
    
    int i;
    //Asignar primeros m trabajos a las m maquinas
    for(i=0; i<m; i++){
        c_t[i] = p[i];
        C_m[i] = c_t[i];
    }
    
    qsort(C_m, m, sizeof(int), creciente);
    //imprimir_array(C_m, m);
    
    //asignar siguientes trabajos 
    for(i=m; i<n; i++){
        printf("%d + %d: ",C_m[0], p[i]);
        C_m[0] = C_m[0] + p[i];
        printf("%d \n",C_m[0], m);
        min_C_m(C_m);
    }
    printf("\n");
    imprimir_array(C_m, m);
    
    return 0;
}

int comparar(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int creciente(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void imprimir_array(int array[], int tam){
    for(int i=0; i<tam; i++){
        printf("%d ", array[i]);
    }
}

void min_C_m(int C_m[]){
    int C = C_m[0];
    
    int i=1;
    while(C > C_m[i]){
        C_m[i-1] = C_m[i];
        i++;
    }
    C_m[i-1] = C;
}
