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
        int arrd[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
            arrd[j] = arr[j];
        }
        sort(arrd, arrd + n);
        for(int i = 0;i<n;i++){
            if(arr[i] != arrd[n-1]){
                cout<<arr[i] - arrd[n-1]<<' ';
            }
            else{
                cout<<arr[i] - arrd[n-2]<<' ';
            }
        }
        cout<<endl;
    }
}