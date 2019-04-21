int phi(int n)
{
    int res=n;
    int i;
    for(i=2;i*i<=n;i++)
    {
        if(!(n%i))
            res-=res/i;
        while(!(n%i))
            n/=i;
        if(n==1)
            break;
    }
    if(n>1)
        res-=res/n;
    return res;
}
