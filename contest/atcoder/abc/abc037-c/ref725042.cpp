#include<iostream>
using namespace std;
 
int N,K,i;
int A[100005],C[100005];
long long int sum;
 
int main(){
    cin >> N >> K;
    for(i=0;i<N;i++){
        cin >> A[i];
    }

    for(i=0;i+K<=N;i++){
        C[i]++;
        C[i+K]--;
    }

    for(i=1;i<N;i++){
        C[i] += C[i-1];
    }

    for(i=0;i<N;i++){
        sum += (long long int)A[i]*C[i];
    }

    cout << sum << endl;

    return 0;
}
