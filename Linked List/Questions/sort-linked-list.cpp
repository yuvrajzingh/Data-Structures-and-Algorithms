struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {

private: 
    ListNode* findMid (ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        return slow;
    }

    ListNode* merge(ListNode* right , ListNode* left){
        if(left == nullptr){
            return right;
        }
        if(right == nullptr){
            return left;
        }

        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        while(left != nullptr && right != nullptr){
            if(left -> val < right -> val){
                temp -> next = left;
                temp = left;
                left = left -> next;
            }
            else{
                temp -> next = right;
                temp = right;
                right = right -> next;
            }
        }
            while(left!=nullptr){
                temp -> next = left;
                temp = left;
                left = left -> next;
            }
            while(right!=nullptr){
                temp -> next = right;
                temp = right;
                right = right -> next;
            }

            ans = ans -> next;
            return ans;

    }

public:
    ListNode* sortList(ListNode* head) {
        //base case
        if(head ==nullptr || head -> next == nullptr){
            return head;
        }

        ListNode* mid = findMid(head);

        ListNode* left = head;
        ListNode* right = mid -> next;
        mid -> next = nullptr;

        //recursive calls to sort both halves

        left = sortList(left);
        right = sortList(right);

        //merge both halves

        ListNode* result = merge(right, left);

        return result;


    }
};