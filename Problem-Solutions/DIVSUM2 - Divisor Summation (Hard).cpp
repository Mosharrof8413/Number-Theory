

/*
  Problem Link : https://www.spoj.com/problems/DIVSUM2/
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

const int MX=1e8+123;
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
ll SOD(ll n)
{
    ll ans=1;
    for(auto p : primes)
    {

        if(p*p > n)break;
        if(n%p==0)
        {
            ll curSum=1;
            ll powP=1;
            while(n%p==0)
            {
                powP*=p;
                curSum+=powP;
                n/=p;
            }
            ans*=curSum;
        }
    }
    if(n>1)
    {
        ans*=(n+1);     //5^1  == 5^0 + 5^1
    }
    return ans;
}
/*
// another way to calculate Summation of divisors..
ll SOD(ll n)
{
    ll ans=1;
    for(auto p : primes)
    {

        if(p*p > n)break;
        if(n%p==0)
        {
            ll powP=p;
            while(n%p==0)
            {
                powP*=p;
                n/=p;
            }

            ans*=((powP-1)/(p-1));
        }
    }
    if(n>1)
    {
        ans*=(n+1);     //5^1  == 5^0 + 5^1
    }
    return ans;
}
*/
int main()
{
    optimize();
    ll limt=1e8+123;
    primeGen(limt);
    ll test;
    cin>>test;
    while(test--)
    {
        ll n;
        cin>>n;
        cout<<SOD(n)-n<<endl;
    }
}

//Alhamdulillah...

