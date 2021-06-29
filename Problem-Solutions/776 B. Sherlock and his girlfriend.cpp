/*
 Problem Link : https://codeforces.com/contest/776/problem/B
 */

#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

#define endl '\n'
#define PB push_back
#define F first
#define S second

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX=1e5+123;
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
    ll test=1;
    // cin>>test;
    sieve(MX);
    while(test--)
    {
        ll n;
        cin>>n;
        (n==1 || n==2) ? cout<<1<<endl : cout<<2<<endl;
        for(ll i=2; i<=n+1; i++)
        {
            if(is_prime[i])cout<<1<<" ";
            else cout<<2<<" ";
        }
        cout<<endl;
    }

}
//Alhamdulillah...


