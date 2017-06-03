#include<bits/stdc++.h>
using namespace std;

typedef long long int ll ; 



////////BIT  range update and sum inits /////////
//  sz   variable is the size of bitree      ////
//  size of the tree must be customized      ////
//  according to problem .                   ////
//  call the          init()  method FIRST   ////  
//  update_Range(ll left , ll right , ll value )/
//  range_Sum(ll left , ll right)            ////

ll sz  = 100  ;               // size of BIT//// 
ll BITTree1[100] , BITTree2[100] ; 

void init(){
    memset(BITTree1 , 0 , sizeof(BITTree1)) ; 
    memset(BITTree2 , 0 , sizeof(BITTree2)) ;
}

int getSum(ll BITree[], ll index) {
    int sum = 0; 
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
    while (index>0)
    {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(ll BITree[], ll n, ll index, ll val) {
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
    while (index <= n)
    {
        BITree[index] += val;
        index += index & (-index);
    }
}
 
int sum(ll x, ll BITTree1[], ll BITTree2[]){
    return (getSum(BITTree1, x) * x) - getSum(BITTree2, x);
}

void updateRange(ll BITTree1[], ll BITTree2[], ll n, ll val, ll l, ll r) {
    updateBIT(BITTree1,n,l,val);
    updateBIT(BITTree1,n,r+1,-val);
 
    updateBIT(BITTree2,n,l,val*(l-1));
    updateBIT(BITTree2,n,r+1,-val*r);
}
 
int rangeSum(ll l, ll r, ll BITTree1[], ll BITTree2[]) {
    return sum(r, BITTree1, BITTree2) - sum(l-1, BITTree1, BITTree2);
}
  
void update_Range(ll l , ll r ,ll val){
    updateRange ( BITTree1 , BITTree2 , sz , val , l , r ) ;
}

ll range_Sum(ll l , ll r){
    rangeSum( l , r , BITTree1 , BITTree2 ) ;
}

///////////////  BIT range update and sum ends ///////////////

int main(){

    init() ;
   
    ll q = 3 ; 
    while(q--){
        ll l , r, v ; 
        cin>>l>>r>>v ; 
        /////////
        update_Range( l , r, v) ; 
        /////////
    }
 
    while(4){
        ll l , r ; 
        cin>>l >> r ; 

        cout << "Sum of elements from [" << l
         << "," << r << "] is ";
        //////////
        cout << range_Sum( l , r) << "\n";
        //////////
    }

    return 0;
}

