#include <stdio.h>
#include <string.h>

int mod(char a[], int n)
{
    int b,i;
    b=0;
    for(i=0;a[i];i++)
    {
        b=b*10+a[i]-48;
        b=b%n;
    }
    return b;
}

main()
{
    int i=0,j,k;
    char a[10000];
    while(gets(a))
    {
        j=0;
        k=0;
        if(i!=0)
        {
            printf("\n");
        }
        if(mod(a,4)==0 && mod(a,100)!=0)
        {
            printf("This is leap year.\n");
            j=1;
            k=2;
        }
        else if(mod(a,400)==0)
        {
            printf("This is leap year.\n");
            j=1;
            k=2;
        }
        if(mod(a,15)==0)
        {
            printf("This is huluculu festival year.\n");
            j=1;
        }
        if(mod(a,55)==0 && k==2)
        {
            printf("This is bulukulu festival year.\n");
            j=1;
        }
        if(j==0)
        {
            printf("This is an ordinary year.\n");
        }
        i++;
    }
    return 0;
}
