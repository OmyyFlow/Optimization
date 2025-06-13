//[0/1] KNAPSACK PROBLEM WHITH DYNAMIC PROGRAMMING (DUPLES)

#include <stdio.h>
#include <conio.h>

#define n 24 // Cant de objetos
#define M 6404180 // Capacidad de la mochila

int cardinalidad_de_S;
int cardinalidad_de_S_prima;
int i, j, h;

int wi[n]={382745,799601,909247,729069,467902,44328,34610,698150,823460,903959,853665,551830,610856,670702,488960,951111,323046,446298,931161,31385,496951,264724,224916,169684 };
int pi[n]={825594,1677009,1676628,1523970,943972,97426,69666,1296457,1679693,1902996,1844992,1049289,1252836,1319836,95327,2067538,675367,853655,1826027,65731,901489,577243,466257,369261 };

//int wi[n]={2, 3, 5, 1, 4};				// Pesos de cada objeto 
//int pi[n]={10, 5, 2, 4, 6};			//beneficios de cada objeto

typedef struct {
	int W; 		/*	DUPLAS	*/
	int P;		/*		(P,W)	*/
	int X[n]; // Vector solucion
} duplas; 


void agregar_dupla(int P, int W);
void imprimir_duplas();
void eliminar_dupla(int dupla_a_eliminar);
int obtener_maxP ();
void agregar_solucion(int i, int j);
void imprimir_solucion();
void obtener_solucion();

duplas S[16777216];

int main (){
			 									
	agregar_dupla(0,0);
	agregar_dupla(pi[0],wi[0]);
	S[1].X[n-1]=1;
	printf("S_1 = {");
	imprimir_duplas();		
	printf("}\n");
		
	for (i=1; i<n; i++){
		cardinalidad_de_S_prima = cardinalidad_de_S; //Le asigna la misma cardinalidad a S prima
			
		//Agregar tuplas correspondientes al objeto i
		for (j = 0; j < cardinalidad_de_S_prima; j++){ //itera todos los elementos en S'
			if (S[j].W + wi[i] <= M) //Si al sumarle el peso del elemento i al peso en la tupla j de S es < M
   			{
   				agregar_dupla(S[j].P+pi[i], S[j].W+wi[i]); // Se agrega si no excede capacidad de la mochila
   				//agregar_solucion(i, j);
  			}	
  			
		} // FIN FOR |S'|
		printf("S'_%d = {", i+1);
		imprimir_duplas();		
		printf("}\n");
		
		//Eliminar duplas
		for (j=1; j<cardinalidad_de_S-1; j++){
			for (h=j+1; h< cardinalidad_de_S; h++){
				if (S[j].P >= S[h].P && S[j].W <= S[h].W){
					eliminar_dupla(h);
					h--;
				}else if (S[j].P <= S[h].P && S[j].W >= S[h].W){
					eliminar_dupla(j);
					j--;
					break;
				}
			}
			
		}
		printf("S_%d = {",i+1);
		imprimir_duplas();		
		printf("}\n");
	}
	
	printf ("\nMax P es: %d", obtener_maxP());
	printf("\nLa solucion es:\n");
	agregar_solucion(i, j);
	obtener_solucion();
	
	return 0;
}

void agregar_dupla(int P, int W){
	S[cardinalidad_de_S].P = P;   /* Agrega la tupla (P, W) */
 	S[cardinalidad_de_S].W = W;	/* al conjunto S */
 	
 	for (int b=0; b<n; b++){
		S[cardinalidad_de_S].X[b]=S[j].X[b];
	}
	S[cardinalidad_de_S].X[n-1-i] = 1;
 	
 	cardinalidad_de_S++;		// Aumenta la cardinalidad del conjunto al agragar nuevo elemento
}

void imprimir_duplas (){
	printf ("(%d, %d)", S[0].P, S[0].W);
	for (int ii=1; ii<cardinalidad_de_S ;ii++){
		printf (", (%d, %d)", S[ii].P, S[ii].W);
	}		
}

void eliminar_dupla(int dupla_a_eliminar) {
	int jj = dupla_a_eliminar;
 	while( jj < cardinalidad_de_S)
 	{
  		S[jj].P=S[jj+1].P;			/*	Recorre posiciones	*/
  		S[jj].W=S[jj+1].W;			/*	eliminando la dupla	*/
  		for (int w=0; w<n; w++){
  			S[jj].X[w] = S[jj+1].X[w];
		}

		jj++;
 	}
	cardinalidad_de_S--;
} 

int obtener_maxP (){
	int maxP = 0;
	for (i = 0; i < cardinalidad_de_S; i++){
		if (S[i].P > maxP){
			maxP = S[i].P;
		}
	}
	return maxP;
}

void obtener_solucion (){
	int maxP = 0, temp;
	for (i = 0; i < cardinalidad_de_S; i++){
		if (S[i].P > maxP){
			maxP = S[i].P;
			temp = i;
		}
	}
	printf ("(");
	for (i=0; i<n; i++){
		printf ("%d, ", S[temp].X[n-1-i]);
	}
	printf (")");
}

void agregar_solucion(int i, int j){
	
	for (int b=0; b<n; b++){
		S[cardinalidad_de_S_prima + j].X[b]=S[j].X[b];
	}
	S[cardinalidad_de_S_prima + j].X[n-1-i] = 1;
		
	
}

void imprimir_solucion() {
	
	for (int a=0; a<cardinalidad_de_S; a++){
		for (int ii=0; ii<n ;ii++){
			printf ("%d, ", S[a].X[ii]);
		}
		printf("\n");
	}
			
	printf(")\n");
}
