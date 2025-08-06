#include <stdio.h>
#include <stdlib.h>

int FFD(int p[], int n, int c);
int FirstFit(int p[], int n, int c);
void mergesort(int a[], int l, int r);
merge(int a[], int l, int mid, int r);
  
int main(){
  int p[] = {1, 2, 9, 6, 5, 4, 7, 1, 3, 8}; //Cargas
  int c = 10; //Capacidad de cada bin
  int n = sizeof(weight) / sizeof(weight[0]);//cant de objetos

  printf("Cantidad de bins usados en la instancia: %d", FDD(p,n,c));
  
  return 0;
}

int FFD(int p[], int n, int c){
  mergesort(p, 0, n-1);
  return FirstFit(p, n, c) 
}

int FirstFit(int p[], int n, int c){
  int cant_bins = 0;
  int cargas[n]; //a lo mas n bins

  cargas[0] = cargas[0] - p[0]; //aperturar un bin y asignar el primer objeto
  cant_bins++;//apertura del bin

  for (int i=1, i<n, i++){
    int j; // var para iterar en los bins abiertos
    for (j = 0; j < cant_bins; j++){
        if(cargas[j] >= p[i]){
            cargas[j] -= p[i]
            break;
        }
    }

    if (j == cant_bins){
      cargas[j] = c - p[i];
      cant_bins++;
    }
      
  } 
  
  return cant_bins;
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
