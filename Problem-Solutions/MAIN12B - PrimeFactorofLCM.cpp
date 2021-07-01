/*
 Problem Link : https://www.spoj.com/problems/MAIN12B/
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
vector<ll>prime_Factorization(ll n)
{
    vector<ll>prime_Factors;
    for(auto u : primes)
    {
        if(u*u > n)break;
        if(n%u==0)
        {
            prime_Factors.push_back(u);
            while(n%u==0)
            {
                n/=u;
            }
        }
    }
    if(n>1)prime_Factors.push_back(n);
    return prime_Factors;
}
int main()
{
    optimize();
    ll limt=1e6+123;
    sieve(limt);
    ll test;
    cin>>test;
    for(ll tc=1; tc<=test; tc++)
    {
        ll n;
        cin>>n;
        set<ll>s;
        for(ll i=1; i<=n; i++)
        {
            ll x;
            cin>>x;
            vector<ll>ans=prime_Factorization(x);
            for(auto u  : ans )s.insert(u);
        }
        cout<<"Case #"<<tc<<": "<<s.size()<<endl;
        for(auto u : s)cout<<u<<endl;
    }
}

//Alhamdulillah...





