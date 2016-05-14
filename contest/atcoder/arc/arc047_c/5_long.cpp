#include<cstdio>
#include<list>
using namespace std;
 
int main(){
  long N,K,q,i,j,t,r=1,flag=0;
  list<long> Nlist;
 
  scanf("%ld %ld",&N,&K);
 
  for(i=1;i<=N;i++){
    Nlist.push_back(i);
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
      list<long>::iterator it = Nlist.begin();
      for(j=1;j<t;j++){
        it++;
      }
      printf("%ld\n",*it);
      if(Nlist.size() != 1){
        Nlist.erase(it);
      }
    }
    else{
      t=N-i;
      list<long>::iterator it = Nlist.begin();
      for(j=1;j<t;j++){
        it++;
      }
      printf("%ld\n",*it);
      while(it != Nlist.begin()){
        it--;
        printf("%ld\n",*it);
      }
      break;
    } 
  }
  return 0;
}
