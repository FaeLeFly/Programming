#include <iostream>
struct IntArray {
  int *data;
  int size;
};

int get(IntArray* arr, int index){
   if (index<0 || index>=arr->size){
       std::cout << "Error";
       abort();
   }
   else{
       return arr->data[index];
   }
}
int get (IntArray& arr, int index){
    return get( &arr, index);
}
void create(IntArray* arr, int size){
    if (size==0) abort();
    arr->data=new int[size];
    (*arr).size=size;
}
void create(IntArray& arr, int size){
    create(&arr,size);
}
void set(IntArray* arr, int index,int value){
    for (;index<arr->size;index++){
        if (index<0 || index>=arr->size){
            std::cout << "Error";
            abort();
        }
        arr->data[index]=value+1;
        value++;
    }
}
void set(IntArray& arr, int index,int value){
    set(&arr,index,value);
}
void print (IntArray* arr){
    for (int i=0;i<arr->size;i++){
            if (i!=arr->size-1){
                if (i==0)std::cout << "[";
                std::cout<<arr->data[i]<<",";
            }
            else {
                if (i==0) std::cout <<"["<<arr->data[i]<<"]";
                else std::cout<<arr->data[i]<<"]";
            }
        }
}
void print(IntArray &arr){
    print (&arr);
}
void resize(IntArray* arr, int newSize){
    if (newSize==0) abort();
    int *b=new int[newSize];
    if (newSize > arr->size){
        for (int i=0;i<newSize;i++){
            if (i<arr->size){
                b[i]=arr->data[i];
            }
            else{
                b[i]=0;
            }
        }
    }
    else{
        for (int i=0;i<newSize;i++){
            b[i]=arr->data[i];
        }
        }
    arr->size=newSize;
    delete [] arr->data;
    arr->data=new int[newSize];
    for (int i=0;i<newSize;i++){
        arr->data[i]=b[i];
    }
    delete [] b;
}
void resize(IntArray &arr,int newSize){
    resize(&arr, newSize);
}
void destroy(IntArray *arr){
    delete [] arr->data;
    arr->size=0;
    arr->data=nullptr;
}
void destroy (IntArray &arr){
    destroy(&arr);
}
int main()
{
   int size =30,index=0,value=0;
   IntArray arr;
   create(arr,size);
   set(arr,index,value);
   print (arr);
   size=50;
   resize(arr,size);
   print(arr);
   size=10;
   resize(arr,size);
   print (arr);
   destroy(arr);
   return 0;
}
