#include <iostream>

using namespace std;

void heapify(int arr[],int n,int i);
void build_max_heap(int arr[],int n);
void heap_sort(int arr[],int n);
int count_distinct(int arr[],int i,int variable,int c,int n);
int distinct (int arr [],int n);

int main()
{
    int n;
    printf("Enter size of array:");
    cin>>n;
    int arr[n];
    printf("Enter the items you want to know the distinct between them:");
for (int i=0;i<n;i++){
      cin>>arr[i];
}

int count_dist =distinct(arr,n);
cout<<"Number of  distinct is: "<<count_dist;

    return 0;
}
void heapify(int arr[],int n,int i){
    int mx=i;
    int l=2*i+1;
    int r=2*i+2;
if(l<n&&arr[l]>arr[mx]) mx=l;
if(r<n&&arr[r]>arr[mx]) mx=r;
    if(mx!=i){
        int temp=arr[i];
        arr[i]=arr[mx];
        arr[mx]=temp;
        heapify(arr,n,mx);
    }
}

void build_max_heap(int arr[],int n){
for(int i=n/2-1;i>=0;i--){
    heapify(arr,n,i);
}
}

//sort array
void heap_sort(int arr[],int n){
build_max_heap(arr,n);
for(int i=n-1;i>0;i--){
    int temp=arr[0];
    arr[0]=arr[i];
    arr[i]=temp;
    heapify(arr,i,0);
}
}
int count_distinct(int arr[],int i,int variable,int c,int n){

if(i>n-1){
    return c;
}
else{
if(variable!=arr[i]){
    c++;
    variable=arr[i];}
    count_distinct(arr,i+1,variable,c,n);
}
}
int distinct (int arr [],int n){
heap_sort(arr,n);
    int variable=arr[0],c=1,i=1;
    return count_distinct(arr,i,variable,c,n);
}

