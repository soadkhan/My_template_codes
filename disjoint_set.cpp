#include<bits/stdc++.h>
using namespace std ; 
typedef long long int ll ;  
#define MX 100010 
#define inll(a) scanf("%lld" , &a)
#define oull(a) printf("%lld\n" , a)

ll dis_ara[MX] ; 

//the parameter is the upper limit
void disjoint_init(ll n ){
	for(ll i  = 0 ; i<= n ; i++)
		dis_ara[i] = i  ;
}

ll find_head(ll a){
	if(dis_ara[a] == a) return  a ; 
	else {
		dis_ara[a] = find_head(dis_ara[a]) ; 
		return find_head(dis_ara[a]) ;
	}
}

void union_fun(ll a , ll b){
	ll u = find_head(a) ; 
	ll v = find_head(b) ; 

	if(u != v) dis_ara[u] = v ;
}

bool che_con(ll a, ll b){
    return ((find_head(a)==find_head(b))?true:false);
}

int main(){
	ll tests ; 
	inll(tests) ; 

	while(tests--){
		ll n ; 
		inll(n) ; 
		/////////

		disjoint_init(n) ; 

		/////////
		ll eg ; 
		inll(eg) ; 

		while(eg--){
			ll a, b ; 
			inll(a) ; inll(b) ; 

			union_fun(a  , b) ;
		}

		ll ans = 0 ; 
		for(ll i = 0 ; i< n ; i++)
			if(dis_ara[i] == i) ans++ ; 

		oull(ans) ; 
	}
	return  0 ;
}