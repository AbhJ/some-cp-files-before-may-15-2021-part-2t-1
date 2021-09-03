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
// #include <bits/stdc++.h>
#define double long double
#define int long long int
#define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb emplace_back
#define koto_memory(a) cout<<(sizeof(a)/1048576.0)<<" MB";
#define res(v) sort(all(v)),v.erase(unique(all(v)), v.end());
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
#define deb(x) cout<<"\n["<<#x<<" = "<<x<<"]\n";
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
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,child[N][26],is_end[N*26],nxt=1,ans;string s[N];vvi a;
void solve(){
  cin>>n;a.resize(n+1);
  rep(i,1,n){
    cin>>s[i];
    reverse(s[i].begin(),s[i].end());
    int node=0;
    for(int j=0;j<s[i].length();j++){
      a[i].push_back(node);
      if(child[node][s[i][j]-'a']==0)
        child[node][s[i][j]-'a']=nxt++;
      node=child[node][s[i][j]-'a'];
    }
    is_end[node]=1;
  }
  rep(i,1,n){
    set<int>prefix;
    //s[i].length()-1 elements must match in original string
    for(int j=s[i].length()-1;j>-1;j--){
      prefix.insert(s[i][j]);
      int node=a[i][j];
      for(auto tmp:prefix)
        if(is_end[child[node][tmp-'a']]==1)
          ans++;
    }
  }
  cout<<ans-n;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}