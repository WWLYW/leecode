/*
 Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

#include <iostream>
#include <map>
using namespace std;
typedef struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

class Solution {
public:
    void recoverTree(TreeNode *root) {
        map<int, int> traverse_map;
        midTraverseSort(root, traverse_map);
        midTraverseRecover(root, traverse_map);
        return;
    }
    
    void midTraverseSort(TreeNode *root, map<int,int> &traverse_map){
        if (root == NULL)
            return;
        midTraverseSort(root->left, traverse_map);
        traverse_map.insert(make_pair(root->val,0));
        midTraverseSort(root->right, traverse_map);
        return;
    }
    
    void midTraverseRecover(TreeNode *root, map<int,int> &traverse_map){
        if (root == NULL)
            return;
        midTraverseRecover(root->left, traverse_map);
        
        if (root->val != traverse_map.begin()->first)
            root->val = traverse_map.begin()->first;
	cout << traverse_map.begin()->first<<endl;
        traverse_map.erase(traverse_map.begin());
        
        midTraverseRecover(root->right, traverse_map);
        return;
    }
};

int CreateTreeNode(TreeNode *root) {
	int num;
	while(1){
		scanf("%d", &num);
		if (num == 0) break;
		if (root == NULL)
			root->val = num;
		else{
			TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
			node->val = num;
			TreeNode *temp = root;
			while(temp){
				if (temp->val > num){
					if (temp->left == NULL){
						temp->left = node;
						break;
					}
					else
						temp = temp->left;
				}
				else{
					if (temp->right == NULL) {
						temp->right = node;
						break;
					}
					else
						temp = temp->right;
				}
			}
		}
	}
}

int main(){
	TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
	CreateTreeNode(root);
	Solution a;
	a.recoverTree(root);
	
}
