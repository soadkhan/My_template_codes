#include<bits/stdc++.h>
using namespace std ;

typedef long long int ll ;
#define mx 2100100
#define inll(a)   scanf("%lld" ,&a )
#define oull(a)   printf("%lld\n" ,a )

struct node{
    ll ct ;
    ll adj[28] ;
    node(){
        ct = 0 ;
        memset(adj , -1 , sizeof(adj)) ;
    }
};

ll sx  = 1 ;
node  trie[mx] ;

void inser(char str[]){
    ll l   = strlen(str) ;
    ll cur = 1 ;
    for(ll i = 0 ; i< l ;i++){
        ll x = str[i] - 'a' + 1 ;
        if(trie[cur].adj[x]==-1){
            trie[cur].adj[x] = ++sx ;
        }
        cur = trie[cur].adj[x] ;
        trie[cur].ct++;
    }
}

ll query(char str[]){
    ll l  = strlen(str) ;
    ll cur = 1 ;
    for(ll i = 0 ; i< l ; i++){
        ll x = str[i]  - 'a' + 1 ;
        if(trie[cur].adj[x]==-1) return 0 ;
        cur  = trie[cur].adj[x] ;
    }
    if(trie[cur].ct > 0) return trie[cur].ct ;
    else return 0 ;
}

int main(){
    char str[100] ;
    ll n ;
    inll(n) ;
    getchar() ;
    while(n--){
        char cmd[10]  ;
        scanf("%s%s" , cmd , str) ;
        if(strcmp(cmd , "add")==0){
            inser(str) ;
        }
        else {
            oull(query(str)) ;
        }
    }
    return 0 ;
}
