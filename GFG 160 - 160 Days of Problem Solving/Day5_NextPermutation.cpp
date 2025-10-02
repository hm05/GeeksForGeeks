/*
Given an array of integers arr[] representing a permutation, implement the next permutation that rearranges the numbers into the lexicographically next greater permutation. If no such permutation exists, rearrange the numbers into the lowest possible order (i.e., sorted in ascending order). 
Note:  A permutation of an array of integers refers to a specific arrangement of its elements in a sequence or linear order.

Examples:
Input: arr[] = [2, 4, 1, 7, 5, 0]
Output: [2, 4, 5, 0, 1, 7]
Explanation: The next permutation of the given array is [2, 4, 5, 0, 1, 7].
Input: arr[] = [3, 2, 1]
Output: [1, 2, 3]
Explanation: As arr[] is the last permutation, the next permutation is the lowest one.
Input: arr[] = [3, 4, 2, 5, 1]
Output: [3, 4, 5, 1, 2]
Explanation: The next permutation of the given array is [3, 4, 5, 1, 2].
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int index = -1;
        for(int i = n-2; i >= 0; i--){
            if(arr[i] < arr[i+1]){
                index = i;
                break;
            }
        }
        if(index == -1){
            reverse(arr.begin(), arr.end());
        }
        else{
            for(int i = n - 1; i > index; i--){
                if(arr[i]>arr[index]){
                    swap(arr[index],arr[i]);
                    break;
                }
            }
            reverse(arr.begin()+index+1, arr.end());
        }
    }
};

int main(){
    Solution sol;
    vector<int> arr = {3, 4, 2, 5, 1};
    sol.nextPermutation(arr);
    for(int x : arr){
        cout << x << " ";
    }
    return 0;
}

// Expected - {3, 4, 5, 1, 2}