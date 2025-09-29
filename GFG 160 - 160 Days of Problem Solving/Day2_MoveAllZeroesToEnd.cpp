/*
You are given an array arr[] of non-negative integers. You have to move all the zeros in the array to the right end while maintaining the relative order of the non-zero elements. The operation must be performed in place, meaning you should not use extra space for another array.

Examples:

Input: arr[] = [1, 2, 0, 4, 3, 0, 5, 0]
Output: [1, 2, 4, 3, 5, 0, 0, 0]
Explanation: There are three 0s that are moved to the end.
Input: arr[] = [10, 20, 30]
Output: [10, 20, 30]
Explanation: No change in array as there are no 0s.
Input: arr[] = [0, 0]
Output: [0, 0]
Explanation: No change in array as there are all 0s.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int a = -1;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == 0 && a == -1){
                a = i;
            }
            if(arr[i] != 0 && a != -1){
                arr[a] = arr[i];
                arr[i] = 0;
                a++;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, 9, 0, 0, 9, 2, 5, 7, 0, 1, 4};
    sol.pushZerosToEnd(arr);
    cout << "Sorted Array is : ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;
    return 0;
}

//Expected Output - {3, 9, 9, 2, 5, 7, 1, 4, 0, 0, 0}