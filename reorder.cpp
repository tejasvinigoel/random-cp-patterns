//first sort by freq of each index being called->implementation ****
//then arrange elements in same order
#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using vb=vector<bool>;
using vvb=vector<vb>;
using vi=vector<int>;
using vvi=vector<vi>;
using vll=vector<ll>;
using vvll=vector<vll>;
using vc=vector<char>;
using vpll=vector<pair<ll,ll>>;
using vvc=vector<vc>;
using vs=vector<string>;
const ll mod=1e9+7, inf=1e10;
#define pb push_back
#define pm cout<<"-1\n"
#define fo(i, n) for (int i = 0; i < n; i++)
#define fr(i, n) for (int i = n - 1; i >= 0;i--)
void no(){
    cout<<"NO"<<endl;
}
void yes(){
    cout<<"YES"<<endl;
}
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
void solve() {
    ll n,m,qry;
    cin>>n>>qry;
    ll ans=0;
    vll v(n);
    fo(i,n)
        cin>>v[i];
    vvll q(qry,vll(2));
    vll temp(n,0);
    fo(i,qry){
        cin>>q[i][0]>>q[i][1];
        temp[q[i][0]-1]++;
        if(q[i][1]<n)
            temp[q[i][1]]--;
    }
    vll pref(n,0);
    pref[0]=temp[0];
    for(ll i=1;i<n;i++){
        pref[i]=pref[i-1]+temp[i]; //now pref has frequencies of how many times that ind is accessed
    }
    sort(pref.rbegin(),pref.rend());
    sort(v.rbegin(),v.rend());
    fo(i,n){
        ans+=pref[i]*v[i];
    }
    cout<<ans<<endl;
}

int main(){
std::ios_base::sync_with_stdio(false);
std::cin.tie(NULL);
    int t;
    t=1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}