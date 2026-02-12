#include<bits/stdc++.h>

using namespace std;
#define ll long long
ll base = 27;

ll mx = 1000005;
vector<ll> allmod = {1000000003, 1000000007, 123123123};
vector<ll> power[3];

int getpoweidx(int mod){
    for(int i = 0; i < allmod.size(); i++){
        if(allmod[i] == mod){
            return i;
        }
    }
}

void calcpower(){
    power[0].push_back(1);
    power[1].push_back(1);
    power[2].push_back(1);
    for(ll i = 1; i < mx; i++){
        power[0].push_back((power[0][i - 1] * base) % allmod[0]);
        power[1].push_back((power[1][i - 1] * base) % allmod[1]);
        power[2].push_back((power[2][i - 1] * base) % allmod[2]);
    }

}

class Hash{
public:
    string st;
    vector<ll> ph;
    ll mod;
    
    Hash(string st,ll mod){
        this->st = st;
        this->mod = mod;
        prefixhash();
    }

    ll getidx(char c){
        return c-'a'+1;
    }
    void prefixhash(){
        ph.push_back(getidx(st[0]));
        for(ll i = 1; i < st.size(); i++){
            ph.push_back(((ph[i-1]*base)%mod+ getidx(st[i]))%mod);
        }
    }

    ll calchash(ll l, ll r){

        if(l == 0){
            return ph[r];
        }
        return (ph[r] - (ph[l-1]*power[getpoweidx(mod)][r-l+1])%mod + mod)%mod;
    }
};

int main(){

    string txt, pat;
    cin >> txt >> pat;
    ll n = txt.size();
    ll m = pat.size();
    calcpower();
    Hash thash(txt,allmod[0]), phash(pat,allmod[0]);
    Hash thash1(txt,allmod[1]), phash1(pat,allmod[1]);
    Hash thash2(txt,allmod[2]), phash2(pat,allmod[2]);
    ll cnt = 0;
    for(ll i = 0; i+m-1 < n; i++){

        if((thash.calchash(i,i+m-1) == phash.calchash(0,m-1)) &&
            (thash1.calchash(i,i+m-1) == phash1.calchash(0,m-1))&&
            (thash2.calchash(i,i+m-1) == phash2.calchash(0,m-1))
        ){
            cnt++;
        }
    }

    cout << cnt << endl;
    
}