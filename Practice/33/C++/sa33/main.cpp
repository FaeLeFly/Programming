#include <iostream>
int *create(int m,int first,int range){
    int *ci=new int[m];
    int count=first;
    for (int i=0;i<m;i++){
        if (i!=0){count+=range;}
        ci[i]=count;
    }
    return ci;
}
int sort(int *ci,int m){
    int ne;
    for(int i=0;i<m;i++){
        for (int j=0;j<m-1;j++){
            if (ci[j]>ci[j+1]){
                ne=ci[j+1];
                ci[j+1]=ci[i];
                ci[i]=ne;
            }
            else{
                continue;
            }
        }
    }
    return *ci;
}
int print(int *ci,int m){
    for (int i=0;i<m;i++){
        std::cout<<ci[i];
    }
}
int main(){
    int m,first,range;
    std::cin>>m; std::cin>>first; std::cin>>range;
    int *ci=create(m,first,range);
    *ci = sort(ci,m);
    print(ci,m);
    delete [] ci;
    return 0;
}
