/*
 Problem Link : https://lightoj.com/problem/false-ordering
 */

#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;

#define endl '\n'
#define PB push_back
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))

ll gcd ( ll a, ll b )
{
    return __gcd ( a, b );
}
ll lcm ( ll a, ll b )
{
    return a * ( b / gcd ( a, b ) );
}


#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

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

vector<ll>list_of_power[1123];
ll NOD[1123];
int main()
{
    ll lim=1000;
    sieve(lim);

    for(auto p : primes)
    {
        for(ll i=p; i<=lim; i+=p)
        {
            ll cnt=1,temp=i;
            while(temp%p==0)
            {
                cnt++;
                temp/=p;
            }
            list_of_power[i].push_back(cnt);
        }
    }
    vector<pair<ll,ll> >v;
    for(ll i=1; i<=lim; i++)
    {
        NOD[i]=1;
        for(auto u : list_of_power[i])
            NOD[i]*=u;
    }

    for(ll i=1;i<=lim;i++)
    {
        v.push_back({NOD[i],-i});
    }
    sort(v.begin(),v.end());

    ll test;
    cin>>test;
    for(ll tc=1; tc<=test; tc++)
    {
        ll n;
        cin>>n;
        cout<<"Case "<<tc<<": ";
        cout<<v[n-1].second*-1<<endl;
    }
}

//Another solution using harmonic series or modified sieve...
/*
ll divisors[MX];
int main()
{
    ll lim=1000;
    sieve(lim);
    for(ll i=1; i<=lim; i++)
    {
        for(ll j=i; j<=lim; j+=i)divisors[j]++;
    }
    vector<pair<ll,ll> >v;
    for(ll i=1; i<=lim; i++)
    {
        v.push_back({divisors[i],-i});
    }
    sort(v.begin(),v.end());

    ll test;
    cin>>test;
    for(ll tc=1; tc<=test; tc++)
    {
        ll n;
        cin>>n;
        cout<<"Case "<<tc<<": ";
        cout<<v[n-1].second*-1<<endl;
    }
}
*/


//Alhamdulillah...

