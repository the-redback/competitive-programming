#include <stdio.h>
#include <string.h>

main()
{
    char a[500];
    int l,i,j,k;
    gets(a);
    l=strlen(a);
    for(i=0;i<l;i++)
    {
        if(a[i]==' ')
        printf(" ");

        else if(a[i]=='e' || a[i]=='E')
        printf("q");

        else if(a[i]=='d' || a[i]=='D')
        printf("a");

        else if(a[i]=='c' || a[i]=='C')
        printf("z");

        else if(a[i]=='r' || a[i]=='R')
        printf("w");

        else if(a[i]=='f' || a[i]=='F')
        printf("s");

        else if(a[i]=='v' || a[i]=='V')
        printf("x");

        else if(a[i]=='t' || a[i]=='T')
        printf("e");

        else if(a[i]=='g' || a[i]=='G')
        printf("d");

        else if(a[i]=='b' || a[i]=='B')
        printf("c");

        else if(a[i]=='y' || a[i]=='Y')
        printf("r");

        else if(a[i]=='h' || a[i]=='H')
        printf("f");

        else if(a[i]=='n' || a[i]=='N')
        printf("v");

        else if(a[i]=='u' || a[i]=='U')
        printf("t");

        else if(a[i]=='j' || a[i]=='J')
        printf("g");

        else if(a[i]=='m' || a[i]=='M')
        printf("b");

        else if(a[i]=='i' || a[i]=='I')
        printf("y");

        else if(a[i]=='k' || a[i]=='K')
        printf("h");

        else if(a[i]==',')
        printf("n");

        else if(a[i]=='o' || a[i]=='O')
        printf("u");

        else if(a[i]=='l' || a[i]=='L')
        printf("j");

        else if(a[i]=='.')
        printf("m");

        else if(a[i]=='p' || a[i]=='P')
        printf("i");

        else if(a[i]==';')
        printf("k");

        else if(a[i]=='/')
        printf(",");

        else if(a[i]=='[')
        printf("o");

        else if(a[i]=='\'')
        printf("l");

        else if(a[i]==']')
        printf("p");

        else if(a[i]=='q'|| a[i]=='Q')
        printf("[");

        else if(a[i]=='w'|| a[i]=='W')
        printf("]");

        else if(a[i]=='a'|| a[i]=='A')
        printf(";");

        else if(a[i]=='s'|| a[i]=='S')
        printf("'");

        else if(a[i]=='z'|| a[i]=='Z')
        printf(".");

        else if(a[i]=='x'|| a[i]=='X')
        printf("/");

        else if(a[i]=='1')
        printf("\\");

        else if(a[i]=='`')
        printf("=");

        else if(a[i]=='2')
        printf("`");

        else if(a[i]=='3')
        printf("1");

        else if(a[i]=='4')
        printf("2");

        else if(a[i]=='5')
        printf("3");

        else if(a[i]=='6')
        printf("4");

        else if(a[i]=='7')
        printf("5");

        else if(a[i]=='8')
        printf("6");

        else if(a[i]=='9')
        printf("7");

        else if(a[i]=='0')
        printf("8");

        else if(a[i]=='-')
        printf("9");

        else if(a[i]=='=')
        printf("0");

        else if(a[i]=='\\')
        printf("-");

    }
    printf("\n");
}
