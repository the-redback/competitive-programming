#include <stdio.h>
#include <string.h>

main()
{
    char a[101],n,i,j,m,l,p,temp;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        {
            break;
        }
        getchar();
        gets(a);
        l=strlen(a);
        m=l/n;

        for(i=0;i<n;i++)
        {
            for(j=i*m,p=(i+1)*m-1;j<=((i+1)*m-1)-m/2;j++,p--)
            {
                temp=a[j];
                a[j]=a[p];
                a[p]=temp;
            }
        }
        printf("%s\n",a);
    }
    return 0;

}
