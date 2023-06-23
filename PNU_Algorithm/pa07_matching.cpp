#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct My_cnt{
    int num;
    int cnt;
};

bool my_comp(const My_cnt &a, const My_cnt &b){
    return a.cnt < b.cnt;
}

int RK(const string &pattern, const string &text){                                                  //Rabin-Karp Algorithm
    int cnt=1, q=30011; long long p_hash=0, t_hash=0, dm=1;
    for(int i=0; i<pattern.length()-1; i++){                                                        //calculate d^m-1
        dm*=5;
        dm%=q;
    }
    
    for(int i=0; i<pattern.length(); i++){                                                          //initialize p_hash & t_hash
        p_hash*=5; t_hash*=5;
        p_hash+=int(pattern[i])-65; t_hash+=int(text[i])-65;
        p_hash%=q; t_hash%=q;
    }

    if(p_hash==t_hash){                                                                             //compare string if p_hash==t_hash    
        for(int i=0; i<pattern.length(); i++){
            if(pattern[i]!=text[i]) break;
            cnt++;
            if(i==pattern.length()-1) return cnt;
        }
    }
    for(int i=1; i<text.length()-pattern.length()+1; i++){                                          //calculate t_hash
        cnt++;
        t_hash=(5*(t_hash-(dm%q)*(text[i-1]-65))+(text[i+pattern.length()-1]-65))%q;
        if(t_hash<0)    t_hash=(t_hash+q)%q;
        if(t_hash==p_hash){                                                                         //compare string if p_hash==t_hash
            for(int j=0; j<pattern.length(); j++){  
                if(pattern[j]!=text[j+i]) break;
                cnt++;
                if(j==pattern.length()-1) return cnt;
            }
        }
    }
    return cnt;
}

void SP(const string &pattern, int *sp){                                                            //get SP for KMP Algorithm
    int k=-1; sp[0]=-1;
    for(int j=1; j<pattern.length(); j++){
        while(k>=0 && pattern[j]!=pattern[k+1]) k=sp[k];
        if(pattern[j]==pattern[k+1])    k++;
        sp[j]=k;
    }
}

int KMP(const string &pattern, const string &text){                                                 //KMP Algorithm
    int cnt=0, j=-1; int sp[pattern.length()] {};                                                   
    SP(pattern, sp);                                                                                //calculate prefix&suffix
    for(int i=0; i<text.length(); i++){
        while(j>=0 && text[i] != pattern[j+1]){                                                     //if text[i]!=pattern[j+1], update pattern index                
            j=sp[j];                                                                
            cnt++;
        }
        if(pattern[j+1]==text[i]){                                                                  //if text[i]==pattern[j+1], pattern index++
            j++;
        }
        cnt++;
        if(j==pattern.length()-1)   return cnt;                                                     //find string, return
    }
    return cnt;
}

void my_jump(const string &pattern, map<char, int> &jump){                                          //make jump map for Boyer Moore Algorithm
    for (int i=0; i<pattern.length(); i++) {
        jump[pattern[i]]=pattern.length()-i-1;
    }
}

int BM(const string &pattern, const string &text){                                                  //Boyer Moore Algorithm
    int cnt=0, i=0;
    map<char, int>jump;
    my_jump(pattern, jump);

    while(i<=text.length()-pattern.length()){
        int j=pattern.length()-1, k=i+pattern.length()-1;
        cnt++;
        while(j>0 && pattern[j]==text[k]){                                                          //if pattern[j]==text[k], compare by j--, k--
            cnt++;
            j--;
            k--;
        }
        if(j==0)    return cnt;                                                                     //if j==0, find string
        if(jump[text[i+pattern.length()-1]]>0) i+=jump[text[i+pattern.length()-1]];                 //if there is jump, i+=jump
        else                                   i++;                                                 //else just i++;
    }
    return cnt;
}

int main(){
    int cnt_p, cnt_t, cnt_RK, cnt_KMP, cnt_BM; string p, t, temp;
    cin >> cnt_p;
    for(int i=0; i<cnt_p; i++){
        cin >> temp;
        p+=temp;
    }
    cin >> cnt_t;
    for(int i=0; i<cnt_t; i++){
        cin >> temp;
        t+=temp;
    }

    cnt_RK=RK(p, t);
    cnt_KMP=KMP(p, t);
    cnt_BM=BM(p, t);

    My_cnt algorithms[3] = {{1, cnt_RK}, {2, cnt_KMP}, {3, cnt_BM}};
    sort(algorithms, algorithms+3, my_comp);


    for(int i=0; i<3; i++){
        if(i<2){
            if(algorithms[i].cnt==algorithms[i+1].cnt || algorithms[i].cnt==algorithms[i-1].cnt)    cout << "0";
            else                                                                                    cout << algorithms[i].num;
        }else if(i==2 && algorithms[i].cnt==algorithms[i-1].cnt){
            cout << "0";
        }else{
            cout << algorithms[i].num;
        }        
        if(i<2) cout << " ";
    }
     
    return 0;
}