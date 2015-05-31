#include <cstdio>
#include <cstdlib>
int swap(char a[],int n)
{
    int i,j,t;
    for(i=0,j=n-1;i<n/2;i++,j--)
    {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
}
main()
{
    long a,b,c,d,p,q,r,s;
    int i,t,j;
    char m[10];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%ld.%ld.%ld.%ld",&a,&b,&c,&d);
        scanf("%ld.%ld.%ld.%ld",&p,&q,&r,&s);
        j=0;
        while(a>0)
        {
            m[j]=a%2+48;
            a=a/2;
            j++;
        }
        m[j]='\0';
        swap(m,j);
        a=atol(m);
        j=0;
        while(b>0)
        {
            m[j]=b%2+48;
            b=b/2;
            j++;
        }
        m[j]='\0';
        swap(m,j);
        b=atol(m);
        j=0;
        while(c>0)
        {
            m[j]=c%2+48;
            c=c/2;
            j++;
        }
        m[j]='\0';
        swap(m,j);
        c=atol(m);
        j=0;
        while(d>0)
        {
            m[j]=d%2+48;
            d=d/2;
            j++;
        }
        m[j]='\0';
        swap(m,j);
        d=atol(m);
        printf("Case %d: ",i);
        if(a==p && b==q && c==r && d==s)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
