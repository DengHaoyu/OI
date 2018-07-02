//
// Created by dhy on 6/26/18.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Student{
    int id;
    int chinese;
    int math;
    int english;
    int sum;
};
bool cmp(Student s1,Student s2){
    if(s1.sum!=s2.sum){
        return s1.sum>s2.sum;
    }else{
        if(s1.chinese!=s2.chinese)return s1.chinese>s2.chinese;
        else return s1.id<s2.id;
    }
}
int main(){
    int n;
    cin>>n;
    Student *sts = new Student[n+1]();
    for(int i = 1;i<=n;i++){
        sts[i].id = i;
        cin>>sts[i].chinese>>sts[i].math>>sts[i].english;
        sts[i].sum = sts[i].chinese+sts[i].english+sts[i].math;
    }
    sort(sts+1,sts+n+1,cmp);
    for(int i = 1 ;i<=5;i++)cout<<sts[i].id<<" "<<sts[i].sum<<endl;
    return 0;
}
