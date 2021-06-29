//primes number generation 1 to N using bitset ...
#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

#define endl '\n'
#define PB push_back
#define F first
#define S second

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mx=1e7+123;
bitset<mx>is_prime;
vector<ll>primes;
void sieve(ll n)
{
    is_prime[1]=is_prime[0]=0;
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
    for(ll i=3; i<=n; i+=2)
    {
        if(is_prime[i]==1)primes.PB(i);
    }
}
int main()
{
    optimize();
    ll test=1;
   // cin>>test;
    while(test--)
    {
        ll n;
        cin>>n;
        sieve(n);
        for(auto u : primes)cout<<u<<" ";
    }

}
//Alhamdulillah...

