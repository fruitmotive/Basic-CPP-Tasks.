#include <stdio.h>
#include <stdlib.h>

void massive (int* a, int n, int i)
{a[i] = rand()%90+10;
printf("%d ",a[i]);
i++;
if (i>n)
return;
else

massive(a,n,i);}

void last_symbols (int* c, int* a, int i, int j,int n)
{c[i]=a[j];
i++; j++;
if (j>n)
return;
else
last_symbols(c,a,i,j,n);}

void addition (double n, int k, int* c, int i, int j)
{if (n>=1)
{if (k<n)
{if (c[j]>c[j+1])
{c[i]=c[j];}
else
{c[i]=c[j+1];}
i++; j=j+2; k++;
addition(n,k,c,i,j);}
else
{i=i-n-n/2;j=j-2*n-n;n=n/2;k=0;
addition(n,k,c,i,j);}}
else
return;}

void output (int* c, int i, int n)
{printf("%d ",c[i]);
i++;
if (i>n)
return;
else
output(c,i,n);}

int main()
{int* a; int* c;
int n;
srand(time(NULL));
printf("demension: "); scanf("%d",&n);
a = (int *)malloc(n*sizeof(int));
c = (int *)malloc((n*2-1)*sizeof(int));

printf("non-sorted massive: ");
massive(a,n-1,0);

last_symbols(c,a,n-1,0,n-1);

addition(n/2,0,c,n-n/2-1,n-1);

printf("\nsorted massive: ");
output(c,0,2*n-2);

free(a);
free(c);}
