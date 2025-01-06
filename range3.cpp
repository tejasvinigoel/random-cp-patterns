//459D.. duplicates--- ai>aj>ak, i<j<k
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

struct SegTree{
    public:
        SegTree(ll sz) : n(sz){
            tree.resize(4*n,0);
        }
        ll query(ll x,ll y){
            return query(x,y,0,n-1,0);
        }
        void update(ll ind,ll val){
            update(ind,val,0,n-1,0);
        }
    private:
        vector<ll>tree;
        ll n;
        //sum of segment
        ll query(ll x,ll y, ll l,ll r, ll i){
            if(r<x||l>y)
                return 0;
            if(l>=x&&r<=y)
                return tree[i];
            ll m=(l+r)>>1;
            return query(x,y,l,m,2*i+1)+query(x,y,m+1,r,2*i+2);
        }
        void update(ll ind,ll val,ll l, ll r, ll i){
            if(l==r){
                tree[i]=val;
                return;
            }
            ll m=(l+r)>>1;
            if(m>=ind)
                update(ind,val,l,m,2*i+1);
            else update(ind,val,m+1,r,2*i+2);
            tree[i]=tree[2*i+1]+tree[2*i+2];
        }
};


void solve() {
    ll n,m;
    cin>>n;
    vll v(n);
    fo(i,n)
        cin>>v[i];
    
    vll f1(n),f2(n);
    map<ll,ll>freq1,freq2;

    for(ll i=0;i<n;i++){
        freq1[v[i]]++;
        f1[i]=freq1[v[i]];
    }

    for(ll i=n-1;i>=0;i--){
        freq2[v[i]]++;
        f2[i]=freq2[v[i]];
    }
    
    vpll arr_and_ind;
    for(ll i=0;i<n;i++)
        arr_and_ind.pb({f1[i],i});
    
    sort(arr_and_ind.begin(),arr_and_ind.end());

    map<pair<ll,ll>,ll> posn;
    for(ll j=0;j<n;j++){
        posn[arr_and_ind[j]]=j;
    }

    SegTree tree(n);
    ll res=0;
    for(int j=0;j<n;j++){
        int f1_ind=posn[{f1[j],j}];
        int f2_ind=upper_bound(arr_and_ind.begin(),arr_and_ind.end(),make_pair(f2[j],LLONG_MAX))
                    -arr_and_ind.begin();
        if(f2_ind<n){
            res+=tree.query(f2_ind,n-1);
            tree.update(f1_ind,1);
        }
    }
    cout<<res<<endl;
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