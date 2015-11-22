int mod(char a[], int divider)
{
    int rem,i;
    rem=0;
    for(i=0;a[i];i++)
    {
        rem=rem*10+a[i]-48;
        rem=rem%divider;
    }
    return rem;
}