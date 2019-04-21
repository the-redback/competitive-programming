#include<cstdio>
using namespace std;
long b[1000001],c[1000001];
int main()
{
	long i,j,m,mx,t;
	b[1]=1;
	mx=0;
	c[1]=1;
	for(i=2;i<1000001;i++)
	{
		for(j=i;j<1000001;j+=i)
			b[j]++;
		if(b[i]>=mx)
		{
			mx=b[i];
			m=i;
		}
		c[i]=m;
	}
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&m);
		printf("%ld\n",c[m]);
	}
	return 0;
}