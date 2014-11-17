/*Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.*/

//之前一直都错误的思路，没有想到把配对的信息记录下来
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        int *A = new int[len];
        for (int i = 0; i < len; i++){//初始化
                A[i] = 0;
        }
        int num = 0, max = 0;
        for(int i = 0; i < len; i++){
                if (s[i] == ')' && i > 0){
                        for(int j = i-1; j >=0 ; j--){
                                if (s[j] == '(' && A[j] == 0){
                                        A[j] = 1;
                                        A[i] = 1;
                                        break;//跳出
                                }
                        }
                }
        }
          
        for(int i = 0; i < len; i++){
                if (A[i] > 0){
                        num++;
                }
                if (A[i] == 0 || (i == len -1) ){
                        if (num > max) max = num;
                        num = 0;//清零
                }
        }
        delete [] A;
        return max; 
    }
};  
