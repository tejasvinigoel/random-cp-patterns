//no duplicates--- ai>aj>ak, i<j<k
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
    vpll ele_and_ind;
    fo(i,n){
        cin>>v[i];
        ele_and_ind.pb({v[i],i});
    }
    sort(ele_and_ind.begin(),ele_and_ind.end());
    map<ll,ll>posn;
    fo(i,n)
        posn[ele_and_ind[i].first]=i;

    SegTree tree(n);
    ll res=0;

    for(ll i=0;i<n;i++){
        //so far weve only marked left elements (as of initial array posn) =1
        ll pos=posn[v[i]];
        //pos means pos elements to left are smaller than v[i]
        ll smaller_on_left=tree.query(0,pos-1);
        ll greater_on_left=i-smaller_on_left;
        ll smaller_on_right=pos-smaller_on_left;
        ll greater_on_right=(n-1-pos)-greater_on_left;

        res+=greater_on_left*smaller_on_right;
        tree.update(pos,1);
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