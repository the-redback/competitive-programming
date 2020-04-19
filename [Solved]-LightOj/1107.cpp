#include <iostream>
using namespace std;

main()
{
    int t,m,i,j,it,x1,y1,x2,y2;
    int a,b;
    cin>>t;
    for(it=1;it<=t;it++)
    {
        cin>>x1>>y1>>x2>>y2;
        cin>>m;
        cout<<"Case "<<it<<":\n";
        for(i=0;i<m;i++)
        {
            cin>>a>>b;
            if(a>x1 && a<x2 && b>y1 && b<y2)
            {
                cout<<"Yes\n";
            }
            else
            {
                cout<<"No\n";
            }
        }
    }
    return 0;
}
