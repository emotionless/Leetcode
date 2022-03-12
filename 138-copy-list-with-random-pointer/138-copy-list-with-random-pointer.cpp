/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    
    Node* copyList(Node* head) {
        if (head == nullptr) return nullptr;
        if (hashMap.find(head) != hashMap.end()) return hashMap[head];
        Node *cur = new Node(head->val);
        cur->next = copyList(head->next);
        cur->random = head->random;
        hashMap[head] = cur;
        return cur;
    }
    
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        Node *newHead = copyList(head);
        Node *cur = newHead;
        while (cur != nullptr) {
            cur->random = hashMap[cur->random];
            cur = cur->next;
        }
        return newHead;
    }
private:
    unordered_map<Node*, Node*> hashMap;
};