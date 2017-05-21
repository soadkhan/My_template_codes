#include<bits/stdc++.h>
using namespace std ;

typedef long long int ll ;
#define sz 1000
#define T_s 15

map<ll , vector<ll> >tree ;
ll level[sz] ;
ll par[sz] ;
ll visited[sz] ;
ll sp_table[T_s + 1][sz] ;
ll root ;
ll node_number_limit ;

void dfs(ll s){
    visited[s] = 1  ;
    ll l = tree[s].size() ;
    for(ll i  = 0 ; i< l ; i++){
        if(visited[ tree[s][i] ] == -1){
            visited[tree[s][i]] = 1 ;
            par[tree[s][i]] = s;
            level[tree[s][i]] = level[s] + 1 ;
            dfs(tree[s][i]) ;
        }
    }
}

void gen_sp_table(ll n){
    for(ll i  = 0 ; i<= n ; i++)
        sp_table[0][i]  = par[i] ;

    for(ll i = 1 ; i <= T_s ; i++)
        for(ll j  = 0  ; j <= n ; j++)
            if(sp_table[i-1][j]!=-1){
                ll age = sp_table[i-1][j]  ;
                sp_table[i][j] = sp_table[i-1][age] ;
            }
}


void LCA_init(){
	memset(level , 0 , sizeof(level)) ;
    memset(visited , -1 , sizeof(visited)) ;

    for(ll i = 0 ; i<= T_s ; i++)
        for(ll j = 0 ; j< sz ; j++)
            sp_table[i][j]  = -1 ;

    for(ll i  = 0 ; i< sz ; i++)
        par[i] = i  ;

    dfs(root) ;
    gen_sp_table(node_number_limit) ;

}


ll lca(ll u  , ll v){
    if(level[u] > level[v])
        swap(u , v)  ;

    for(ll i = T_s ; i>= 0  ; i--)
        if(level[u] <= level[sp_table[i][v]])
            v = sp_table[i][v] ;

    for(ll i = T_s ; i>= 0 ; i--)
        if(sp_table[i][u] !=  sp_table[i][v] ){
            u = sp_table[i][u] ;
            v = sp_table[i][v] ;
        }

    if(u==v) return  u ;
    return par[v] ;
}

void input() {
	tree.clear() ;
	cin>>node_number_limit ;
	for(ll i  = 1 ; i< node_number_limit ; i++){
		ll a , b ;
		cin>>a>>b ;
		tree[a].push_back(b) ;
		tree[b].push_back(a) ;
	}
}

int main(){
	input() ;
	root = 1 ;
	LCA_init() ;

	ll a , b ;
	while(cin>>a>>b){
		cout<<a<<" "<<b<<" -> "<<lca(a , b)<<endl;
	}

	return  0 ;
}
