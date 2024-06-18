#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n == 1)
    {
        cout<<n;
        return 0;
    }
    else if(n==2 or n==3)
    {
        cout<<"NO SOLUTION";
        return 0;
    }
    
    for(int i = 2; i <=n; i+=2)
    {
        cout<<i<<" ";
    }
    for(int j = 1; j<=n;j+=2)
    {
        cout<<j<<" ";
    }
   
}