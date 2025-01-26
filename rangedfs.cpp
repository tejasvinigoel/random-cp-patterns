//1336A.. code-a-tic explanation bestt
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
vll cnt;
vvll adj;
vll vis;
ll dfs(ll x,ll level){
    vis[x]=1;
    ll kids=0;
    for(auto nbr:adj[x]){
        if(!vis[nbr]){
            kids+=dfs(nbr,level+1);
        } //if I make x an industrial spot,
        //every kid of x will have to be subtracted by 1
        //directly subtract no of kids.. sum total is same
    }
    cnt[x]=level-kids;
    return kids+1;
    //cnt[x] is considering x to be an industrial spot but we r returning it as tho x is tourist
}
void solve() {
    ll n,m,k;
    cin>>n>>k;
    adj.resize(n+1);
    vis.resize(n+1,0);
    cnt.resize(n+1,0);

    fo(i,n-1){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1,0);
    // fo(i,n+1)
    //     cout<<cnt[i]<<" ";
    cnt[0]=-1e9;
    sort(cnt.rbegin(),cnt.rend());
    ll ans=0;
    fo(i,k)
        ans+=cnt[i];
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