#include <iostream>
void create(int **ci,int m,int first,int range){
    *ci=new int[m];
    int count=first;
     for (int i=0;i<m;i++){
         if (i!=0){count+=range;}
         (*ci)[i]=count;
        }
}
void destroy(int **ci){
    delete [] (*ci);
    *ci=nullptr;
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
        if (i!=m-1){
            if (i==0)std::cout << "[";
            std::cout<<ci[i]<<",";
        }
        else{
            if (i==0) std::cout << "["<<ci[i]<<"]";
            else std::cout<<ci[i]<<"]";
        }
    }
    return *ci;
}
int main()
{
    int m,first=0,range=0;
    std::cin>>m; std::cin>>first; std::cin>>range;
    int *ci;
    create(&ci,m,first,range);
    *ci=sort(ci,m);
    print(ci,m);
    destroy(&ci);
    return 0;
}
