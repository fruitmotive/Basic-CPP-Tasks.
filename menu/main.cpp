#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

struct item
{item *next,*prev;
int cur;
char name[20];
void (*action)();
void (*actionE)(item*);
int fin;};

void func1()
{system("cls");
cout<<"func 1 has worked!"<<endl;
getch();}

void func2()
{system("cls");
cout<<"func 2 has worked!!"<<endl;
getch();}

void func3()
{system("cls");
cout<<"func 3 has worked!!!"<<endl;
getch();}

void func4()
{system("cls");
cout<<"func 4 has worked!!!!"<<endl;
getch();}

void func5()
{exit(0);}

void free(item *d)
{item *p = d;
while(!(d->fin))
{p=d;
delete(p);
d=d->next;}
delete(d);
exit(0);}

void rev(item *p, char*a, void (*act)())
{item *c, *n;
c = new item;
n=p;
c->cur=0;
sprintf(c->name,a);
while(!(n->fin))
{n=n->next;}
n->next=c;
c->next=p;
p->prev=c;
c->prev=n;
n->fin=0;
c->fin=1;
c->action = act;}

item* making_of_list()
{item *p;
p=new item;
p->cur=1;
sprintf(p->name,"func 1");
p->action=func1;
p->fin=1;
p->next=p;
p->prev=p;
rev(p,"func 2", func2);
rev(p,"func 3", func3);
rev(p,"func 4", func4);
rev(p,"click to exit"  , func5);
return p;}

void func_of_menu(item *t)
{char choice;
item *c;
do
{c=t;
system("cls");
while(!(c->fin))
{cout<<"(";
if(c->cur)
{cout<<"x";}
else cout<<" ";
cout<<")"<< c->name << endl;
c = c->next;}
cout<<"(";
if(c->cur) cout<<"x)"<<c->name;
else cout<<" )"<<c->name;
choice=getch();
if(choice==13)
{while(1)
{if(c->cur)
{if((c->fin)==1) free(c);
else c->action();
break;}
c=c->next;}}
if(choice==72)
{while(1)
{if(c->cur)
{(c->prev)->cur=1;
c->cur=0;
break;}
c=c->prev;}}
if(choice==80)
{while(1)
{if(c->cur)
{(c->next)->cur=1;
c->cur=0;
break;}
c=c->next;}}}
while(1);}

int main()
{func_of_menu(making_of_list());
return 0;}
