/*
  Problem Link : https://www.spoj.com/problems/TDPRIMES/
*/
#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

#define endl '\n'
#define PB push_back
#define F first
#define S second

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mx=1e8;                          // counting prime function ....lower_bound(N/ln(N) )<= PI(N)<= upper_bound (1.25506*N/ ln(N))
bool is_prime[mx];                          // upper_bound is important ...
vector<ll>primes;
void sieve(ll n)
{
   is_prime[1]=1;
   ll sq=sqrt(n);
   for(ll i=3;i<=sq;i+=2)
   {
       if(is_prime[i]==0)
        {
       for(ll j=i*i;j<=n;j+=(i+i))
           is_prime[j]=1;
        }
   }
   primes.PB(2);
   for(ll i=3;i<=n;i+=2)
   {
       if(is_prime[i]==0)primes.PB(i);
   }
}
int main()
{
    optimize();
    sieve(mx);
    ll test=1;
    //cin>>test;
    while(test--)
    {
      for(ll i=0;i<=primes.size();i++)
      {
          if((i+1)%100==1)cout<<primes[i]<<endl;
      }
    }

}
//Alhamdulillah...



