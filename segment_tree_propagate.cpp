#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

#define setzero(a)    memset(a,0,sizeof(a))
#define tc3(x)        printf("Case %d:\n",x)
#define inll(x)        scanf("%lld",&x)
#define rep1(n ,i)     for(ll i = 1 ; i<=n ; i++ )


#define  MX 100200

ll ara[MX] ;
ll tree[3*MX] ;
ll pro[3*MX] = {0} ;
ll n ;

void init(ll nd , ll be , ll en ){
    if( be == en){
        tree[nd] = ara[be] ;
        return ;
    }

    ll left  = 2*nd ;
    ll right =  left + 1 ;
    ll mid = (be+en)/2 ;

    init(left , be , mid) ;
    init(right , mid+1 , en) ;

    tree[nd] = tree[left] +  tree[right] ;
    return ;
}

void add(ll nd , ll be , ll en , ll i , ll  j, ll new_val ){
    if(i<=be && j>=en){
        pro[nd]+=new_val ;
        tree[nd]+= (en-be+1)*new_val ;
        return ;
    } // vitore

    if(i>en || j<be) {
        return ;
    } // baire

    ll left  =  nd*2 ;
    ll right =  left + 1 ;

    ll mid  = (be+en)/2 ;

    add(left , be , mid , i , j , new_val) ;
    add(right , mid+1 , en, i , j , new_val) ;

    tree[nd] = tree[left] + tree[right] + (en - be + 1)*pro[nd] ;
    return ;
}


ll  sum(ll nd  , ll be , ll en , ll i  , ll j , ll carry ){


    if(i>en || j<be) {
        return 0 ;
    } // baire

    if(i<=be && j>=en){
        return ( tree[nd]+(en-be+1)*carry ) ;
    }// vitore

    ll left  =  nd*2 ;
    ll right =  left + 1 ;

    ll mid  = (be+en)/2 ;

    ll ret_left = sum(left , be , mid , i , j , carry + pro[nd]) ;
    ll ret_right  = sum(right , mid+1 , en , i , j , carry + pro[nd]) ;

    return  ( ret_left + ret_right ) ;

}


int main(void) {
    //read ;
    //write ;
    ll tests ;
    inll(tests) ;

    rep1(tests , i ){
        tc3(i) ;
        setzero(tree) ;
        setzero(pro) ;
        ll q ;
        ll n ;
        inll(n) ; inll(q) ;
        while(q--){
            ll cmd , x , y , v ;
            inll(cmd) ;
            if(cmd==0){
                inll(x) ; inll(y) ; inll(v) ;
                add(1 , 0 , n-1 , x , y , v ) ;
            }
            if(cmd==1){
                inll(x) ; inll(y) ;
                printf("%lld\n" , sum(1 , 0 , n-1 , x , y , 0)) ;
            }

        }

    }


    return 0;
}


