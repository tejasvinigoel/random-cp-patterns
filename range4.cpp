//sereja and queries
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

struct Node{
    int matched, opened, closed;
    Node(){
        matched=0;
        opened=0;
        closed=0;
    }
    Node(char ch){ //leaf
        matched=0;
        opened=0;
        closed=0;
        if(ch=='(')
            opened=1;
        else closed=1;
    }
    Node(const Node &lhs, const Node &rhs){
        int newMatches=min(lhs.opened,rhs.closed);
        //cout<<lhs.opened<<rhs.closed<<newMatches<<endl;
        matched=lhs.matched+rhs.matched+newMatches*2;
        closed=lhs.closed+rhs.closed-newMatches;
        opened=lhs.opened+rhs.opened-newMatches;
    }
};

class SegmentTree{
    int n;
    vector<Node>seg;

    void build(int p,int l,int r,const string &a){
        if(l==r){
            seg[p]=Node(a[l]);
            return;
        }
        int mid=(l+r)>>1;
        build(2*p,l,mid,a);
        build(2*p+1,mid+1,r,a);
        seg[p]=Node(seg[2*p],seg[2*p+1]);
    }

    Node get(int p,int ql, int qr, int l,int r){
        if(l>=ql&&r<=qr)
            return seg[p];
        if(l>qr||r<ql)
            return Node();
        int mid=(l+r)>>1;
        return Node(get(2*p,ql,qr,l,mid),get(2*p+1,ql,qr,mid+1,r));
    }

public:
    SegmentTree(const string &a){
        this->n=a.size();
        seg.resize(4*n);
        build(1,0,n-1,a);
    }
    SegmentTree(int n){
        this->n=n;
        seg.resize(4*n);
    }
    Node get(int l,int r){
        return get(1,l,r,0,n-1);
    }

};


void solve() {
    ll n,m;
    string s;
    int q;
    cin>>s>>q;
    SegmentTree segtree(s);
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        Node st=segtree.get(l,r);
        cout<<st.matched<<endl;
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