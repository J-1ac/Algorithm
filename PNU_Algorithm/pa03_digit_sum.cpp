#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
Main Idea
#1 choose n1 which all digit is different.
#2 choose n2 maching with n1.
#3 check is there any duplicated elem between n1 and n2
#4 cal digit_sum and update max_digit_sum
*/

vector<int> get_digit(int my_num){                                                                  // get each digit and return vector<int>
    vector<int> ans;
    ans.push_back(my_num%10);
    my_num/=10;
    ans.push_back(my_num%10);
    my_num/=10;
    ans.push_back(my_num);
    return ans;
} 

bool is_different_digit(const vector<int>& num1, const vector<int>& num2){                          // check is there any duplicated elem and return bool
    bool ans = true;
    for(int i=0; i<3; i++){
        if(num1[i]==num2[0] || num1[i]==num2[1] || num1[i]==num2[2]){
            ans=false;
            break;
        }
    }
    return ans;
}

int main(){
    int n, max_digit_sum=-1, max_n1, max_n2;
    cin >> n;

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<10; k++){
                int n1=0, n2=0, digit_sum=0; vector<int> n1_digit, n2_digit; bool ispossible=true;
                if(i!=j && i!=k && j!=k){                                                                               // check n1's digits are duplicated
                    n1=i*100+j*10+k;
                    n2=n-n1;
                    if(n1<12 || n2<12 || n1>987 || n2>987)  continue;                                                   // check edge case
                    
                    n2_digit=get_digit(n2);
                    if(n2_digit[0]==n2_digit[1] || n2_digit[0]==n2_digit[2] || n2_digit[1]==n2_digit[2]) continue;      // check n2's digits are duplicated 

                    n1_digit=get_digit(n1);
                    ispossible=is_different_digit(n1_digit, n2_digit);                                                  // check is there any duplicated digit between n1 and n2
                    
                    if(ispossible){
                        for(int l=0; l<3; l++){                                                                         // cal digit_sum
                            digit_sum+=n1_digit[l];
                            digit_sum+=n2_digit[l];
                        }
                        if(digit_sum>=max_digit_sum){                                                                   // update max_digit_sum
                            max_digit_sum=digit_sum;
                            max_n1=n1;
                            max_n2=n2;
                        }
                    }
                }
            }
        }
    }

    /*
    check point
    #1 max_n2 always bigger than max_n1
    #2 note the output format when max_n2 is 2 digits
    #3 if max_digit_sum==-1 -> there is no ans
    */

    if(max_digit_sum==-1)   cout << max_digit_sum;
    else if(max_n2>99)      cout << max_n2 << ' ' << max_n1 << ' ' << max_digit_sum;                 
    else                    cout << '0' << max_n2 << ' ' << max_n1 << ' ' << max_digit_sum;


    return 0;
}