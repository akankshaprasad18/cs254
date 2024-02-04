#include<bits/stdc++.h>
using namespace std;
int a[200000];
int b[200000];


int find_median(int arr[],int brr[],int n,int m, int low,int high) {
    //  int low=0;
    // int high=n;
    

    int cut1=(low+high)/2;
    int cut2=(n+m+1)/2-cut1;
    int l1,l2,r1,r2=0;
    if(cut1==0){
    l1=INT_MIN;
    }
    
    if(cut2==0){
    l2=INT_MIN;
    }
    if(cut1==n){
     r1=INT_MAX;
    }
    if(cut2==m){
     r2=INT_MAX;
    }
    l1=arr[cut1-1];
    l2=brr[cut2-1];
    r1=arr[cut1];
    r2=brr[cut2];
    if(l1<=r2 && l2<=r1){
        if((n+m)%2==0){
            return (max(l1,l2)+min(r1,r2))/2;
        }
        else{
            return max(l1,l2);
        }
    }
    else if(l1>r2){
        high=cut1-1;
        return find_median(arr,brr, n, m, low, high);
    }
    else{
        low=cut1+1;
        return find_median(arr,brr,n, m,low,high);
    }
}
int main(){
    // int arr[] = {2};
    // int n = 1;
    // int brr[]={1,3};
    // int m =2;
    // int low=0;
    // int high=n;
    // int ans=find_median(arr, brr, n, m,  low, high);
    // cout<<ans<<endl;
    freopen("test_cases_Q2.txt","r",stdin);
    freopen("output_Q2.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
       
        for(int i=0; i<n; i++)
            cin >> a[i];
        for(int i=0; i<m; i++)
            cin >> b[i];
        if(n>m){
        int low=0;
        int high=m;
        int ans=find_median(b, a, m, n,  low, high);
        cout<<ans<<endl;
        }
        else{
        int low=0;
        int high=n;
        int ans=find_median(a, b, n, m,  low, high);
        cout<<ans<<endl;

        }

        
        // cout << "Median of the two sorted arrays: "<< median_sorted(a, b) << endl;
    }



return 0;
}
