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
//converting array2LL
Node* convertarray2LL(vector<int>arr) {
  Node* head = new Node(arr[0]);
  Node* mover = head; 
  for (int i=1;  i<arr.size(); i++) {
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }
  return head;
}
// length of the LL
int length_LL(Node* head) {
  int cnt = 0;
  Node* temp = head;
  while (temp) {
    temp = temp->next;
    cnt++;
  }
  return cnt;
}
//check if the element is present
int isPresent(Node* head, int val) {
  Node* temp = head;
  while (temp != NULL) {
    if (temp->data == val) return 1;
    temp = temp->next;
  }
  return 0;
}
int main() {
  vector<int> arr = {2,5,8,7,3}; 
  // Node* y = new Node(arr[0], nullptr); // the new key word gives out the memory of the node that has been created from the params passed.
  Node* head = convertarray2LL(arr);
  cout << length_LL(head);
  cout << isPresent(head, 5);
}
