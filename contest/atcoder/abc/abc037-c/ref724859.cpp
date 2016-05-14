#include<iostream>
using namespace std;

int N,n,k,a,c,l;
long long int sum;

int main(){
    cin >> N >> k;
    n = N - k + 1;
    for(int i=1;i<=N;i++){
        cin >>a;
        l = min(i,N-i+1);
        c = min(n,k);
        c = min(l,c);
        sum += (long long int)c*a;
    }

    cout << sum << endl;

    return 0;
}
