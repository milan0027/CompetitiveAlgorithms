#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define lld long double
#define fi first
#define se second
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define loop(n) for(int i=0;i<n;i++)
#define rep(i,s,e) for(int i=s;i<e;i++)
#define test int t; cin>>t; while(t--)
#define sortf(a) sort(a.begin(),a.end())
#define sortr(a) sort(a.rbegin(),a.rend())
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ansyes cout<<"YES\n"
#define ansno cout<<"NO\n"
const int mod = 1000000007, dom = 998244353;
const int N = 200001, inf = 2100000000;
const lld eps = 1e-6, pi = 3.1415926535897932;
const long long INF = 4000000000000000000;

int32_t main()    
{

   fastio;
   int isprime[101]={0};
   isprime[1]=1;
   for(int i=2;i*i<=100;i++)
   {
      if(isprime[i]==0)
      {
         for(int j=i*i;j<=100;j+=i)
         {
            isprime[j]=1;
         }
      }
   }
   for(int i=1;i<=100;i++)
   {
      if(isprime[i]==0)
         cout<<i<<" ";
   }
   

}