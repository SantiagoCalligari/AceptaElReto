#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
int ascOrd(int numRoto[])
{
    int i, aux, j, numDescom[4];
    for ( i=0; i<4; i++)
    numDescom[i] = numRoto[i];
    for ( j=0; j<4; j++)
    for( i=0; i<3; i++)
    {
        if(numDescom[i]>numDescom[i+1])
        {
            aux = numDescom[i];
            numDescom[i] = numDescom[i+1];
            numDescom[i+1] = aux;
        }
    }
   return numDescom[0]*1000 + numDescom[1]*100 + numDescom[2]*10 + numDescom[3] ;
}

int descOrd(int numRoto[])
{
    int i, aux, j, numDescom[4];
    for ( i=0; i<4; i++)
    numDescom[i] = numRoto[i];
    for ( j=0; j<4; j++)
    for( i=0; i<3; i++)
    {
        if(numDescom[i]<numDescom[i+1])
        {
            aux = numDescom[i];
            numDescom[i] = numDescom[i+1];
            numDescom[i+1] = aux;
        }
    }
  // printf("%i" numDescom[0]*1000 + numDescom[1]*100 + numDescom[2]*10 + numDescom[3]);
   return numDescom[0]*1000 + numDescom[1]*100 + numDescom[2]*10 + numDescom[3] ;
} 

void descomponer(char input[], int NumeroDescompuesto[])
{       
    char aux[1];
    int i, numDesc, numAsc;
    for( i=0; i<4; i++)
    {
        aux[0] = input[i];
        NumeroDescompuesto[i] = atoi(aux);
    }
}

void itoaa(long i, char *string)
{
	int power = 0, j = 0;
 
	j = i;
	for (power = 1; j>10; j /= 10)
		power *= 10;
 
	for (; power>0; power /= 10)
	{
		*string++ = '0' + i / power;
		i %= power;
	}
	*string = '\0';
}

int krepreakar(int input[], int ciclos)
{
   char tostr[4],keprekar[4];
   int iteracion[4],aa[4], i, asc, desc;
   i = input[0]*1000 + input[1]*100 + input[2]*10 + input[3];
   if(i==6174)
   return ciclos;
   else
  // {
    //return ciclos;
  // }
       if(input[1]==input[2] && input[3] == input[0] && input[1] == input[3])
       {
        return 8;
       }
       else
       {
           desc = descOrd(input);
           asc = ascOrd(input);
           itoaa(desc-asc, tostr);
           descomponer(tostr, iteracion);
           ciclos = ciclos + 1;
           krepreakar(iteracion, ciclos);
       }
}

int main()
{
   char input[50][50];
   int numDesc[5], c, i;
   scanf("%i", &c);
   for( i=0; i<c; i++)
   {
    scanf("%s", &input[i]);
   }
   for( i=0; i<c; i++)
   {
    descomponer(input[i], numDesc);
    printf("%i\n",krepreakar(numDesc, 0));
   }
   return 0;
}