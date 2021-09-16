#include <stdio.h>
#define SIZE 1229
#define MOST 10000
int isprime(int *list,int index,int n){
    for(int i=0;i<index;i++){
        if(list[i]*list[i]>n)return 1;
        if(n%list[i]==0)return 0;
    }
    return 1;
}

int main(){
    int n,index=1,power=0,list[SIZE]={2};
    scanf("%d",&n);
    for(int i=3;i<MOST;i+=2)if(isprime(list,index,i))list[index++]=i;
    while(!isprime(list,index,n)){
        for(int i=0;i<index;i++){
            power=0;
            while(n%list[i]==0){
                power++;
                n/=list[i];
            }
            if(power>1){
                printf("%d^%d",list[i],power);
                if(n!=1)printf(" * ");
                break;
            }
            else if(power==1){
                printf("%d",list[i]);
                if(n!=1)printf(" * ");
                break;
            }
        }
    }
    if(n!=1)printf("%d",n);
}
