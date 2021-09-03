//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 04 in 03 : 59 : 14
//title - J_Spelling_Check.cpp
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
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
string s, t;int n, P[N], S[N], pre, suf;
void solve(){
	cin >> s >> t;n = s.length();vi v;
	rep(i, 1, n - 1){
		if(s[i - 1] == t[i - 1])pre++;
		else break;
	}
	rep(i, 0, n - 2){
		if(*(s.rbegin() + i) == *(t.rbegin() + i))suf++;
		else break;
	}
	if(pre + suf > n - 2){
		{
			per(i, min(pre, n - 1), max(n - 1 - suf, 0LL))
				v.pb(i);
		}
		cout << v.size() << "\n";
		reverse(all(v));
		for(auto &i: v)cout << i + 1 << " ";
	}
	else cout << 0;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/* xx++;cout<<"Case "<<xx<<": " */;solve();cout<<endl;}
  return 0;
}