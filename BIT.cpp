#include<bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

#define inll(a) scanf("%lld" , &a)
#define oull(a) printf("%lld\n" , a)
#define sz 1000


ll ara[sz] ;
ll BIT[sz]  ;


void update_bit(ll in , ll val){
    while(in < sz){
        BIT[in] += val ;
        in += in&(-in) ;
    }
}

ll sum_bit(ll in){
    ll res = 0 ;
    while( in > 0 ){
        res+= BIT[in] ;
        in -= in&(-in) ;
    }
    return  res ;
}


int main(){


    return  0 ;
}
