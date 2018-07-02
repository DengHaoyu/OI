//
// Created by dhy on 6/25/18.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Person{
    int id;
    int coount;
    int weight;
};
bool cmp(Person p1,Person p2){
    if(p1.weight==p2.weight){
        return p1.id<p2.id;
    }else{
        return p1.weight>p2.weight;
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    int E[11]{0};
    vector<Person> persons;
    for(int i = 1;i<=n;i++){
        persons.push_back(* new Person());
    }
    for(int i = 1 ; i<=10;i++){
        cin>>E[i];
    }
    for(int i = 1 ; i <= n;i++){
        persons[i].id = i;
    }
    for(int i = 1;i<=n;i++)cin>>persons[i].weight;
    sort(persons.begin()+1,persons.end()+1,cmp);
    for(int i = 1;i<=n;i++){
        persons[i].coount = i;
    }
    for(int i = 1;i<=n;i++){
        persons[i].weight+=E[(persons[i].coount-1)%10+1];
    }
    sort(persons.begin()+1,persons.end()+1,cmp);
    for(int i = 1;i<=k;i++){
        cout<<persons[i].id<<" ";
    }
    return 0;
}

