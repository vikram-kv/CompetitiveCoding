/// MINIMUM SEGMENT TREE RANGE QUERY IMPLEMENTATION
// 1 indexing followed

// SAMPLE INPUT

/*
5 6
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 1 5
u 3 10
q 1 5
*/

/*
1
1
2
3
*/


#include <bits/stdc++.h>
using namespace std;
#define NMAX 1000000

int tree[NMAX * 4];

void build_tree(int arr[], int v, int l, int r) {

    if(l == r) {
        tree[v] = arr[l];
    } else {

        int mid = (l+r) >> 1;
        build_tree(arr, 2*v, l, mid);
        build_tree(arr, 2*v+1,mid+1,r);
        tree[v] = min(tree[2*v], tree[2*v+1]);
    }
}

int find_min(int v, int tl, int tr, int l, int r) {

    if(l > r) return INT_MAX;
    if(l == tl && r == tr) {
        return tree[v];
    }
    
    int tm = (tl+tr)>>1;
    return min(find_min(2*v, tl, tm, l, min(tm,r)), find_min(2*v+1, tm+1,tr,max(tm+1,l),r));
}

void update(int v, int tl, int tr, int x, int y) {
    if(tl == tr) {
        tree[v] = y;
    }
    else {
        int tm = (tl+tr) >> 1;
        
        if(x <= tm) {
            update(2*v,tl,tm,x,y);
        }
        else {
            update(2*v+1,tm+1,tr,x,y);
        }

        tree[v] = min(tree[2*v], tree[2*v+1]);
    }
}

int main() {

    int N, Q;
    int A[NMAX];

    memset(tree, 0, sizeof tree);

    cin >> N >> Q;

    for(int i=1;i<=N;++i) {
        cin >> A[i];
    }

    build_tree(A,1,1,N);
    char opt;
    int l, r, x, y;
    for(int i=0;i<Q;++i) {
        cin >> opt;
        if(opt == 'q') {
            cin >> l >> r;
            cout << find_min(1,1,N,l,r) << endl;
        }
        else {
            cin >> x >> y;
            update(1,1,N,x,y);
        }
    }
    return 0;
}