class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        Node* head = root;
        while(head != NULL) {
            Node* temp = new Node(0);
            Node* dummy = temp;
            while(head != NULL) {
                if(head->left != NULL) {
                    temp->next = head->left;
                    temp = temp->next;
                }
                if(head->right != NULL) {
                    temp->next = head->right;
                    temp = temp->next;
                }
                head = head->next;
            }
            head = dummy->next;
            delete dummy;
        }
        return root;
    }
};