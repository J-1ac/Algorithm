#include<bits/stdc++.h>
using namespace std;

int t, n;
string p,temp;
deque<int> nums;
bool reverseFlag;

// nums를 출력하는 함수
void printnums(){
    cout << "[";
    if(reverseFlag){
        for(int i=nums.size()-1; i>=0; i--){
            if(i!=0){
                cout << nums[i] << ",";
            }else{
                cout << nums[i];
            }
        }
    }else{
        for(int i=0; i<nums.size(); i++){
            if(i!=nums.size()-1){
                cout << nums[i] << ",";
            }else{
                cout << nums[i];
            }
        }
    }
    cout << "]\n"; 
}

// 문자열을 파싱하여 nums에 저장하는 함수
void parsing(){
    int index=0;

    while(index<temp.size()){
        if(temp[index] == '['){
            index++;
            continue;
        }else if(temp[index] == ']'){
            return;
        }else{
            string num = {};
            while(temp[index] != ',' && temp[index] != ']'){
                num+=temp[index];
                index++;
            }
            index++;
            nums.push_back(stoi(num));
        }
    }
}

// 주어진 함수를 수행하는 함수
void myfunc(){
    for(int i=0; i<p.size(); i++){
        if(p[i] == 'R'){
            // 실제로 reverse를 하는게 아닌, flag 변경
            reverseFlag = !reverseFlag;
        }
        if(p[i] == 'D'){
            // 유효성 검사 후 첫 번째 수 버리는 함수 수행
            if(nums.size() == 0){
                cout << "error\n";
                return;
            }
            if(reverseFlag){
                nums.pop_back();
            }else{
                nums.pop_front();
            }
        }
    }

    printnums();
}

int main(){
    cin >> t;
    for(int i=0; i<t; i++){
        nums.clear(); reverseFlag=false;                 // 전역변수 초기화
        cin >> p >> n >> temp;
        parsing();
        myfunc();
    }

    return 0;
}