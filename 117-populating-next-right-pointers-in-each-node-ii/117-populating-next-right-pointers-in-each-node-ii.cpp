/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    
    /*
    // This solution works for perfect binary tree
    void DFS(Node *prev, Node *cur) {
        if(cur == NULL) return;
        
        if(prev != NULL) prev -> next = cur;
        
        if(cur -> left != NULL) {
            DFS(prev? (prev -> right? prev -> right : prev -> left) : NULL, cur -> left);
            DFS(cur -> left, cur -> right);
        } else {
            DFS(prev? (prev -> right? prev -> right : prev -> left) : NULL,cur -> right);
        }
        return;
    }
    */
    
    
    
    Node* connect(Node* root) {
        
        Node *start = root;
        while(start != NULL) {
            
            Node *cur = start;
            Node *pre = NULL;
            start = NULL;
            while(cur != NULL) {
                if(cur -> left != NULL) {
                    if(start == NULL) start = cur -> left;
                    if(pre) pre -> next = cur -> left;
                    pre = cur -> left;
                }
                if(cur -> right != NULL) {
                    if(start == NULL) start = cur -> right;
                    if(pre) pre -> next = cur -> right;
                    pre = cur -> right;
                }
                cur = cur -> next;
            }
        }
        
        return root;
    }
};