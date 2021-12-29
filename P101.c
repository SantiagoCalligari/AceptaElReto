#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
int consMagica2(int lados, int cuadrado[1024][1024], int constanteUno)
{
    int filas, columnas, constanteMagicaOriginal;
    int sumaEsquinas, sumaCentros, centro; 
    constanteMagicaOriginal = (4*constanteUno)/lados;
    sumaEsquinas = cuadrado[0][0] + cuadrado[0][lados-1] + cuadrado[lados-1][lados-1] + cuadrado[lados-1][0];
    if((lados % 2) == 0)
    {    
        sumaCentros = cuadrado[0][lados/2] + cuadrado[0][(lados/2)-1] + cuadrado[lados-1][lados/2] + cuadrado[lados-1][(lados/2)-1] + cuadrado[lados/2][0] + cuadrado[(lados/2)-1][lados-1] + cuadrado[lados/2][lados-1] + cuadrado[(lados/2)-1][0];
        sumaCentros = sumaCentros/2;
        centro = cuadrado[lados/2][lados/2] + cuadrado[(lados/2)-1][lados/2] + cuadrado[(lados/2)-1][(lados/2)-1] + cuadrado[lados/2][(lados/2)-1];
    }else
        {
           sumaCentros = cuadrado[0][lados/2] + cuadrado[lados-1][lados/2] + cuadrado[lados/2][0] + cuadrado[lados/2][lados-1];
           centro = 4*cuadrado[(lados/2)][lados/2];
        }
    return (sumaCentros == sumaEsquinas && sumaCentros == constanteMagicaOriginal && constanteMagicaOriginal == centro) ? 1 : 0;
}
int cifrasIgualCasillas(int lados, int cuadrado[1024][1024])
{
    int i, filas, columnas,j;
    int existe = 0;
    for( i = 0; i < lados*lados; i++ )
    {
        j = i+1;
        for(columnas = 0; columnas < lados; columnas++)
        {
            for(filas = 0; filas < lados; filas++)
            {
                if(j==cuadrado[columnas][filas])
                {
                    existe++;
                    columnas = filas = 1024;
                }
            }
        }
    }
    return (existe==lados*lados) ? 1 : 0;
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
        printf("\n");
    }
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
       n==0 ? continuar=0 : continuar;
       rellenarCuadrado(n, cuadrado);
       calcularMagico(n,cuadrado, resultados);
       //mostrarCuadrado(n, cuadrado, resultados); //consMagica2 devuelve 1, comprobarMagico  devuelve 1, 
       if(comprobarMagico(n,resultados))
       {
            if(cifrasIgualCasillas(n,cuadrado))
                printf("\n%s\n",consMagica2(n,cuadrado,resultados[0][0])?"ESOTERICO":"");
            else
            {
                printf("\nDIABOLICO\n");
            }
       }else
            printf("\nNO\n");
    }
    return 0;
//4
//16 3 2 13 5 10 11 8 9 6 7 12 4 15 14 1 
}