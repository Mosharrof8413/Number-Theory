//Divisors printing with O(nlnn)
//using harmonic series...
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

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
const ll mx=1e5+123;
vector<ll>divisors[mx];

// Divisors 1 to N...
//using Harmonic series ..its work in O(nln(n)) which is less than O(nlogn)
 void check(ll n)
{
    for(ll i=1;i<=n;i++)
    {
        for(ll j=i;j<=n;j+=i)
            divisors[j].push_back(i);
    }
}
int main()
{
    optimize();
    ll test=1;
    //cin>>test;
    for(ll tc=1;tc<=test;tc++)
    {
       ll n;
       cin>>n;
       check(n);
       for(ll i=1;i<=n;i++)
       {
           cout<<"Divisors of "<<i<<" is : ";
           for(auto u : divisors[i])
           cout<<u<<" ";
           cout<<endl;
       }

    }

}
//Alhamdulillah...



