//replace 31 with 53 if u consider a-zA-Z
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
using vvc=vector<vc>;
using vs=vector<string>;
using pll=pair<ll,ll>;
const ll mod=1e9+7, inf=1e10, N=2e5+5;
#define pb push_back
#define fo(i, n) for (long long i = 0; i < n; i++)
#define fr(i, n) for (ll i = n - 1; i >= 0;i--)
#define cin(a,n)   vll a(n); fo(i,n) {cin>>a[i];}
#define prv(a) for(auto i:a) cout<<i<<" ";
#define f first
#define s second
void no(){
    cout<<"NO"<<endl;
}
void yes(){
    cout<<"YES"<<endl;
}
vll dp,pw;
void preprocess(string s){
    ll n=s.size();
    dp.resize(n);
    pw.resize(n);

    ll p=31; //53 for a-zA-Z
    ll pow=p;

    dp[0]=s[0]-'a'+1;
    pw[0]=1; //multiply smaller by this to compare 2 strings ... p^0=1.. p^i

    for(int i=1;i<n;i++){
        dp[i]=(dp[i-1]+(s[i]-'a'+1)*pow)%mod;
        pw[i]=pow;
        pow=(pow*p)%mod;
    }
}

ll hashQuery(int l,int r){
    ll ans=dp[r];
    if(l>0)
        ans=(dp[r]-dp[l-1]+mod)%mod;
    return ans;
}
void solve(){
    string s;
    cin>>s;
    preprocess(s);
    ll ans=0;
    int n=s.size();
    for(int i=0;i<n-1;i++){
        ll pref=dp[i];
        ll suff=hashQuery(n-i-1,n-1);
        if((pref*pw[n-1-i])%mod==suff){
            for(int j=1,k=i+1;k<n-1;k++,j++){
                ll mid=hashQuery(j,k);
                if((pref*pw[j])%mod==mid){
                    ans=i+1; break;
                }
            }
        }
    }
    //cout<<ans<<endl;
    if(ans==0)
        cout<<"Just a legend"<<endl;
    else
        cout<<s.substr(0,ans)<<endl;
}
int main(){
std::ios_base::sync_with_stdio(false);
std::cin.tie(NULL);
std::cout.tie(NULL);
    int t;
    t=1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}