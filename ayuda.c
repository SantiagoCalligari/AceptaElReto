#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _SNodo {
  int num;
  struct _SNodo *abajo;
  struct _SNodo *der;
} SNodo;
void liberar(SNodo* cuadrado, int lados)
{
  SNodo *temp, *sigLinea;
  temp = sigLinea = cuadrado;
  while(cuadrado->der!=NULL || cuadrado->abajo!=NULL)
  {
    SNodo *antecesor = temp;
    for(int j=0; temp->abajo!=NULL;j++)
    {
      if (j!=0) antecesor = antecesor->abajo;
      temp = temp->abajo;
    }
    if(temp==antecesor) antecesor = &cuadrado;
      while(temp->der!=NULL)
      {
        SNodo *aux = temp;
        SNodo* pred = temp;
        for(int i=0;temp->der!=NULL;i++)
        { 
          if(i!=0) pred = pred->der;
          temp = temp->der; 
        }
        pred->der=NULL;
        free(temp);
        temp = aux;
      }
      antecesor->abajo = NULL;
      if(cuadrado->abajo != NULL)
        free(temp);
      temp = cuadrado;
  }
  free(cuadrado);
}

void MostrarCuadrado(SNodo* cuadrado)
{
  SNodo* temp, *temp2;
  temp = cuadrado;
  while(temp != NULL)
  {
    temp2 = temp;
    while(temp2 != NULL)
    {
      printf("%d",temp2->num);
      temp2=temp2->der;
    }
    printf("\n");
    temp = temp->abajo;
  }
}
//Todos los datos agregados//
SNodo* apuntarAbajo(SNodo* cuadrado)
{
  SNodo* temp, *sig, *abajo;
  temp = abajo = cuadrado;
  while(abajo->abajo!=NULL)
  {
    sig = abajo->abajo;
    while(temp!=NULL)
    {
      temp->abajo = sig;
      temp = temp->der;
      sig = sig->der;
    }
    abajo = abajo->abajo;
    temp = abajo;
  }
  return cuadrado;
}
SNodo* agregarDatos(SNodo* cuadrado, int dato)
{
  SNodo* nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->num = dato;
  nuevoNodo->der = NULL;
  nuevoNodo->abajo = NULL;
  if(cuadrado == NULL) return nuevoNodo;
  else
  {
    SNodo* temp = cuadrado;
    for(;temp->der != NULL;temp=temp->der);
    temp->der = nuevoNodo;
  }
  return cuadrado;
}
SNodo* rellenarFila(int lados, SNodo* cuadrado)
{
  int numero,filas = 0;
  for(filas; filas < lados; filas++)
  {
    scanf("%d", &numero);
    cuadrado = agregarDatos(cuadrado, numero);
  }
  return cuadrado;
}
SNodo* rellenarCuadrado(int lados, SNodo* cuadrado)
{
  int columnas = 0;
  for(columnas;columnas<lados;columnas++)
  {
    if (cuadrado==NULL)
    {
      cuadrado = rellenarFila(lados,cuadrado);
    }else
    {
      SNodo* temp = cuadrado;
      for(;temp->abajo != NULL; temp = temp->abajo);
      temp = rellenarFila(lados, temp->abajo);
      SNodo* ultratemp = cuadrado;
      for(;ultratemp->abajo; ultratemp=ultratemp->abajo);
      ultratemp->abajo = temp;
    }
  }
  return cuadrado;
}
//         Datos          //
void principal(SNodo* cuadrado)
{
  int n;
  scanf("%d", &n);
  if(n)
  {
    cuadrado = rellenarCuadrado(n, cuadrado);
    cuadrado = apuntarAbajo(cuadrado);
    MostrarCuadrado(cuadrado);
    liberar(cuadrado,n);
    principal(cuadrado);
  }
}
int main()
{
  SNodo* cuadrado = NULL;
  principal(cuadrado);
  return 0;
}