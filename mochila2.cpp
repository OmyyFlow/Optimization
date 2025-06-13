//librerias
#include <iostream>  //c++

using namespace std;

//======================================================================
//Instancia:
int M = 12;
int P[] = {10, 5, 2, 4, 6};
int W[] = {2, 3, 5, 1, 4};
//======================================================================

//Matriz de tuplas
int **S;	// S_j
int t_S=0;	// t_S: tamaño de S_j
            // Para llevar un control de las tuplas insertadas en matriz S
            // o sea, el número de columnas. 
            
void agregar_tupla(int p_i, int w_i)
{
 S[0][t_S]=p_i;
 S[1][t_S]=w_i;
 t_S=t_S+1;
}

void quitar_tupla(int h)
{
 for (int l=h; l<t_S-1; l++)
 {
  S[0][l]=S[0][l+1];
  S[1][l]=S[1][l+1];
 }
 t_S=t_S-1;
} 

void mostrar_tuplas(int j, bool prima)
{
 cout << "S";
 if (prima==true) cout << "'";
 cout << "_"<< j+1 << "={ ";
 for (int l=0; l<t_S; l++)
 {
  cout << "(" << S[0][l] << "," << S[1][l] << ")";
  if (l<t_S-1) cout << ", ";  
 }
 cout << " }" << endl;
}

int main(void)
{

 int n= sizeof(W)/sizeof(W[0]);	    // n: Cantidad de objetos en la instancia
 cout << "Cantidad de objetos: " << n << endl;

 // Declarando el tamaño de la matriz S
 S=new int*[2];		// Agregando 2 filas a matriz S
  S[0]=new int[4*M];  // Agregando (4 veces M) columnas a cada fila de matriz S
  S[1]=new int[4*M];

 //ejemplo:
 //            1   2   ...   M
 // S=       -------------------
 //     p_i  |   |   | ... |   |   = La primer fila son los beneficios
 //     w_i  |   |   | ... |   |   = la segunda fila son los pesos
 //          -------------------

 int j=0;	// j indica 

 agregar_tupla(0,0);	
 agregar_tupla(P[0], W[0]);
 mostrar_tuplas(j,false); 
 j=j+1;
 
 while(j<n)
 {

  // Agregando nuevas tuplas:
  int t_S_jm1 = t_S;	// t_Sm1: tamaño de conjunto S_{j-1}
  for (int k=0; k<t_S_jm1; k++)
  {
   if (S[1][k] + W[j] <= M)
   {
    agregar_tupla(S[0][k] + P[j], S[1][k] + W[j]);
   }
  }

  mostrar_tuplas(j,true);


  //Depurando tuplas:
  int l=0;
  while (l < t_S-1)
  {
   int h=l+1;
   bool flag=false;
   while (h<t_S)
   {
    if( (S[0][l]>=S[0][h]) and (S[1][l]<=S[1][h]) )
    {
     quitar_tupla(h);
    }
    else if( (S[0][h]>=S[0][l]) and (S[1][h]<=S[1][l]) )
    {
     quitar_tupla(l);
     flag=true;
     break;
    }
    else
    {
     h=h+1;
    } 
   }
   if (flag==false)
   {
    l=l+1;
   }
   else
   {
    flag=false;
   }
   
  }
  mostrar_tuplas(j,false);
  j=j+1;
 }

 // Buscar ganancia máxima:
 int P_max=0;
 for (int l=0; l<t_S; l++)
 {
  if (S[0][l]>P_max)
  {
   P_max=S[0][l];
  }  
 }

 //Mostrar ganancia máxima:  
 cout << "Ganancia máxima = " << P_max << endl;
	
 return 0;
}
 





