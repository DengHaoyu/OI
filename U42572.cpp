//
// Created by dhy on 18-10-4.
//
#include <iostream>
#include <stack>
using namespace std;
int order[3] = {0,1,2};
stack<int> stacks[3];
inline void success(){
    cout<<"SUCCESS"<<endl;
}
inline int abs(int x){
    if(x<0)return -x;
    return x;
}
inline void unsuccess(){
    cout<<"UNSUCCESS"<<endl;
}
int main(void){
    ios::sync_with_stdio(false);
    string command;
    cin>>command;
    int x,num;
    int t1,t2;
    while(command!="END"){
        if(command=="PUSH"){
            cin>>x>>num;
            stacks[order[x]].push(num);
            success();
        } else if(command=="POP"){
            cin>>x;
            if(stacks[order[x]].empty()){
                unsuccess();
                cin>>command;
                continue;
            }
            stacks[order[x]].pop();
            success();
        }else if(command=="ADD"){
            cin>>x;
            if(stacks[1].empty()||stacks[0].empty()){
                unsuccess();
                cin>>command;
                continue;
            }
            t1=stacks[1].top();
            stacks[1].pop();
            t1+=stacks[0].top();
            stacks[0].pop();
            stacks[order[x]].push(t1);
            success();
        }else if(command=="SUB"){
            cin>>x;
            if(stacks[1].empty()||stacks[0].empty()){
                unsuccess();
                cin>>command;
                continue;
            }
            t1=stacks[1].top();
            stacks[1].pop();
            t1-=stacks[0].top();
            stacks[0].pop();
            stacks[order[x]].push(abs(t1));
            success();
        }else if(command=="DEL"){
            cin>>x;
            if(stacks[order[x]].empty()){
                unsuccess();
                cin>>command;
                continue;
            }
            stacks[order[x]] = *new stack<int>();
        }else if(command=="MOVE"){
            cin>>x>>t1;
            while(!stacks[order[t1]].empty()){
                stacks[order[x]].push(stacks[order[t1]].top());
                stacks[order[t1]].pop();
            }
        } else if(command=="SWAP"){
            t2 = order[1];
            order[1] = order[0];
            order[0] = t2;
            success();
        }else{
            unsuccess();
        }
        cin>>command;
    }
    if(command=="END"){
        success();
        if(stacks[order[0]].empty()){
            cout<<"NONE"<<endl;
        }else {
            while (!stacks[order[0]].empty()) {
                cout << stacks[order[0]].top() << ' ';
                stacks[order[0]].pop();
            }
            cout<<endl;
        }
        if(stacks[order[1]].empty()){
            cout<<"NONE"<<endl;
        }else{
            while (!stacks[order[1]].empty()) {
                cout << stacks[order[1]].top() << ' ';
                stacks[order[1]].pop();
            }
            cout<<endl;
        }
    }
    return 0;
}
