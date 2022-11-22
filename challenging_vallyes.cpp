#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

const char nl = '\n';

void print_array(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
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
        int k = 1;
        int count = 0;
        for(int i = 1;i < n;i++){
            if(arr[i]-arr[i-1] > 0 and k > 0){
                count++;
                // cout<<"i->"<<i<<endl;
                k = 0;
            }
            else if(arr[i] - arr[i-1] < 0){
                k = 1;
            } 
        }
        if(k > 0){
            count++;
        }
        // cout<<"count"<<count<<endl;
        if(count == 1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}