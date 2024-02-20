#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
#define sz(x) (int)((x).size())
#define all(x) x.begin(),x.end()
#define ll long long
using namespace std;
const int INF=1e9+10;
void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if (k==1){
        cout<<s<<'\n';
        return;
    }
    string re;
    vector<int> vis(n);
    vector<int> tmp;
    for (int j=k;j>1;--j){
        for (int i=0;i<n;++i){
            if (vis[i]) continue;
            while (sz(tmp)&&s[tmp.back()]>s[i]) {
                vis[tmp.back()]=0;
                tmp.pop_back();
            }
            tmp.push_back(i);
            vis[i]=1;
        }
        if (sz(tmp)==n) break;
    }
    int x=-1,y=-1;
    for (int i=0;i<n;++i){
        if (!vis[i]){
            if (x!=-1&&y==-1&&s[x]!=s[i]) y=i;
            if (x==-1) x=i;
        }
    }
    if (x!=-1){
        while (sz(tmp)) {
            if (s[tmp.back()]>s[x]||s[tmp.back()]==s[x]&&y!=-1&&s[y]<s[x]){
                vis[tmp.back()]=0;
                tmp.pop_back();
            }
            else break;
        }
    }

    for (int &i:tmp)  re.push_back(s[i]);
    
    for (int i=0;i<n;++i) if (!vis[i]) re.push_back(s[i]);
    cout<<re<<'\n';

}
int main(){
    fastio;
    int t;cin>>t;
    while (t--) solve();
}