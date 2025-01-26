//copying data
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
const ll N=1e6,nll=-346247534;
ll n,m;
ll a[N],b[N],xx[N],yy[N],kk[N],val[4*N];

void set_val(ll x,ll xl, ll xr, ll ql, ll qr, ll v){
    if(qr<=xl||ql>=xr)
        return;
    if(ql<=xl&&xr<=qr){
        val[x]=v;
        return;
    }
    ll xm=(xl+xr)>>1;
    if(val[x]!=nll){
        val[2*x+1]=val[x];
        val[2*x+2]=val[x];
        val[x]=nll;
    }
    set_val(2*x+1,xl,xm,ql,qr,v);
    set_val(2*x+2,xm,xr,ql,qr,v);
}
ll get_val(ll x,ll xl,ll xr, ll q){
    if(q<xl||q>=xr)
        return 0;
    if(xr==xl+1)
        return val[x];
    ll xm=(xl+xr)>>1;
    if(val[x]!=nll){
        val[2*x+1]=val[x];
        val[2*x+2]=val[x];
        val[x]=nll;
    }
    return get_val(2*x+1,xl,xm,q)+get_val(2*x+2,xm,xr,q);
}
void solve() {
    cin>>n>>m;
    fo(i,n)
        cin>>a[i];
    fo(i,n)
        cin>>b[i];
    
    fill(val,val+4*N,nll); //new stl
    set_val(0,0,n,0,n,-1);
    fo(i,m){
        ll qt;
        cin>>qt;
        if(qt==1){
            cin>>xx[i]>>yy[i]>>kk[i];
            xx[i]--, yy[i]--;
            set_val(0,0,n,yy[i],yy[i]+kk[i],i);
        }
        else{
            ll pos;
            cin>>pos;
            pos--;
            ll up=get_val(0,0,n,pos);
            if(up==-1)
                cout<<b[pos]<<endl;
            else cout<<a[xx[up]+(pos-yy[up])]<<endl;
        }
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