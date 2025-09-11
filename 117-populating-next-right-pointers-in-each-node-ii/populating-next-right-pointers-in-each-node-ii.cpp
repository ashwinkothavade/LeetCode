class Solution {
public:
    Node* connect(Node* head) {
        Node* parent = head;
        Node* childHead = nullptr;
        Node* child = nullptr;

        while (parent != nullptr) {
            while (parent != nullptr) {
                if (parent->left != nullptr) {
                    if (childHead == nullptr) {
                        childHead = parent->left;
                    } else {
                        child->next = parent->left;
                    }
                    child = parent->left;
                }
                if (parent->right != nullptr) {
                    if (childHead == nullptr) {
                        childHead = parent->right;
                    } else {
                        child->next = parent->right;
                    }
                    child = parent->right;
                }
                parent = parent->next;
            }
            parent = childHead;
            childHead = nullptr;
            child = nullptr;
        }
        return head;
    }
};
