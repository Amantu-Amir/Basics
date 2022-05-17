#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define Mid(b,e) b+(e-b)/2
#define inf 1e18
double PI=2*acos(0.0);

//---------------------------------------------------------------------------//
//Timus: 314795JS
//knight moves
// ll X[8] = {2, 1, -1, -2, -2, -1, 1, 2};
// ll Y[8] = {1, 2, 2, 1, -1, -2, -2, -1};
// ll dx[]={1,-1,0,0};
// ll dy[]={0,0,1,-1};
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
//------------------------------------------------------------------------------//


const ll p=29;
const ll N=2e6+50;
const ll mod=1e9+7;

class Solution{
public:
	ll lengthOfLongestSubstring(string s){
		ll n=s.size(),L=0,res=0;
		unordered_map<char,ll>cnt;
		for(ll i=0; i<n; i++){
			cnt[s[i]]++;
			if(cnt[s[i]]>1){
				while(cnt[s[i]]>1){
					cnt[s[L]]--;
					L++;
				}
			}
			res=max(res,i-L+1);
		}
		return res;
	}
};

int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		string str;
		//cin>>str;
		Solution obj;
		ll ans=obj.lengthOfLongestSubstring("");
		cout<<ans<<"\n";
	}
	return 0;
}



