#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int pivot_cnt=0;                                                                  //gloval count val for quick_sort

void insertion_sort(vector<int> &nums, int k){                                    //insertion_sort
    int key, cnt=0;
    for(int i=1; i<nums.size(); i++){
        key=nums[i];                                                              //set a key left to right
        int j=i-1;
        while(j>=0 && nums[j]>key){
            if(i<=k) cnt++;                                             
            nums[j+1]=nums[j];
            j--;
        }
        if(i<=k && j>=0)    cnt++;                                                //add cnt except key moved to first index
        nums[j+1]=key;
    }
    cout << cnt << '\n';
}

void selection_sort(vector<int> &nums, int k){                                    //selection_sort
    for(int i=0; i<k; i++){
        int min_index=i;
        for(int j=i+1; j<nums.size(); j++){
            if(nums[j]<nums[min_index]) min_index=j;                              //find min elem & index
        }
        swap(nums[i], nums[min_index]);
    }
    for(int num :nums) cout << num << '\n';
}

void heapifying(vector<int> &nums, int size, int index){                          //make min tree
    int min_index=index, left=index*2+1, right=index*2+2;

    if(left<size && nums[left]<=nums[min_index])     min_index=left;
    if(right<size && nums[right]<=nums[min_index])   min_index=right;
    if(min_index!=index){                                                         //if min changed -> make min tree recursively
        swap(nums[index], nums[min_index]);
        heapifying(nums, size, min_index);
    }
}

void heap_sort(vector<int> &nums, int k){                                         //heap_sort
    for(int i=nums.size()/2-1; i>=0; i--)   heapifying(nums, nums.size(), i);     //initalizing heap
        
    for(int i=nums.size()-1; i>=nums.size()-k; i--) {                             //proceed heap_sort k times
        swap(nums[0], nums[i]);
        heapifying(nums, i, 0);
    }

    for(int i=0; i<nums.size()-k; i++) cout << nums[i] << '\n';
}

void recursive_quick(vector<int> &nums, int left, int right, int k){
    if(pivot_cnt==k) return;                                                      //if proceed k times -> return
    if(left<right) {
        int pivot = nums[left];                                                   //set a pivot as first elem
        int i=left, j=right;

        while(i<j){
            while (i<j && nums[j]>pivot)    j--;                                  //find a elem smaller then pivot start from right
            while (i<j && nums[i]<=pivot)   i++;                                  //find a elem larger then pivot start from left
            if(i<j)                         swap(nums[i], nums[j]);
        }

        swap(nums[left], nums[i]);                                                //locate the pivot
        pivot_cnt++;
        recursive_quick(nums, left, i-1, k);                                      //sort recursively
        recursive_quick(nums, i+1, right, k);
    }
}

void quick_sort(vector<int> &nums, int k){                                        //quick_sort
    recursive_quick(nums, 0, nums.size()-1, k);
    for(int num :nums) cout << num << '\n';
}

int main(){
    int kind, k, n, num; vector<int> my_nums;
    cin >> kind >> k >> n;
    for(int i=0; i<n; i++){
        cin >> num;
        my_nums.push_back(num);
    }

    switch(kind){
        case 1:  
            insertion_sort(my_nums, k);
            break;
        case 2:  
            selection_sort(my_nums, k);
            break;
        case 3:  
            heap_sort(my_nums, k);
            break;
        case 4:  
            quick_sort(my_nums, k);
            break;  
    }

    return 0;
}