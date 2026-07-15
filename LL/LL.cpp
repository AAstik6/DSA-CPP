#include<iostream>
#include<set>
#include<vector>
#include<map>
using namespace std;

class ListNode {
  public:
  int val;
  ListNode* next;

  public:
  ListNode(int  val1, ListNode* next1) {
    val = val1;
    next = next1;
  }
  ListNode(int val1) {
    val = val1;
    next = nullptr;
  }
};

class Node {
  public:
  int data;
  Node* next;

  public:
  Node(int data1, Node* next1) {
    data = data1;
    next = next1;
  }
  Node(int data1) {
    data = data1;
    next = nullptr;
  }
};
//converting array to LL
Node* convertarraytoLL(vector<int> arr) {
  Node* head = new Node(arr[0]);
  Node* mover = head;

  for(int i=0; i<arr.size(); i++) {
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }
  return head;
}
int is_present(Node* head, int val) {
    Node* temp = head;
    while(temp != NULL) {
      if (temp->data == val) return true;
      temp = temp->next;
    }
    return 0;
}
int length_LL(Node* head) {
    int cnt = 0;
    Node* temp = head;
    while (temp != NULL) {
      cnt++;
      temp = temp->next;
    }
    return cnt;
}
//insertion at the front of the LL
Node* insert_head(Node* head, int val) {
  Node* temp = new Node(val, head);
  return temp;
}
// inserting the node at the last of the LL.
Node* insert_at_last(Node* head, int val) {
  Node* temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  Node* last_node = new Node(val);
  temp->next = last_node;
  return head;
}
// inserting at the Kth position.
Node* insert_at_k(Node* head, int val, int k) {
  if (head == NULL) {
    if (k == 1) {
      Node* x = new Node(val);
    }
  }
  if (k == 1) {
    Node* temp = new Node(val, head);
    return temp;
  }
  int cnt = 0;
  Node* temp = head;

  while (temp != NULL) {
    cnt++;
    if (cnt == k-1) {
      Node* x = new Node(val);
      x->next = temp->next;
      temp->next = x;
      break;
    }
    temp = temp->next;
  }
  return head;
}
// insert element before the element 'x'
Node* insert_before_x(Node* head, int val, int x) {
  if (head == NULL) return NULL;

  if (head->data == x) {
    Node* new_node = new Node(val, head);
    return new_node;
  }

  Node* temp = head;
  while (temp->next != NULL) {
    if (temp->next->data == x) {
      Node* new_node = new Node(val, temp->next);
      temp->next = new_node;
      break;
    }
    temp = temp->next;
  }
  return head;
}
// middle node of the LL
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;

        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        temp = head;
        int cnt2 = 0;
        while (temp != NULL) {
            cnt2++;
            if (cnt2 == (cnt/2)+1) break;
            temp = temp->next;
        }
        return temp;
    }
};
// Linked list Cycle
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        if (head == NULL) return false;
        if (head->next == NULL) return false;

        map <ListNode*, int> mpp;
        ListNode* temp = head;
        while(temp != NULL) {
            mpp[temp]++;
            if (mpp[temp] == 2) return true;
            temp = temp->next;
        }
        return false;
    }
};
// find the length of the loop in LL
/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    int findLengthOfLoop(ListNode *head) {
        map<ListNode*, int> mpp;

        if (head == NULL) return 0;
        if (head->next == NULL) return 0;

        ListNode* temp = head;
        int cnt = 0;

        while (temp != NULL) {
            cnt++;
            if (mpp.find(temp) != mpp.end()) {
                return cnt - mpp[temp];
            }
            mpp[temp] = cnt;
            temp = temp->next;
        }
        return 0;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        if (head->next == NULL) {
            delete head;
            return NULL;
        }
        ListNode* temp = head;
        int cnt1 = 0;

        while (temp != NULL) {
            cnt1++;
            temp = temp->next;
        }
        if (n==1) delete temp;
        if (cnt1 == n) {
            ListNode* del_node = head;
            head = head->next;
            delete del_node;
        }
        temp = head;
        int res = cnt1-n;
        while (temp != NULL) {
            res--;
            if (res == 0) {
                ListNode* del_node = temp->next;
                temp->next = temp->next->next;
                delete del_node;
            }
            temp = temp->next;
        }
        return head;
    }
};
// 142. Linked List Cycle II
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};

// 143. Reorder List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head != NULL) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second_half = reverse(slow->next);
        slow->next = nullptr;
        ListNode* first_half = head;

        while (second_half != NULL) {
            ListNode* temp1 = first_half->next;
            ListNode* temp2 = second_half->next;
            first_half->next = second_half;
            second_half->next = temp1;
            
            first_half = temp1;
            second_half = temp2;
        }
    }
};
int main() {
  vector<int> arr = {1,2,3,4};
  Node* head = convertarraytoLL(arr);
  is_present(head, 4);
  head = insert_head(head, 5);
  head = insert_at_last(head, 100);
}
