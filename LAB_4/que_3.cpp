#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000000];

int Partition(int arr[],int l,int h) {
    int pivot=arr[h];
    int i=l-1;
    for(int j=l;j<=h;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[h]);
    return i;
    
}
int Quickselect(int k,int arr[],int l,int h){
    int pivot_f=Partition(arr,l,h);
    int size_r=h-pivot_f;
    if(size_r==k-1){
        
        return arr[pivot_f];
    }
    else if(size_r>k-1){
        return Quickselect(k,arr,pivot_f+1,h);
    }
    else{
        return Quickselect(k-(size_r+1),arr,l,pivot_f-1);
    }

}
signed main(){
    
    freopen("test_cases.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;

    while(t--){
        int N1;
        cin >> N1;
       
       
       
        for(int i = 0; i<N1; i++){
            cin >> a[i];
        }
    int k=2;

    int ans=Quickselect(k,a,0,N1-1);
    cout<<ans<<endl;
}
}