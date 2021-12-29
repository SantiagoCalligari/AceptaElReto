#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
int encontrarMayor(int cuadrado[1024][1024], int lados)
{
    int columnas, filas, mayor;
    columnas = filas = 0;
    for( columnas = 0; columnas < lados; columnas++)
    {
        for( filas = 0; filas < lados; filas++)
        {
          if(filas=columnas=0)
            mayor = cuadrado[columnas][filas];
           else
            if(mayor < cuadrado[columnas][filas])
                mayor = cuadrado[columnas][filas];
        }
    }
    return mayor; 
}
int comprobarMagico(int lados, int resultados[2][1025])
{
    int i, bandera, j;
    bandera = 1;
    for( i = 0; i < lados; i++ )
    {
        if(i+1 != lados)
            j = i+1;    
        if ( (resultados[0][i] != resultados[0][j]) || (resultados[0][i] != resultados[1][j]))
        {
            bandera = 0;
            i = lados;
        }
    }
    return bandera;
}

void mostrarCuadrado(int lados, int cuadrado[1024][1024], int resultados[2][1025])
{
    int columnas, filas;
    printf("\n");
    for( columnas = 0; columnas < lados; columnas++)
    {
        for( filas = 0; filas < lados; filas++)
        {
          printf("%4i", cuadrado[columnas][filas]);
        }
        printf("= %i", resultados[0][columnas]);
        printf("\n");
    }

    for( columnas = 0; columnas < lados; columnas++)
            printf("%4i", resultados[1][columnas]);
}

void calcularMagico(int lados, int cuadrado[1024][1024], int resultados[2][1025])
{
    int columnas, filas, suma, diag1, i, bandera = 0;
    
    
    //suma de las filas y las columnas, se guardan en su lugar.
    for( columnas = 0; columnas < lados; columnas++)
    {
        suma = 0;
        for( filas = 0; filas < lados; filas++)
        {
          suma = cuadrado[columnas][filas] + suma;
        }
        resultados[0][columnas] = suma;
    }
    
    
    for( filas = 0; filas < lados; filas++)
    {
        suma = 0;
        for( columnas = 0; columnas < lados; columnas++)
        {
          suma = cuadrado[columnas][filas] + suma;
        }
        resultados[1][filas] = suma;
    }
    
    
    // suma de las diagonales, se guardan uno mas adelante que la cantidad de lados;
    suma = 0;
    for (i = 0; i < lados; i++)
    {   
        suma = cuadrado[i][i] + suma;
    }
        resultados[0][lados] = suma;
    
    suma = 0;
    for (i = lados; i > 0; i--)
    {   
        suma = cuadrado[i][i] + suma;
    }
    resultados[1][lados] = suma;
}

void rellenarCuadrado(int lados, int cuadrado[1024][1024])
{
    int columnas, filas;
    for( columnas = 0; columnas < lados; columnas++)
    {
        for( filas = 0; filas < lados; filas++)
        {
          scanf("%i", &cuadrado[columnas][filas]);
        }
    }
}

int main()
{
    int cuadrado[1024][1024], resultados[2][1025], continuar, n;
    continuar = 1;
    while (continuar)
    {
       scanf("%i", &n);
       !n ? continuar=0 : continuar;
       rellenarCuadrado(n, cuadrado);
       calcularMagico(n,cuadrado, resultados);
       mostrarCuadrado(n, cuadrado, resultados);
       //printf("\n%i", encontrarMayor(cuadrado, n));       
    }

    return 0;
//4
//16 3 2 13 5 10 11 8 9 6 7 12 4 15 14 1 
}