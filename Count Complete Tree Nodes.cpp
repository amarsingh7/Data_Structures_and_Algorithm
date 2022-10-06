class Solution {
public:
    int findleftheight(TreeNode* root){
        int h=0;
        while(root!=NULL){
            h++;
            root=root->left;
        }
        return h;
    }
    int findrightheight(TreeNode* root){
        int h1=0;
        while(root!=NULL){
            h1++;
            root=root->right;
        }
        return h1;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int lh=findleftheight(root);
        int rh=findrightheight(root);
        if(lh==rh)return (1 << lh)-1;
        return 1+countNodes(root->left) + countNodes(root->right);
        
    }
};
