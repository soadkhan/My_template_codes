#include<bits/stdc++.h>
using namespace std  ;

typedef long long int ll ;
#define inll(a) scanf("%lld" , &a)
#define sz 1000

map<ll , vector<ll> >tree ;
ll sub_tr[sz] ;
ll parent[sz] ;
ll visited[sz] ;

ll chain_Ind[sz] ; //
ll chain_Pos[sz] ; //

ll chain_Head[sz] ; //
ll chain_len[sz] ; //

ll base_ara[sz] ; //
ll pos_in_base[sz] ; //
ll chain_No = 1 ;
ll ptr = 1 ;

ll root ;

void dfs(ll s){
    sub_tr[s] = 1 ;
    visited[s] = 1  ;
    ll l = tree[s].size() ;
    for(ll i  = 0 ; i< l ; i++){
        if(visited[ tree[s][i] ] == -1){
            visited[tree[s][i]] = 1 ;
            parent[tree[s][i]] = s;
            dfs(tree[s][i]) ;
            sub_tr[s] += sub_tr[ tree[s][i] ] ;
        }
    }
}

void heavy_init(){
    memset(chain_Head , -1 , sizeof(chain_Head)) ;
    memset(chain_len , 0 , sizeof(chain_len)) ;
    memset(sub_tr , 0 , sizeof(sub_tr)) ;
    memset(visited , -1 , sizeof(visited)) ;
    memset(parent , -1 , sizeof(parent)) ;

    ptr = 1 ;
    chain_No = 1 ;

    dfs(root) ;
}


void HLD(ll cur){
    if(chain_Head[chain_No] == -1)
        chain_Head[chain_No] = cur ;

    chain_Ind[cur] = chain_No ;
    chain_Pos[cur] = chain_len[chain_No]  ;
    chain_len[chain_No] ++ ;

    base_ara[ptr] = cur ;
    pos_in_base[cur]  = ptr ;
    ptr++ ;

    ll sc = -1 ;
    ll in = -1 ;
    ll mx = -1 ;

    ll l = tree[cur].size() ;
    for(ll i  = 0 ; i< l ; i++ ){
        ll v = tree[cur][i] ;
        if(v != parent[cur] &&  sub_tr[v] > mx){
            sc = v ;
            mx = sub_tr[v] ;
            in  =  i ;
        }
    }

    if(sc != -1)
        HLD( sc ) ;

    for(ll i  = 0 ; i< l ; i++){
        ll  v = tree[cur][i] ;
        if( v!= sc && v!= parent[cur]){
            chain_No ++ ;
            HLD(v) ;
        }
    }
}

void input(){
    ll n  ;
    inll(n) ;
    for(ll i = 0 ; i< n-1 ; i++){
        ll a , b ;
        inll(a)  ; inll(b) ;
        tree[a].push_back(b) ;
        tree[b].push_back(a) ;
    }
}

/*
input

7
1 2
1 3
1 6
3 4
6 7
4 5

expected and the output

1 3 4 5 2 6 7
7 1 3 2 1 2 1
1 2 6
1 5 2 3 4 6 7
0 0 1 2 3 0 1
1 2 1 1 1 3 3
4 1 2
*/



int main(){
   //  freopen("in.txt" , "r" , stdin) ;

    input() ;
    root  = 1 ;
    heavy_init() ;

    HLD(root ) ;





    for(ll i  = 1 ; i< ptr ; i++ )
        cout<<base_ara[i]<<" " ;
    cout<<endl;

    for(ll i  = 1 ; i<=  7 ; i++)
        cout<<sub_tr[i]<<" " ;
    cout<<endl;

    for(ll i =1 ; i<= chain_No ; i++)
        cout<<chain_Head[i]<<" " ;
    cout<<endl;

    for(ll i  = 1 ; i<= 7 ; i++)
        cout<<pos_in_base[i]<<" ";
    cout<<endl;

    for(ll i = 1 ; i<= 7 ; i++)
        cout<<chain_Pos[i]<<" " ;
    cout<<endl;

    for(ll i  = 1 ; i<= 7 ; i++)
        cout<<chain_Ind[i]<<" " ;
    cout<<endl;

    for(ll i = 1 ; i<= chain_No ; i++)
        cout<<chain_len[i]<<" " ;
    cout<<endl;

    return  0 ;
}
