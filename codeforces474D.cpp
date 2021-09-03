//Coded by Abhijay Mitra
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <numeric>
#include <vector>
#include <iterator> 
#include <map>
#include <set>
#include <climits>
#include <queue>
#include <cmath>
#include <stack>
#include <cctype>
#include <bitset>
#include <bits/stdc++.h>
#define double long double
#define int long long int
#define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb emplace_back
#define koto_memory(a) cout<<(sizeof(a)/1048576.0)<<" MB";
#define res(v) sort(all(v)),v.erase(unique(all(v)), v.end());
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec "<<endl;
#define deb(x) cout<<endl<<"["<<#x<<" = "<<x<<"]"<<endl;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x)     x.begin(), x.end()
using namespace std;
const int N=2e5+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,k;
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
int mul(int a,int b){
  return ((a)*(b))%M;
}
int add(int a,int b){
  a+=b;
  if(a>=M)a-=M;
  return a;
}
ll sub(ll a,ll b){
  return ((a%M)-(b%M)+M)%M;
}
int f[N],b[N];
void calc_fact(){
  f[0]=b[0]=1;
  rep(i,1,N-1){
    f[i]=mul(f[i-1],i);
    b[i]=powM(f[i],M-2);
  }
}
int C(int n,int r){
  assert(n<N);assert(r<N);
  if(r>n)return 0;
  return (f[n]*mul(b[r],b[n-r])%M)%M;
}
int ans[N],sp[N][26],A,B;
int get_sum(int &L,int &R){
  int sum=0;
  per(j,25,0)if((1<<j)<=R-L+1)sum=add(sum,sp[L][j]),L+=(1LL<<j);
  return sum;
}
void solver(){
  ans[0]=1;
  rep(i,1,N-1){
    ans[i]=sp[i-1][0]=add(ans[i-1],(i-k>=0?ans[i-k]:0LL));
  }
  rep(j,1,25)
    rep(i,0,N-1-(1<<j)){
      sp[i][j]=add(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
    }
}
void solve(){
  cin>>A>>B;
  cout<<get_sum(--A,--B);
}
int32_t main()
{
  ibs;cti;
  // solve();return 0;
  int xx=0;
  int t;cin>>t>>k;solver();while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}