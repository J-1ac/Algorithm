#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool my_compare(string a, string b){
    return a.size()>b.size();
}

int main(){
    int n, max_num=9, sum=0; string word; vector<string> words; map<char, int> my_map;
    cin >> n;
    int ans[n]{};
    for(int i=0; i<n; i++){
        cin >> word;
        words.push_back(word);
    }

    sort(words.begin(), words.end(), my_compare);
    
    for(int j=0; j<words.size(); j++){
        for(int i=0; i<words[j].size(); i++){
            ans[j]*=10;
            if(my_map.find(words[j][i])==my_map.end()){
                my_map.insert({words[j][i], max_num});
                ans[j]+=max_num;
                max_num--;
            }else{
                ans[j]+=my_map[words[j][i]];
            }
        }
    }

    for (auto iter : my_map) {
		cout << iter.first << " " << iter.second << endl;
	}

    for(int i :ans) sum+=i;
    cout << sum;

    return 0;
}