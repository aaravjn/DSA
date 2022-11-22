#include <iostream>
#include <vector>

using namespace std;

bool find_char(char &c, vector<char> &taken){
    for(int i = 0; i<taken.size() ; i++){
        if(c == taken[i]){
            return 1;
        }
    }
    return 0;
}

void permut(string &s, vector<char> taken, int n){
    if(taken.size() == n){
        for(int j = 0;j < taken.size(); j++){
            cout<<taken[j];
        }
        cout<<endl;
        return ;
    }
    for(int j = 0;j < s.length();j++){
        if(!find_char(s[j], taken)){
            taken.push_back(s[j]);
            permut(s, taken, n);
            taken.pop_back();
        }
    }
}
int main(){
    string s = "abcd";
    permut(s, {}, s.length());
}