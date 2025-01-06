//356A
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
    ll n,m;
    cin>>n>>m;
    vi ans(n+1,0);
    set<int>alive;
    for(int i=1;i<=n+1;i++)
        alive.insert(i);
    while(m--){
        int l,r,w;
        cin>>l>>r>>w;
        auto it=alive.lower_bound(l);
        while(*it<=r&&it!=alive.end()){
            if(*it!=w){
                ans[*it]=w;
                auto kill=it;
                it++;
                alive.erase(kill);
            }
            else it++;
        }
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
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