#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int fish_flip2(vector<int> &fish){                                              //fish_flip1: flip fish to consecutive numbers
    int flipcnt=0;
    for(int index=0; index<fish.size(); index++){
        if(fish[index]!=index+1){                                               //need to flip
            flipcnt++;
            if(flipcnt>2) return -1;                                            //return if flipcnt>2

            int flip_end=index;
            while(fish[flip_end]!=index+1 && fish[flip_end]!=-(index+1)){       //find end of flip
                flip_end++;
            }
            
            vector<int> temp(fish.begin()+index, fish.begin()+flip_end+1);
            int temp_index=index;
            
            for(int j=temp.size()-1; j>=0; j--){
                fish[temp_index]=-temp[j];
                temp_index++;
            }
        }
    }

    return flipcnt;
}

int fish_flip1(vector<int> &origin){                                                    //fish_flip1: flip consecutive numbers to fish
    int flipcnt=0; vector<int> fish;

    for(int i=0; i<origin.size(); i++) fish.push_back(i+1);
    
    for(int index=0; index<fish.size(); index++){
        if(fish[index]!=origin[index]){                                                 //need to flip
            flipcnt++;
            if(flipcnt>2) return fish_flip2(origin);                                    //return go to fish_flip2 if flipcnt>2

            int flip_end=index;
            while(fish[flip_end]!=origin[index] && fish[flip_end]!=-(origin[index])){   //find end of flip
                flip_end++;
            }
            
            vector<int> temp(fish.begin()+index, fish.begin()+flip_end+1);
            int temp_index=index;
            
            for(int j=temp.size()-1; j>=0; j--){
                fish[temp_index]=-temp[j];
                temp_index++;
            }
        }
    }

    return flipcnt;
}

int main(){
    int k;
    cin >> k;

    for(int i=0; i<5; i++){
        int temp; vector<int> fishs;

        for(int j=0; j<k; j++){
            cin >> temp;
            fishs.push_back(temp);
        }

        int cnt = fish_flip1(fishs);

        switch (cnt){
        case 1:
            cout << "one\n";
            break;
        case 2:
            cout << "two\n";
            break;
        case -1:
            cout << "over\n";
            break;
        }
    }

    return 0;
}