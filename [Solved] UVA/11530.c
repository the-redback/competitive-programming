#include <stdio.h>
#include <string.h>

int main()
{
    int j,count,n,i,l;
    char a[100];

    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
      {

        gets(a);

        l=strlen(a);
        count=0;
        for(j=0;j<l;j++)
        {
            if (a[j]== 'a'||a[j]=='d'||a[j]=='g'||a[j]=='j'||a[j]=='m'||a[j]=='p'||a[j]=='t'||a[j]=='w'||a[j]==' ')
            {
                count++;
            }
            else if(a[j]== 'b'||a[j]=='e'||a[j]=='h'||a[j]=='k'||a[j]=='n'||a[j]=='q'||a[j]=='u'||a[j]=='x')
            {
                count=count+2;
            }
            else if(a[j]== 'c'||a[j]=='f'||a[j]=='i'||a[j]=='l'||a[j]=='o'||a[j]=='r'||a[j]=='v'||a[j]=='y')
            {
                count=count+3;
            }
            else if(a[j]== 's'||a[j]=='z')
            {
                count=count+4;
            }
        }
        printf("Case #%d: %d\n",i+1,count);
        }

    return 0;
}
