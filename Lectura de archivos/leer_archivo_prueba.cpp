#include<stdio.h>
#include<stdlib.h>

int main(){

    FILE* archivo = fopen("trabajos.txt", "r");
 
    if (!archivo) {
        perror("No se pudo abrir el archivo");
        return 1;
    }

    int n, m;
    fscanf(archivo, "%d", &n); // número de trabajos
    fscanf(archivo, "%d", &m); // número de máquinas
    
    printf("\n\t\t\tn:%d", n);
    printf("\n\t\t\tm:%d",m);
    int p[n];
    for (int i = 0; i < n; i++) {
        fscanf(archivo, "%d", &p[i]);
        printf("\n\t\t\tp[%d]:%d",i, p[i]);
    }
    fclose(archivo);
    return 0;
}
