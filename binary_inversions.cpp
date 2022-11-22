#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef long double ld;
typedef vector<int> vi;


void print_array(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}
ll calc_inv(int arr[], int n){
    int count_1 = 0;
    ll inv = 0;
    for(int i = 0;i<n;i++){
        if(arr[i]){
            count_1++;
        }
        else{
            inv += count_1;
        }
    }
    return inv;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int arr[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        int pre1[n];
        int pre0[n];
        int count_1 = 0;
        int count_0 = 0;
        for(int i = 0; i < n;i++){
            if(arr[i] == 1){
                count_1++;
            }
            pre1[i] = count_1;
        }
        for(int i = n-1;i>=0;i--){
            if(arr[i] == 0){
                count_0++;
            }
            pre0[i] = count_0;
        }
        ll inv = calc_inv(arr, n); 
        ll mx = inv;
        for(int i = 0;i<n;i++){
            if(arr[i] == 0){
                mx = max(mx, inv-pre1[i]+pre0[i]-1);
            }
            else{
                mx = max(mx, inv+pre1[i]-1-pre0[i]);
            }
        }
        cout<<mx<<endl;
    }
}