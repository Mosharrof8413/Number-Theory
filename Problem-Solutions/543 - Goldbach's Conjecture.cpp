/*
  Problem Link : https://onlinejudge.org/external/5/543.pdf
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define PB push_back
#define F first
#define S second

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mx=1e7+123;
bool is_prime[mx];
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
  // primes.PB(2);
   for(ll i=3;i<=n;i+=2)
   {
       if(is_prime[i]==0)primes.PB(i);
   }
}
int main()
{
    optimize();
    sieve(mx);
    ll n;
    while(scanf("%lld",&n) && n)
    {
      ll okk=1;
      for(auto u : primes)
      {
         ll d2=n-u;
         if(is_prime[d2]==0)
         {
             cout<<n<<" = "<<u<<" + "<<d2<<endl;
             okk=0;
             break;
         }
       }
       if(okk)
       cout<<"Goldbach's conjecture is wrong."<<endl;
    }

}
//Alhamdulillah...




