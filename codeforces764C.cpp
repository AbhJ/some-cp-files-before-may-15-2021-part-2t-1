#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e5+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
ll c[N];
// bool u[N];
// vector<vector<int> > a;
// void bfs(int s) {
//   d[s] = 0;
//   queue<int> q;
//   q.push(s);
//   while (!q.empty()) {
//     int v = q.front();q.pop();
//     for (auto to : a[v]) {
//       if (d[to] == -1) {
//         d[to] = d[v] + 1;
//         q.push(to);
//       }
//     }
//   }
// }
// ll ans;
// ll dp[N],ans;double num;
// double dfs(int u,int v=-1){
//     // ll d=c[u];
//     // ans=max(ans,d);
//     // if(u[x])return;
//     // u[x]=1;
//     // if(st)c[x]=i+1;
//     double t=0;bool c=0;double n=0;
//     for(auto y:a[u]){
//         // int y=b.F;ll C=b.S;
//         if(y==v)continue;
//         t+=dfs(y,u);n++;
//         // ans=max(ans,x+d-C);
//         // if(x%=2)ans++;
//         // t=max(x,t);
//         // d=max(d,win+c[u]-C);
//     }
//     if(n==0)return 1;
//     // num+=a[u].size()-1;
//     // ans+=t+1;
//     return (t/n)+1;
//     //size of subtree =t+1
//     // if(t%2)ans++;
//     // if(t==0)return 1;
//     return t+1;
// }

// ll powM(ll b, int p) {
//   ll r=1;
//   for(; p; b=b*b%M, p/=2)
//     if(p&1)
//       r=r*b%M;
//   return r;
// }
// ll powM(ll a,ll b)
// {
//   ll ans=1;
//   while(b)
//   {
//     if(b&1LL)ans=ans*a%M;
//     a=a*a%M;
//     b>>=1;
//   }
//   return ans;
// }
// ll s,side,x,y;
void solve(){
  int n;cin>>n;
  // a=std::vector<std::vector<int> > (n);
  std::vector<int> l(n-1),r(n-1);
  for (int i = 0; i < n-1; ++i)
  {
    int x,y;cin>>x>>y;
    l[i]=x-1;r[i]=y-1;
  }
  for (int i = 0; i < n; ++i)
  {
    cin>>c[i];
  }
  std::vector<int> v(n);
  int C=0;
  for (int i = 0; i < n-1; ++i)
  {
    if(c[l[i]]!=c[r[i]]){
      C++;v[l[i]]++,v[r[i]]++;
    }
  }
  for (int i = 0; i < n; ++i)
  {
    if(v[i]==C){
      cout<<"YES\n"<<i+1;return;
    }
  }
  cout<<"NO";
}
int main()
{
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      cout<<"\n";
    // }
    return 0;
}