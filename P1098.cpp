//
// Created by dhy on 18-6-23.
//
#include<iostream>
using namespace std;
int main() {
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    string str, ans;
    cin >> str;
    for (int i = 0; i < str.size() - 1; i++) {

        if (str[i] != '-') {
            ans.push_back(str[i]);
        } else {
            if(str[i+1]=='-'){
                ans.append(1,'-');
                ans.append(1,'-');
                i++;
                continue;
            }
            if(i==0){
                ans.push_back('-');
                continue;
            }
            if(isdigit(str[i-1])&&isalpha(str[i+1])||isalpha(str[i-1])&&isdigit(str[i+1])){
                ans.push_back('-');
                continue;
            }
            if(str[i-1]>=str[i+1]){
                ans.push_back('-');
                continue;
            }
            if (p3 == 1) {
                for (int j = str[i-1]+1; j < str[i + 1]; j++) {
                    if (p1 == 1) {
                        if (isdigit(j)) {
                            ans.append(p2, j);
                        } else {
                            ans.append(p2, j);
                        }
                    } else if(p1==2){
                        if (isdigit(j)) {
                            ans.append(p2, j);
                        } else {
                            ans.append(p2, j - 'a' + 'A');
                        }
                    }else{
                        ans.append(p2,'*');
                    }
                }
            } else {
                for (int j = str[i + 1]-1; j > str[i - 1]; j--) {
                    if (p1 == 1) {
                        if (isdigit(j)) {
                            ans.append(p2, j);
                        } else {
                            ans.append(p2, j);
                        }
                    } else if(p1==2){
                        if (isdigit(j)) {
                            ans.append(p2, j);
                        } else {
                            ans.append(p2, j - 'a' + 'A');
                        }
                    }else{
                        ans.append(p2,'*');
                    }
                }
            }
        }
    }
        ans.append(1, str[str.size() - 1]);
        cout << ans;
        return 0;
}