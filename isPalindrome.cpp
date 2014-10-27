/*
 Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome. 
*/

class Solution {
public:
    bool isPalindrome(string s) {
	int len = s.length();
	int i=0, j=0;
	char c1, c2;
	if (len == 0)
		return true;
	else{
		i = 0;
		j = len -1;
	
		while (i < j){
			c1 = tolower(s[i]);
			c2 = tolower(s[j]);

			if ( ! ((c1 >= '0' && c1 <= '9') || (c1 >= 'a' && c1 <= 'z')) ){
				i++;
				continue;
			}

			if ( ! ((c2 >= '0' && c2 <= '9') || (c2 >= 'a' && c2 <= 'z')) ){
				j--;
				continue;
			}

			if (c1 != c2){
				return false;
			}
			else{
				i++;
				j--;
			}
			
		}
		return true;
		
	}
        
    }
};
