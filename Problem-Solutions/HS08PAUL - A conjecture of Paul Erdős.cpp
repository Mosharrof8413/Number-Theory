/*
 Problem Link : https://www.spoj.com/problems/HS08PAUL/
 */

#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

#define endl '\n'
#define PB push_back
#define F first
#define S second

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX=1e7+123;
ll ans[MX];
bitset<MX>is_prime;
vector<ll>primes;
void sieve(ll n)
{
    ll sq=sqrt(n);
    for(ll i=3; i<=n; i+=2)is_prime[i]=1;
    for(ll i=3; i<=sq; i+=2)
    {
        if(is_prime[i]==1)
        {
            for(ll j=i*i; j<=n; j+=(i+i))
                is_prime[j]=0;
        }
    }
    primes.PB(2);
    is_prime[2]=1;
    for(ll i=3; i<=n; i+=2)
    {
        if(is_prime[i]==1)primes.PB(i);
    }
}
int main()
{
    optimize();

    sieve(MX);
    for(ll x=1;x<3200;x++)
    {
        for(ll y=1;y<60;y++)
        {
            ll check=(x*x)+(y*y*y*y);
            if(check>MX)continue;
            if(is_prime[check])ans[check]=1;
        }
    }
    for(ll i=1;i<MX;i++)
    {
        ans[i]+=ans[i-1];
    }
    ll test;
    cin>>test;

    while(test--)
    {
        ll n;
        cin>>n;
        cout<<ans[n]<<endl;
    }

}
//Alhamdulillah...



