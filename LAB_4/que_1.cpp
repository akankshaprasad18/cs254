
#include<bits/stdc++.h>
using namespace std;


long long int ct=0;

void Merge(vector<int> &a, int l, int m, int h) {
    int i = l; // Initialize i to the start of the left sub-array
    int j = m + 1;
    int k = 0;
    vector<int> temp(h-l+1); // Temporary array to store merged sub-arrays

    while (i <= m && j <= h) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
             ct += (m - i + 1); // Increase count for all remaining elements in left sub-array
        }
    }

    while (i <= m) {
        temp[k++] = a[i++];
        // ct++;
    }

    while (j <= h) {
        temp[k++] = a[j++];
   
    }

    // Copying back the sorted elements to the original array
    for (i = l, k = 0; i <= h; i++, k++) {
        a[i] = temp[k];
    }
}

void MergeSort(vector<int> &a, int l, int h) {
    if (l <h) {
        int m = l + (h - l) / 2;
        MergeSort(a, l, m);
        MergeSort(a, m + 1, h);
        Merge(a, l, m, h);
    }
}

int main() {
    freopen("test_cases_Q1.txt","r",stdin);
    freopen("output_Q1.txt","w",stdout);
    int t;
    cin >> t;

    while(t--){
        int N1;
        cin >> N1;
        vector<int> a(N1);
       
       
       
        for(int i = 0; i<N1; i++){
            cin >> a[i];
        }

   
    MergeSort(a, 0, N1 - 1);

    cout << "INVERSION COUNT: "<<ct << endl;
    
}
}