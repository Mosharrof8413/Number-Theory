/*
 Problem Link : https://codeforces.com/contest/230/problem/B
 */

#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

#define endl '\n'
#define PB push_back
#define F first
#define S second


ll gcd ( ll a, ll b )
{
    return __gcd ( a, b );
}
ll lcm ( ll a, ll b )
{
    return a * ( b / gcd ( a, b ) );
}

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX=1e6+123;
bitset<MX>is_prime;
vector<ll>primes;

void primeGen(ll n)
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
    ll limt=1e6+123;
     primeGen(limt);
    map<ll,ll>mp;
    for(auto u : primes)
    {

        if(u*u>1000000000123)
            break;

        mp[u*u]=1;
    }
    ll test;
    cin>>test;
    for(ll i=0;i<test;i++)
    {
        ll n;
        cin>>n;
        (mp[n]==1) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }
}
/*
Alhamdulillah..
*/
