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
	ll minimumCardPickup(vector<ll>& v){
		ll n=v.size(),L=0,res=1000000;
		unordered_map<ll,ll>cnt;
		for(ll i=0; i<n; i++){
			cnt[v[i]]++;
			if(cnt[v[i]]>1){
				while(cnt[v[i]]>1){
					cnt[v[L]]--;
					L++;
				}
				res=min(res,i-(L-1)+1);
			}
		}
		if(res==1000000){res=-1;}
		return res;
	}
};

int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1; cin>>t;
	for(ll T=1; T<=t; T++){
		ll n; cin>>n;
		vector<ll>v(n);
		for(ll i=0; i<n; i++){
			cin>>v[i];
		}
		Solution obj;
		ll ans=obj.minimumCardPickup(v);
		cout<<ans<<"\n";
	}
	return 0;
}



