#include <bits/stdc++.h>
using namespace std;

const int mx = 100005;
int def = 0;
vector<int> arr(mx,def);
vector<int> tree(4*mx,def);


int f(int a, int b){
    return max(a,b);      //here we can use +,min,bit OR   etc
}

int build(int i, int tl, int tr){
    
    if(tl == tr){
        tree[i] = arr[tl];
        return tree[i];
    }

    int m = (tl+tr)/2;
    tree[i*2] = build(i*2, tl,m);
    tree[i*2+1] = build(i*2+1, m+1,tr);
    tree[i] = f(tree[i*2], tree[i*2+1]);
    return tree[i];
}

int update(int i, int tl, int tr, int ui){

    if(tl == tr && tl == ui){ // tl == tr == ui
        tree[i] = arr[ui];
        return tree[i];
    }

    if(ui < tl || tr < ui){
        return tree[i];
    }

    int m= (tl+tr)/2;
    tree[2*i] = update(2*i, tl, m, ui);
    tree[2*i+1] = update(2*i+1, m+1,tr, ui);
    tree[i] = f(tree[2*i],tree[2*i+1]);
    return tree[i];

}

int query(int i, int tl, int tr, int l, int r){
    
    if(l <= tl && tr<= r){ // full
        return tree[i];
    }

    if(l > tr || tl > r){
        return def;
    }

    int m = (tl+tr)/2;
    int left = query(2*i, tl, m,l,r);
    int right = query(2*i+1, m+1,tr, l,r);
    return f(left,right);
}

int main()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    build(1,1,n); // 1 -> tree idx // 1 -> left index of arr

    // for(int i = 1; i <= 4*n; i++){
    //     cout << tree[i] << " ";
    // }

    int q;
    cin >> q;
    while(q--){
        int op;
        cin >> op;
        if(op == 1)
        {
            int i,x;
            cin >> i >> x;
            arr[i] = x;
            update(1,1,n,i);
        }else{
            int l,r;
            cin >> l >> r;
            cout << query(1,1,n,l,r) << "\n";
        }
    }
    
}
/**
8
2 9 3 4 8 7 6 7
3
1 0 7
2 11 0
1 0 7
**/