#include <stdio.h>
#include <stdlib.h>

void imprimir_array(int array[], int tam);
void min_C_m(int C_m[]);
void mergesort(int a[], int l, int r);
void merge(int a[], int l, int mid, int r);//mayor a menor

//instance:

int n = 79;
int m = 10;
int p[] = {24, 22, 23, 5, 11, 23, 26, 9, 23, 9, 14, 16, 12, 2, 2, 6, 20, 26, 12, 15, 13, 26, 17, 7, 12, 4, 4, 20, 10, 9, 2, 9, 1, 2, 2, 12, 14, 23, 21, 13, 13, 23, 3, 6, 23, 11, 2, 7, 13, 10, 3, 6, 13, 2, 14, 7, 21, 7, 22, 13, 22, 18, 22, 6, 2, 11, 5, 9, 9, 5, 12, 2, 12, 19, 6, 14, 2, 2, 24 };

int main() {

    mergesort(p, 0, n - 1);

    int C_m[m]; //Tiempo de completés de cada máquina
    int i;

    //Asignar primeros m trabajos a las m maquinas
    printf("\n**Agregar los primeros m trabajos a las m maquinas**\n\n");
    for (i = 0; i < m; i++) {
        C_m[m-i-1] = p[i];
        printf("Trabajo %d con p=%d asignado a la maquina %d\n", i + 1, p[i], m-i );
    }

    printf("Carga de las máquinas: ");
    imprimir_array(C_m, m);
    printf("\n\n");
    //asignar siguientes trabajos 
    for (i = m; i < n; i++) {
        printf("Asignar trabajo [%d] con p=[%d] a la máquina con carga: [%d]\n", i + 1, p[i], C_m[0]);
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

    printf("\n\n===> Cmax = %d\n\n", C_m[m - 1]);
    return 0;
}

void imprimir_array(int array[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("[%d] ", array[i]);
    }
}

void min_C_m(int C_m[]) {
    int C = C_m[0];

    int i = 1;
    while (C > C_m[i]) {
        C_m[i - 1] = C_m[i];
        i++;
    }
    C_m[i - 1] = C;
}

void mergesort(int a[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2; // calcula el medio entre l y r
        mergesort(a, l, mid);    // Llamada recursiva para la mitad izquierda
        mergesort(a, mid + 1, r); // Llamada recursiva para la mitad derecha
        merge(a, l, mid, r);      // Mezcla las dos mitades ordenadas
    }
}

void merge(int a[], int l, int mid, int r) {
    int temp[r - l + 1];  // Arreglo temporal para la fusión
    int i = l, j = mid + 1, k = 0;

    while (i <= mid && j <= r) { // Mezcla mientras ambas mitades tengan elementos
        if (a[i] > a[j]) { //compara para asignar al arreglo temporal
            temp[k] = a[i];//
            i++;
        }
        else {
            temp[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid) { // Copia los elementos restantes de la mitad izquierda
        temp[k] = a[i];
        i++;
        k++;
    }

    while (j <= r) { // Copia los elementos restantes de la mitad derecha
        temp[k] = a[j];
        j++;
        k++;
    }

    for (i = l; i <= r; i++) { // Copia los elementos fusionados de nuevo al arreglo original
        a[i] = temp[i - l];
    }
}

