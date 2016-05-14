#include<cstdio>
#include<list>
using namespace std;
 
int main(){
  int N,K,q,i,j,t,r=1,flag=0;
  list<int> Nlist;
 
  scanf("%d %d",&N,&K);
 
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
      list<int>::iterator it = Nlist.begin();
      for(j=1;j<t;j++){
        it++;
      }
      printf("%d\n",*it);
      if(Nlist.size() != 1){
        Nlist.erase(it);
      }
    }
    else{
      t=N-i;
      list<int>::iterator it = Nlist.begin();
      for(j=1;j<t;j++){
        it++;
      }
      printf("%d\n",*it);
      while(it != Nlist.begin()){
        it--;
        printf("%d\n",*it);
      }
      break;
    } 
  }
  return 0;
}
