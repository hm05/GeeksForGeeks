/*
Given an array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. Do the mentioned change in the array in place.
Note: Consider the array as circular.

Examples :
Input: arr[] = [1, 2, 3, 4, 5], d = 2
Output: [3, 4, 5, 1, 2]
Explanation: when rotated by 2 elements, it becomes 3 4 5 1 2.
Input: arr[] = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20], d = 3
Output: [8, 10, 12, 14, 16, 18, 20, 2, 4, 6]
Explanation: when rotated by 3 elements, it becomes 8 10 12 14 16 18 20 2 4 6.
Input: arr[] = [7, 3, 9, 1], d = 9
Output: [3, 9, 1, 7]
Explanation: when we rotate 9 times, we'll get 3 9 1 7 as resultant array.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
  public:
    int gcd(int a, int b){
        if(b == 0){
            return a;
        }
        return gcd(b, a%b);
    }
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        int k = d%n;
        if (n != 0 && k != 0){
            int g = gcd(n, k);
        
            for(int i = 0; i < g; i++){
                int temp = arr[i];
                int j = i;
                while (true){
                    int next_j = (j + k) % n;
                    if (next_j == i){
                        break;
                    }
                    arr[j] = arr[next_j];
                    j = next_j;
                }
                arr[j] = temp;
            }
        }
    }
};

class previousSolution {
  public:

    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        for(int i = 0; i < d%n; i++){
            for(int j = 0; j < n-1; j++){
                swap(arr[j],arr[j+1]);
            }
        }
        
    }
};

int main (){
    Solution sol;
    vector<int> arr = {7,3,9,1};
    int d = 9;
    sol.rotateArr(arr, d);
    for (int nums : arr){
        cout << nums << " ";
    }
    return 0;
}

//Expected Output - {3, 9, 1, 7}