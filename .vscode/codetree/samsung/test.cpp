#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int arr[10][10];
int myarr[4]={1,2,3,4};
bool visited[4];

void print_arr(int (&myarr)[10][10]){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cout << myarr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "-------------------------------------------------------\n";
}

void rotate_all(){
    int new_arr[10][10]{};
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            new_arr[j][10-i-1] = arr[i][j];
        }
    }
    print_arr(new_arr);
}

// 1. 순열 (Permutation)
void permutation(int n, vector<int>& newarr){
    if(newarr.size()==n){
        for(int i=0; i<newarr.size(); i++){
            cout << newarr[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int i=0; i<4; i++){
        if (!visited[i]){
            visited[i]=true;
            newarr.push_back(myarr[i]);
            permutation(n, newarr);
            newarr.pop_back();
            visited[i]=false;
        }
    }
}

// 2. 중복순열 (Permutation with Repetition)
void permutationWithRepetition(int n, vector<int>& newarr) {
    if (newarr.size() == n) {
        for (int i = 0; i < newarr.size(); i++) {
            cout << newarr[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < 4; i++) {
        newarr.push_back(myarr[i]);
        permutationWithRepetition(n, newarr);
        newarr.pop_back();
    }
}

// 3. 조합 (Combination)
void combination(int start, int n, vector<int>& newarr) {
    if (newarr.size() == n) {
        for (int i = 0; i < newarr.size(); i++) {
            cout << newarr[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i < 4; i++) {
        newarr.push_back(myarr[i]);
        combination(i + 1, n, newarr);
        newarr.pop_back();
    }
}

// 4. 중복조합 (Combination with Repetition)
void combinationWithRepetition(int start, int n, vector<int>& newarr) {
    if (newarr.size() == n) {
        for (int i = 0; i < newarr.size(); i++) {
            cout << newarr[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i < 4; i++) {
        newarr.push_back(myarr[i]);
        combinationWithRepetition(i, n, newarr);
        newarr.pop_back();
    }
}



int main(){
    int cnt=0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            arr[i][j] = cnt++;
        }
    }

    // print_arr(arr);

    // rotate_all();

    vector<int> newarr;
    int n = 2; // 선택할 원소의 개수

    cout << "(Permutation):" << endl;
    permutation(n, newarr);

    cout << "\n(Permutation with Repetition):" << endl;
    permutationWithRepetition(n, newarr);

    cout << "\n(Combination):" << endl;
    combination(0, n, newarr);

    cout << "\n(Combination with Repetition):" << endl;
    combinationWithRepetition(0, n, newarr);


    return 0;
}