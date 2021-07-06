#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000
//MAX foi editado para 50.000 e 100.000 para fazer a contagem

//selecion sort
void selection_sort(int vetor[], int a)
{
int x, y, aux, xy;
for (x=0; x < a-1; x++){
  xy = x;
  for (y=x+1; y<a; y++)
  {
    if (vetor[xy] > vetor[y])
    {
      xy = y;
    }
  }
  aux = vetor[x];
  vetor[x] = vetor[xy];
  vetor[xy] = aux;
  }
}
//Insertion sort 
void insertionSort(int vetor[],int a)
{
 int x, j, num;
 for(x = 1; x < a; x++){
  num = vetor[x];
  for(j = x-1; j >= 0 && num < vetor[j]; j--){
   vetor[j+1] = vetor[j];
  }
  vetor[j+1] = num;
 }
}
//bubble sort:
void bubbleSort (int vetor[], int a) 
{
int x, y, aux, flag;
for (x = 1; x < a; x++){
  flag = 0;
  for (y = 0; y < a - 1; y++)
  {
    if (vetor[y]>vetor[y+1])
    {
      aux=vetor[y];
      vetor[y]=vetor[y+1];
      vetor[y+1]=aux;
      flag=1;
    }
  }
    if(flag == 0)
    {
      break;
    }
  }
}
int main (){ 
  int array[MAX];
  int x, i, aux, j;
  clock_t start, end;
//array com numeros aleatorios  
/*srand(time(NULL));
  for(x=0; x < MAX; x++)
  {
    array[x] = rand () % 100000; 
  } */
//array com numeros crescentes 
  for(x = 0; x < MAX; x++){
    array[x] = x; 
  } 
//array com numeros decrescentes
/*for( x =0 ; x < MAX; x++){
    array[x] = MAX - x;  
  } */
    
//APLICANDO: selectionSort;
/*start = clock();
  selection_sort(array, MAX);
  end = clock(); */

//APLICANDO: bubbleSort;
  start = clock();
  bubbleSort(array, MAX);
  end = clock(); 

//APLICANDO: insertionSort;
/*
  start = clock();
  insertionSort(array, MAX);
  end = clock(); 
*/
/* foram comentados os elementos do codigo que não estavam em execução para não causarem conflito enquando cada um era testado.*/

//SAIDA:
    printf("\n\n after sorted: \n\n");
    for (i=0; i < MAX; i++)
    {
      printf("%d ", array[i]);
    }
    printf("\n\n Time before: %lf ms", (( double )start)/ (( CLOCKS_PER_SEC )));
    printf("\n Time after: %lf ms", (( double )end)/ (( CLOCKS_PER_SEC )));
    double diftime = (( double ) end - start ) / CLOCKS_PER_SEC;
    printf("\n Time difference in seconds: %lf", diftime);
    printf("\n Time difference in ms: %lf", diftime*1000);
    return 0;
}
