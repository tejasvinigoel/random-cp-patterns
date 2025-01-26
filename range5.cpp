//ant colony.. no of eles in (l,r) st ai=gcd(eles betw l,r)
//Q'(l,r,key)....no of eles in (l,r)=key
//mp<int,vi>... mp[x]=vector of indices where x occurs in array
//Q'(l,r,key)=mp[key].upperbound(r)-mp[key].lowerbound(l)
//gcd ants are freed.. rest are eaten so r-l+1-ans is printed
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
#define fo(i, n) for (ll i = 0; i < n; i++)

ll n;
vll tree; //tree[index]=gcd of elements in range [l,r]
vll v;

void build(ll index,ll l,ll r){
    if(l==r){
        tree[index]=v[l];
        return;
    }
    ll mid=(l+r)>>1;
    build(2*index,l,mid);
    build(2*index+1,mid+1,r);
    tree[index]=__gcd(tree[2*index],tree[2*index+1]);
}
ll query(ll index, ll l, ll r,ll ql, ll qr){
    if(l>=ql&&r<=qr)
        return tree[index];
    if(l>qr||r<ql)
        return 0;
    ll mid=(l+r)>>1;
    return __gcd(query(2*index,l,mid,ql,qr),query(2*index+1,mid+1,r,ql,qr));
}
void solve() {
    cin>>n;
    v.clear();
    v.resize(n);
    tree.clear();
    tree.resize(4*n);
    map<ll,vll>mp;
    fo(i,n){
        cin>>v[i];
        mp[v[i]].pb(i);
    }
    build(1,0,n-1);
    ll q;
    cin>>q;
    while(q--){
        ll l,r;
        cin>>l>>r;
        l--;r--;
        ll ans=0;
        ll rangegcd=query(1,0,n-1,l,r);

        if(!mp[rangegcd].empty()){
            auto &vec=mp[rangegcd];
            ans=upper_bound(vec.begin(),vec.end(),r)-lower_bound(vec.begin(),vec.end(),l);
        }
        cout<<r-l+1-ans<<endl;

    }

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