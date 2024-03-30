#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void push(char *,int *,char);
char stacktop(char *);
void isproduct(char,char);
int ister(char);
int isnter(char);
int isstate(char);
void error();
void isreduce(char,char);
char pop(char *,int *);
void printt(char *,int *,char [],int);
void rep(char [],int);
struct action
{
char row[3][5];
};
struct action A[10]={
{"sd","se","emp"},
{"emp","emp","acc"},
{"sg","sh","emp"},
{"sd","se","emp"},
{"rd","rd","rd"},
{"emp","emp","rb"},
{"sg","sh","emp"},
{"rd","rd","rd"},
{"rc","rc","rc"},
{"rc","rc","rc"}
};
struct goto_t
{
char r[2][5];
};
struct goto_t G[10]={
{"b","c"},
{"emp","emp"},
{"emp","f"},
{"emp","i"},
{"emp","emp"},
{"emp","emp"},
{"emp","j"},
{"emp","emp"},
{"emp","emp"},
{"emp","emp"}
};
char ter[6]={'p','q','$'};
char nter[3]={'S','A'};
char states[12]={'a','b','c','d','e','f','g','h','i','j'};
char stack[100];
int top=-1;
char temp[10];
struct grammar
{
char left;
char right[5];
};
const struct grammar rl[3]={
{'S',"AA"},
{'A',"pA"},
{'A',"q"}
};
int main()
{
char name[20];
char rollno[20];
printf("\nEnter  the Name of the Student:");
scanf("%s",name);
printf("\nEnter the Roll Number of the Student:");
scanf("%s",rollno);
printf("\n Name of the Student is:%s",name);
printf("\n Roll no of the Student is:%s",rollno);
char inp[80],x,p,dl[80],y,bl='a';
int i=0,j,k,l,n,m,c,len;
printf(" \nEnter the String  be Parsed :");
scanf("%s",inp);
len=strlen(inp);
inp[len]='$';
inp[len+1]='\0';
push(stack,&top,bl);
printf("\n STACK \t\t\t INPUT");
printt(stack,&top,inp,i);
do
{
x=inp[i];
p=stacktop(stack);
isproduct(x,p);
if(strcmp(temp,"emp")==0)
error();
if(strcmp(temp,"acc")==0)
break;
else
{
if(temp[0]=='s')
{
push(stack,&top,inp[i]);
push(stack,&top,temp[1]);
i++;
}
else
{
if(temp[0]=='r')
{
j=isstate(temp[1]);
strcpy(temp,rl[j-2].right);
dl[0]=rl[j-2].left;
dl[1]='\0';
n=strlen(temp);
for(k=0;k<2*n;k++)
pop(stack,&top);
for(m=0;dl[m]!='\0';m++)
push(stack,&top,dl[m]);
l=top;
y=stack[l-1];
isreduce(y,dl[0]);
for(m=0;temp[m]!='\0';m++)
push(stack,&top,temp[m]);
}
}
}
printt(stack,&top,inp,i);
}while(inp[i]!='\0');
if(strcmp(temp,"acc")==0)
printf(" \n The Given Input String is Successfully Parsed ");
else
printf(" \n Do Not Accept the Input String ");
getch();
}
void push(char *s,int *sp,char item)
{
if(*sp==100)
printf(" Stack is Full ");
else
{
*sp=*sp+1; s[*sp]=item;
}
}
char stacktop(char *s)
{
char i;
i=s[top];
return i;
}
void isproduct(char x,char p)
{
int k,l;
k=ister(x);
l=isstate(p);
strcpy(temp,A[l-1].row[k-1]);
}
int ister(char x)
{
int i;
for(i=0;i<6;i++)
if(x==ter[i])
return i+1;
return 0;
}
int isnter(char x)
{
int i;
for(i=0;i<3;i++)
if(x==nter[i])
return i+1;
return 0;
}
int isstate(char p)
{
int i;
for(i=0;i<12;i++)
if(p==states[i]) return i+1;
return 0;
}
void error()
{
printf(" Unable to Parse the the Input string ");
exit(0);
}
void isreduce(char x,char p)
{
int k,l;
k=isstate(x);
l=isnter(p);
strcpy(temp,G[k-1].r[l-1]);
}
char pop(char *s,int *sp)
{
char item;
if(*sp==-1)
printf(" Stack is Empty ");
else
{
item=s[*sp];
*sp=*sp-1;
}
return item;
}
void printt(char *t,int *p,char inp[],int i)
{
int r;
printf("\n");
for(r=0;r<=*p;r++)
rep(t,r);
printf("\t\t\t");
for(r=i;inp[r]!='\0';r++)
printf("%c",inp[r]);
}
void rep(char t[],int r)
{
char c;
c=t[r];
switch(c)
{
case 'a': 
printf("0");
break;
case 'b': 
printf("1");
break;
case 'c': 
printf("2");
break;
case 'd': 
printf("3");
break;
case 'e': 
printf("4");
break;
case 'f': 
printf("5");
break;
case 'g': 
printf("6");
break;
case 'h': 
printf("7");
break;
case 'i': 
printf("8");
break;
case 'j': 
printf("9");
break;
default :
printf("%c",t[r]);
break;
}
}