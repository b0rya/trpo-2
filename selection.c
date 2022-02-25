#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


int getrand(int min, int max)                                                   //funciya randomnogo zapolneniya massiva
{
return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

double wtime()                                                                  //podschet vremeni
{
struct timeval t;
gettimeofday(&t, NULL);
return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

void selectionSort(int a[],int n)                                               //sortirovka vstavkoj
{

  int mini=0,tmp=0,i,j;
    for (i=0;i<n-1;i++)
    {
       mini=i;

      for (j=i+1;j<n;j++)
      {
        if (a[j]<a[mini])
        {
          mini=j;
        }
      }

      tmp = a[i];
      a[i]=a[mini];
      a[mini]=tmp;
    }

}

void printA(int a[],int n)                                                      //funciya vivoda massiva
{
  for (int i=0;i<n;i++)
  {
    printf("%d ",a[i]);
  }
  printf("\n");
  printf("\n");                                                                 //otsupi dlya krasoti
  printf("\n");
}

void randomA(int a[],int n, int min, int max)                                   //funciya randomnogo zapolneniya massiva
{
  int i;
  for (i=0;i<n;i++)
  {
    a[i]=getrand(min,max);
    printf("%d ",a[i]);
  }
  printf("\n");
  printf("\n");                                                                 //otsupi dlya krasoti
  printf("\n");

} 

int proverkaMIN_MAX(int min, int max)                                           // proverka min and max
{

   if (min>max)
   {
      return 1;
   }
 return 0;
}


int main ()
{
  int max, min;
  printf("Vvedite min, max znacheniya: ");
  scanf("%d %d",&min,&max);
  printf("\n");

  while (1)
  {
      if (proverkaMIN_MAX(min, max))
      {
          printf("Error, vvedite zanogo");
          scanf("%d %d",&min,&max);
      }
      else
      {
          break;
      }

  }

  double sec_start, sec_end, sec;                                               //obyavlenie peremennih dlya podscheta vremeni
  int n;
  int *a;
  printf("Razmer: ");
  scanf("%d",&n);
  a=(int*)malloc(sizeof(int)*n);                                                //videlenie razmera dlya massiva
  

  
  
  int i;
  for (i=0;i<n;i++)
  {
    a[i]=getrand(min,max);
    printf("%d ",a[i]);
  }
  printf("\n");
  printf("\n");                                                                 //otsupi dlya krasoti
  printf("\n"); 
  //randomA (a,n,min,max);
  sec_start = wtime();                                                          //nachalo podscheta vremeni
  selectionSort (a,n);                                                          //vizov sortirovki
  sec_end = wtime();                                                            //konec podscheta vremeni
  sec = (sec_end - sec_start);                                                  //kostil'

  printA(a,n);                                                                  //vizov vivoda massiva


  printf("Time: %f seconds", sec);
  free(a);                                                                      //ochistka pamyati


return 0;
}
