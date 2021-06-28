
//Checking a given number prime or not using sieve algorithm...
#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

#define endl '\n'
#define PB push_back
#define F first
#define S second

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mx=1e6+123;
bool is_prime[mx];
vector<ll>primes;
void sieve()
{
   is_prime[1]=1;

   for(ll i=4;i<=mx;i+=2)is_prime[i]=1;
   ll sq=sqrt(mx);
   for(ll i=3;i<=sq;i+=2)
   {
       if(is_prime[i]==0)
        {
       for(ll j=i*i;j<=mx;j+=(i+i))
           is_prime[j]=1;
        }
   }
   primes.PB(2);
   for(ll i=3;i<=mx;i+=2)
   {
       if(is_prime[i]==0)primes.PB(i);
   }
}
int main()
{
    optimize();
    ll test=1;
    //cin>>test;
    sieve();
    while(test--)
    {
      ll n;
      cin>>n;
      if(is_prime[n]==0)cout<<n<<" is a prime number"<<endl;
       else cout<<n<<" is not a prime number"<<endl;
    }

}
//Alhamdulillah...


