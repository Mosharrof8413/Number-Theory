
/*
 Problem Link :  https://www.spoj.com/problems/SINEGGS/
 */

#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

#define endl '\n'
#define PB push_back
#define F first
#define S second


#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

map<ll,ll>is_sqr;
int main()
{
    optimize();
    ll limt=320000;
    for(ll i=1;i<=limt;i++)
    {
        is_sqr[1LL*i*i]=1;
    }
    ll test;
    cin>>test;
    while(test--)
    {
        ll n;
        cin>>n;

        if(is_sqr[n])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

//Alhamdulillah...






