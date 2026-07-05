#include<iostream>
#include<set>
#include<vector>
using namespace std;

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

Node* convertarrtoLL(vector<int> arr) {
  Node* head = new Node(arr[0]);
  Node* mover = head;
  for (int i=1; i<arr.size(); i++) {
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }
  return head;
}
// delete the head of LL
Node* delete_head(Node* head) {
  if (head == NULL) return NULL;
  Node* temp = head;
  head = head->next;
  delete temp;
  return head;
}
// delete the tail of LL
Node* delete_tail(Node* head) {
  if (head == NULL) return NULL;
  // in case of 1 node.
  if (head->next == NULL) {
    delete head;
    return NULL;
  }
  Node* temp = head;
  while(temp->next->next != NULL) {
    temp = temp->next;
  }
  delete temp->next;
  temp->next = NULL;

  return head;
}
// delete the kth element of the list.
Node* deletekth_ele(Node* head, int k) {
  if (head == NULL) {
    return NULL;
  }
  Node* temp = head;
  if (k == 1) {
    head = head->next;
    delete temp;
    return head;
  }
  Node* prev = NULL;
  int cnt = 0;
  while (temp != NULL) {
    cnt++;
    if (cnt == k) {
      prev->next = prev->next->next;
      delete temp;
      break;
    }
    prev = temp;
    temp = temp->next;
  }
  return head;
}
/**
 * Leetcode --> 237.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = temp->next;
        delete temp;
    }
};
int main() {
  vector<int> arr = {1,2,3,4,5};
  Node* head = convertarrtoLL(arr);
  head = delete_head(head);
  cout << head;
}