#include <bits/stdc++.h>
using namespace std;

/**for ordered set */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
/**for ordered set */
// oset<datatype>st;
//less<T> so in ascending order... greater<T> would change to descending
//less_equal<T> for non-unique values (orderedmultiset)
//less<T>->unique values only
// *st.find_by_order(0) is like st[0].. 1st element
//st.insert(val)
//st.order_of_key(val)  gives no of eles less than val
//*st.lower_bound(val) first ele >=val
//*st.upper_bound(val) first ele>val
//st.erase(val)

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
const ll mod=1e9+7, inf=1e10;
#define pb push_back
#define fo(i, n) for (long long i = 0; i < n; i++)
#define fr(i, n) for (ll i = n - 1; i >= 0;i--)
#define cin(a,n)   vll a(n); fo(i,n) {cin>>a[i];}
#define prv(a) for(auto i:a) cout<<i<<" ";
void no(){
    cout<<"NO"<<endl;
}
void yes(){
    cout<<"YES"<<endl;
}
//find pairs of intervals inside intervals
void solve(){
    ll n;
    cin>>n;
    vvll v(n,vll(2));
    fo(i,n)
        cin>>v[i][0]>>v[i][1];
    
    sort(v.begin(),v.end());
    oset<ll>st;
    fo(i,n)
        st.insert(v[i][1]);
    ll ans=0;
    fo(i,n){
        ans+=st.order_of_key(v[i][1]);
        st.erase(v[i][1]);
    }
    cout<<ans<<endl;
}
int main(){
std::ios_base::sync_with_stdio(false);
std::cin.tie(NULL);
    int t;
    t=1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}