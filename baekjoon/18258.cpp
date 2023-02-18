#include <iostream>
#include <queue>
using namespace std;

int main(void){
    queue<int> myq;
    int n,num;
    string order;
    cin>>n;

    for (int i=0; i<n; i++){
        cin>>order;
        if (order=="push"){    
            cin>>num;
            myq.push(num);
        }
        else if (order=="pop"){
            if (myq.size()>0){
                cout<<myq.front();
                myq.pop();
            }else {
                cout<<-1;
            }    
        }
        else if (order=="size"){  
            cout<<myq.size();  
        }
        else if (order=="empty"){  
            if (myq.size()>0){
                cout<<0;
            }else {
                cout<<1;
            }   
        }
        else if (order=="front"){    
            if (myq.size()>0){
                cout<<myq.front();
            }else {
                cout<<-1;
            }   
        }
        else if (order=="back"){    
            if (myq.size()>0){
                cout<<myq.back();
            }else {
                cout<<-1;
            }   
        }
    }

    return 0;
}