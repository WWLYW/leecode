/*Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue. 

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively. 

Note:
 You are not suppose to use the library's sort function for this problem. */
class Solution {
public:
    void sortColors(int A[], int n) {
        int temp[3];
        int result[n];
        memset(temp, 0, sizeof(temp));
        for(int i = 0; i < n; i++){
            temp[A[i]]++;
        }
        for(int i = 1; i < 3; i++){
            temp[i] += temp[i - 1];
        }
        
        for(int i = n - 1; i >= 0; i--){
            result[temp[A[i]] - 1] = A[i];
            temp[A[i]]--;
        }
        for(int i = 0; i < n; i++){
            A[i] = result[i];
        }
    }
};
