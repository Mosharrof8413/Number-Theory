/*
 Problem Link : https://onlinejudge.org/external/114/11466.pdf
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

    sieve(MX);
    ll n;
    while(cin>>n && n)
    {
        vector<ll>ans=prime_Factorization(abs(n));
        if(ans.size()<=1)cout<<-1<<endl;
        else
        {
            ll okk=ans[ans.size()-1];
            cout<<okk<<endl;
        }
    }

}
//Alhamdulillah...



