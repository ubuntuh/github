// Accepted.
// もともとのコードでは、大量のテストのうち、ごく少数において WA (Wrong Answer)、または TLE (Time Limit Exceeded) とされていました。
// int 型として宣言されていた変数を long 型として宣言しなおしたところ、1 件の TLE を除いて AC (Accepted) となりました。
// データ構造として list を用いていたのを、配列による実装に変更したところ、全てのテストで AC (Accepted) を得ることができました。
#include<cstdio>
using namespace std;

// int 型として宣言されていた変数を long 型として宣言します。
// 話を簡単にするために、int 型のままでよいものも全て long 型にします。
long N,K,q,i,j,t,r=1,flag=0;
// 値 [1, 100000] を添字 [1, 100000] に格納するために要素数が 100000 + 1 個の配列を確保します。
// 添字をわかりやすくするため、0 番目の要素は使いません。
// すでに使ってしまいもう使うことのできない要素は -1 で表すことにします。
long Nlist[100000 + 1];
// リストの中の index 番目の要素を返して、今後その要素を使用不能にする関数です。
long useCharacter(long index) {
    for (long a = 1; a <= N; a++) {
        if (Nlist[a] != -1) {
            if (index == 1) {
                long temp = Nlist[a];
                Nlist[a] = -1;
                return temp;
            }
            index--;
        }
    }
    return -1;
}
// リストの中の index 番目の要素から順に、手前に見ていき、それ以下の要素を全て出力する関数です。
void consume(long index) {
    long a;
    for (a = 1; a <= N; a++) {
        if (Nlist[a] != -1) {
            if (index == 1) break;
            index--;
        }
    }
    while (a != 0) {
        if (Nlist[a] != -1) {
            printf("%ld\n", Nlist[a]);
        }
        a--;
    }
}
int main(){
  scanf("%ld %ld",&N,&K);
 
  for(i=1;i<=N;i++){
    Nlist[i] = i;
  }
  
  for(i=0;i<N;i++){
    if(flag==0){
      q=( (N-i)*r )/K;
      r=( (N-i)*r )%K;
      if(r==0){
        flag=1;
        t = q;
      }else{
        t = q+1;
      }
      printf("%ld\n",useCharacter(t));
    }
    else{
      consume(N-i);
      break;
    } 
  }
  return 0;
}
