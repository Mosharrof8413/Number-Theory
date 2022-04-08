/*
 Problem :

*/

#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

#define endl '\n'
#define PB push_back
#define F first
#define S second

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
ll sum;
ll gcd (ll a,ll b)
{
    if(b==0)return a;

    return gcd(b,b%a);
}

ll bigMod(ll p,ll base,ll mod)
{
    if(p==1) return base%mod;

    if(p%2) return (bigMod(p-1,base,mod)*base)%mod;

    ll x= bigMod(p/2,base,mod);
    x=(x*x)%mod;
    return x;
}

int main()
{
    optimize();

        ll B,P,M;
        cin>>B>>P>>M;
        cout<<bigMod(P,B,M)<<endl;
}

//Alhamdulillah..


/*
input:

5 5 10


Output:

5


*/






