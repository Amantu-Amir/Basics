#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
//typedef tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>pbds;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>pbds; 
//typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>pbds; 

//------------------------------------------------------------------------------//


const ll p=29;
const ll N=2e6+50;
const ll mod=1e9+7;

class Solution {
public:
    string minWindow(string s, string t) {
    	if(s.size()<t.size()){return "";}
        int tlen=t.size();
        vector<int>cnt(55,0);
        for(int i=0; i<tlen; i++){
        	int id=t[i]-'a'+26;
        	if(t[i]>='A' and t[i]<='Z'){
        		id=t[i]-'A';
        	}
        	cnt[id]++;
        }
        int slen=s.size(),ok=0;
        int L=0,R=slen,a=0,b;
        vector<int>currCnt(55);
        while(L<=R){
        	int mid=L+(R-L)/2,flag=0,LL=0;
        	for(int i=0; i<=52; i++){
        		currCnt[i]=0;
        	}
        	for(int i=0; i<slen; i++){
        		int id=s[i]-'a'+26;
        		if(s[i]>='A' and s[i]<='Z'){
        			id=s[i]-'A';
        		}
        		currCnt[id]++;
        		if(i>=mid){
        			int id=s[LL]-'a'+26;
	        		if(s[LL]>='A' and s[LL]<='Z'){
	        			id=s[LL]-'A';
	        		}
	        		currCnt[id]--;
	        		LL++;
        		}
        		int ck=1;
        		for(int j=0; j<=52; j++){
        			if(currCnt[j]<cnt[j]){
        				ck=0; break;
        			}
        		}
        		if(ck==1){
        			a=LL,b=i;
        			flag=1; break;
        		}
        	}
        	if(flag==1){
        		ok=1;
        		R=mid-1;
        	}
        	else{
        		L=mid+1;
        	}
        }
        if(ok==0){return "";}
        t="";
        for(int i=a; i<=b; i++){
        	t+=s[i];
        }
        return t;
    }
};

int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		string s,t;
		cin>>s>>t;
		Solution obj;
		cout<<obj.minWindow(s,t)<<"\n";
	}
	return 0;
}



