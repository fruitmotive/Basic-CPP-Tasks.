#include<stdio.h>
#include<stdlib.h>

void massive (int* a, int n, int i)
{a[i] = rand()%90+10; i++;
if (i>n)
return;
else
massive(a,n,i);}

int  smassive (int i, int n, int j, int c, int d, int *a, int *b)
{if(n<2)
{b[i]=a[j];
return a[j];}
else
{c=smassive(2*i+1,n/2,j,0,0,a,b);
d=smassive(2*i+2,n/2,j+n/2,0,0,a,b);
if (c>=d)
{b[i]=c;
return c;}
else
{b[i]=d;
return d;}}}

void output (int* a, int i, int n)
{printf("%d ",a[i]); i++;
if (i>n)
return;
else
output(a,i,n);}

int main()
{int* a; int* b;
int n;
srand(time(NULL));
printf("demension: "); scanf("%d",&n);
a = (int *)malloc(n*sizeof(int));
b = (int *)malloc((n*2-1)*sizeof(int));

massive (a,n-1,0);
printf("non-sorted massive: ");
output (a,0,n-1);

smassive (0,n,0,0,0,a,b);
printf("\nsorted massive: ");
output (b,0,2*n-2);

free(a);free(b);}

