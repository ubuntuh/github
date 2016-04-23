// reference: submission 703699
#include <stdio.h>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
ll n;
ll d[100];
 
int dfs(int i, ll w){
    if(w > n){
        return 0;
    }
    if(i < 0){
        return 1;
    }
    if(w % d[i] == 0){
        return dfs(i - 1, w * d[i]);
    }
    else{
        return dfs(i - 1, w) + dfs(i - 1, w * d[i]);
    }
}
 
int main(){
    int q;
    scanf("%lld%d",&n,&q);
    for(int i = 0; i < q; i++){
        scanf("%lld",d + i);
    }
    printf("%d\n",dfs(q - 1, 1));
}
