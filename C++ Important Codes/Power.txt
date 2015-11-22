LL power(LL n,LL m)
{
    LL sum=1;
    while(m>0)
    {
        sum*=n;
        m--;
    }
    return sum;
}
