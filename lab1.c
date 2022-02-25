#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

//--------------------------------------------------------------------------
//funciya randomnogo zapolneniya massiva
int getrand(int min, int max)                                                   
{
return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
//podschet vremeni
double wtime()                                                                  
{
struct timeval t;
gettimeofday(&t, NULL);
return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
//swap
void swap(int *x, int *y)
  {
   int temp;
   temp = *x;                                                                   
   *x = *y;                                                                     
   *y = temp;
  }
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
//nahozdenie max elementa massiva
int findMax(int a[], int n)
{
    int m = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > m)
            m = a[i];
    return m;
}
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
//countingSort
void countingSort(int a[], int n, int place)
{
    int *b;
    int *c;
    b = (int*)malloc(sizeof(int)*n);
    c = (int*)malloc(sizeof(int)*n);
    int i; 
    b[n] = 0;                                                  
 
    for (int i = 0; i < n; i++)
    {
        b[(a[i] / place) % 10]=b[(a[i] / place) % 10] + 1;
    }
 
    for (int i = 1; i < 10; i++)
    {
       b[i] += b[i - 1]; 
    }
 
    for (int i = n - 1; i >= 0; i--) 
    {
        c[b[(a[i] / place) % 10] - 1] = a[i];
        b[(a[i] / place) % 10]=b[(a[i] / place) % 10] - 1;
    }
 
    for (int i = 0; i < n; i++)
    {
        a[i] = c[i];
    }
}
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
//radixsort
void radixsort(int a[], int n, int max)
{
    max=findMax(a,n);
   for (int place=1;max/place>0;place*=10)
   {
        countingSort(a,n,place);  
   }
   //free(b);
   //free(c);
}
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
//heapify
  void heapify(int a[],int n,int i)
{
    int l=(2*i)+1;
    int r=(2*i)+2;
    int max=i;
    if(l<n && (a[l] > a[max]))
    {
        max=l;
    }
    
    if(r<n && (a[r] > a[max]))
    {
        max=r;
    }
    if(max!=i)
    {
        swap(&a[i],&a[max]);
        heapify(a,n,max);
    }
}
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
//HeapSort
void HeapSort(int a[], int n)
{
    for(int i=n/2-1;i>0;i--)
    {
        heapify(a,n,i);
    }
        for(int i=n-1;i>0;i--)
    {
        swap(&a[0],&a[i]);
        heapify(a,i,0);
    }
}
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
//selectionSort
void selectionSort(int a[],int n)                                               
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
//--------------------------------------------------------------------------
//funciya vivoda massiva
void printA(int a[],int n)                                                      
{
  for (int i=0;i<n;i++)
  {
    printf("%d ",a[i]);
  }
  printf("\n");
  printf("\n");                                                                 //otsupi dlya krasoti
  printf("\n");
}
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
//funciya randomnogo zapolneniya massiva
void randomA(int a[],int n, int min, int max)                                   
{
  int i;
  for (i=0;i<n;i++)
  {
    a[i]=getrand(min,max);
    //printf("%d ",a[i]);
  }
  printf("\n");
} 
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// proverka min and max
int proverkaMIN_MAX(int min, int max)                                           
{
    
   if (min>max)   
   {           
      return 1; 
   }
 return 0; 
}
//--------------------------------------------------------------------------


int main ()
{
  int max=100000, min=0;
  printf("Vvedite min, max znacheniya: ");                                      
  //scanf("%d %d",&min,&max);
  printf("\n");
  
  while (1)
  {
      if (proverkaMIN_MAX(min, max))
      {
          printf("Error, vvedite zanogo: ");
          scanf("%d %d",&min,&max);
      }
      else 
      {
          break;
      }
      
  }
  
  double sec_start, sec_end, sec;                                               //obyavlenie peremennih dlya podscheta vremeni
  int n = 0, i=0;
  int *a;
  printf("Razmer: ");
  scanf("%d",&n);
  
  a=(int*)malloc(sizeof(int)*n);                                                //videlenie razmera dlya massiva

  randomA (a,n,min,max);
  findMax(a,n);
  sec_start=wtime();
  radixsort(a,n,max);
  sec_end=wtime();
  sec=sec_end-sec_start;
  printf("Radix sort: kollichestvo elementov %d, Time: %f seconds",n,sec);  
  printf("\n");
  
  randomA (a,n,min,max);
  sec_start = wtime();                                                          //nachalo podscheta vremeni
  //selectionSort (a,n);                                                          //vizov sortirovki
  sec_end = wtime();                                                            //konec podscheta vremeni
  sec = (sec_end - sec_start);                                                  //kostil'
  //printA(a,n);                                                                 //vizov vivoda massiva
  printf("Selection sort: kollichestvo elementov %d, Time: %f seconds",n,sec);  
  printf("\n");
  
  randomA (a,n,min,max);
  sec_start = wtime();
  HeapSort (a,n);
  //printA(a,n);
  sec_end = wtime();
  sec = (sec_end - sec_start);
  //printA(a,n);
  printf("Heap sort: kollichestvo elementov %d, Time: %f seconds",n,sec);
 
  free(a);                                                                         //ochistka pamyati 
return 0;
}
