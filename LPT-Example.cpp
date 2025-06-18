#include <stdio.h>
#include <stdlib.h>

int comparar(const void* a, const void* b);
int creciente(const void* a, const void* b);
void imprimir_array(int array[], int tam); 
void min_C_m(int C_m[]);

int main (){
    //int n = 9;
    //int m = 3;
    //int p[] = {8,5,7,9,1,4,2,3,6};
    
    int n=79;
    int m = 10;
    int p[] = {24, 22, 23, 5, 11, 23, 26, 9, 23, 9, 14, 16, 12, 2, 2, 6, 20, 26, 12, 15, 13, 26, 17, 7, 12, 4, 4, 20, 10, 9, 2, 9, 1, 2, 2, 12, 14, 23, 21, 13, 13, 23, 3, 6, 23, 11, 2, 7, 13, 10, 3, 6, 13, 2, 14, 7, 21, 7, 22, 13, 22, 18, 22, 6, 2, 11, 5, 9, 9, 5, 12, 2, 12, 19, 6, 14, 2, 2, 24};
    //int n = sizeof(p) / sizeof(p[0]);
    qsort(p, n, sizeof(int), comparar);
    
    //imprimir_array(p, n);
    
    int c_t[n]; //Tiempo de completés de cada trabajo
    int C_m[m]; //Tiempo de completés de cada máquina
    
    int i;
    //Asignar primeros m trabajos a las m maquinas
    printf("Agregar los primeros m trabajos a las m maquinas\n");
    for(i=0; i<m; i++){
        c_t[i] = p[i];
        C_m[i] = c_t[i];
        printf("Trabajo %d con p=%d asignado a la maquina %d\n", i+1,p[i], i+1);
    }
    
    qsort(C_m, m, sizeof(int), creciente);
    printf("Carga de las máquinas: ");
    imprimir_array(C_m, m);
    printf("\n\n");
    //asignar siguientes trabajos 
    for(i=m; i<n; i++){
        printf("Asignar trabajo [%d] con p=[%d] a la máquina con carga: [%d]\n",i+1, p[i], C_m[0]);
        C_m[0] += p[i];
        //printf("%d \n",C_m[0], m);
        min_C_m(C_m);
        printf("Actualizando cargas:\n");
        imprimir_array(C_m, m);
        printf("\n\n");
    }
    printf("---Trabajos asignados---");
    printf("\nTiempos de completés de las maquinas:\n");
    imprimir_array(C_m, m);
    
    printf("\n\n===> Cmax = %d", C_m[m-1]);
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
        printf("[%d] ", array[i]);
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
