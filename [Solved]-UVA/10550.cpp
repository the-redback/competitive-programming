#include <cstdio>
#include <cstring>
main()
{
    int a,b,c,d;
    int sum;
    while(scanf("%d %d %d %d",&a,&b,&c,&d)==4)
    {
        if(a==0 && b==0 && c==0 && d==0)
            return 0;
        sum=1080;
        a=a-b;
        if(a<0)
            a+=40;
        b=c-b;
        if(b<0)
            b+=40;
        c=c-d;
        if(c<0)
            c+=40;
        sum+=(a*9)+(b*9)+(c*9);
        printf("%d\n",sum);
    }
    return 0;
}
