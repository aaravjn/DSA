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
        int a, b, c;
        cin>>a>>b>>c;
        int arr[3] = {a, b, c};
        sort(arr, arr+3);
        cout<<arr[1]<<endl;
    }
}