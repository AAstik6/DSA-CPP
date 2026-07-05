#include<iostream>
#include<vector>
using namespace std;

class Node {
  public:
  int data;
  Node* next;
  Node* back;

  public:
  Node(int data1, Node* next1, Node* back1) {
    data = data1;
    next = next1;
    back = back1;
  }
  Node(int data1) {
    data = data1;
    next = nullptr;
    back = nullptr;
  }
};
// convert array to doubly LL
Node* convertarraytoDLL(vector<int> arr) {
  Node* head = new Node(arr[0]);
  Node* prev = head;
  for (int i=1; i<arr.size(); i++) {
    Node* temp = new Node(arr[i]);
    prev->next = temp;
    temp->back = prev;
    prev = temp;
  }
  return head;
}
//delete the head of DLL
Node* delete_head(Node* head) {
  if (head == NULL) return NULL;
  if (head->next == NULL) {
    delete head;
    return NULL;
  }
  else{
  Node* temp = head;
  head = head->next;
  delete temp;
  head->back = nullptr;
  return head;
  }
}
// delete the tail of DLL
Node* delete_tail(Node* head) {
  if (head == NULL) return NULL;
  if (head->next == NULL) {
    delete head;
    return NULL;
  }
  Node* temp = head;
  while(temp->next->next != NULL) {
    temp = temp->next;
  }
  delete temp->next;
  temp->next = nullptr;
  return head;
}
//delete the kth node of DLL
Node* delete_kthNode(Node* head, int k) {
  if (head == NULL) return NULL;
  Node* temp = head;
  int cnt = 0;

  while(temp != NULL) {
    cnt++;
    if (cnt == k) break;
    temp = temp->next;
  }
  Node* prev = temp->back;
  Node* front = temp->next;

  if (prev == NULL && front == NULL) {
    delete temp;
    return NULL;
  }
  else if (prev == NULL) {
    delete temp;
    front->back = nullptr;
    head = head->next;
    return head;
  }
  else if (front == NULL) {
    delete temp;
    prev->next = front;
    return head;
  }
  else if (prev != NULL && front != NULL) {
    prev->next = front;
    front->back = prev;
    delete temp;
  }
  return head;
}
// delete the node from the DLL
Node* node_delete(Node* head, int node) {
  Node* temp = head;
  //assuming node is never at head.
  while (temp != NULL) {
    temp = temp->next;
    if (temp->data == node) break;
  }

  Node* prev = temp->back;
  Node* front = temp->next;
  if (front == NULL) {
    prev->next = front;
    delete temp;
    return head;
  }
  else {
    prev->next = front;
    front->back = prev;
    delete temp;
    return head;
  }
}
// insert at the the head of the DLL
Node* insert_atHead(Node* head, int val) {
  if (head == NULL) {
    Node* new_node = new Node(val, nullptr, nullptr);
    return new_node;
  };
  Node* new_node = new Node(val, head, nullptr);
  head->back = new_node;
  head = new_node;
  return head;
}
// reverse the DLL
class Solution {
public:
    ListNode* reverseDLL(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL && head->prev == NULL ) return head;
        ListNode* temp = head;
        ListNode* last = nullptr;
        while (temp != NULL) {
            temp->prev = temp->next;
            temp->next = last;
            last = temp;
            temp = temp->prev;
        }
        head = last;
        return head;
    }
};
int main() {
  vector<int> arr = {1,2,3,4};
  Node* head = convertarraytoDLL(arr);
}
