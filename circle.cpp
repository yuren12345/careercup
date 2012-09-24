/**
 * 找出带环单链表的环起始节点
 * 比如 ： 1，2，3，4，5，6，3，4，5，6，3.....
 * 3就是答案
 */
#include <iostream>
#include <cassert>

class LinkList {
  struct Node {
    Node(int param) {
      val = param;
      next = NULL;
    }
    
    int val;
    Node *next;
  };
  
public:
  LinkList() {
    header = NULL;
  }
  
  void insertNode(int val) {
    Node *curr = header;
    Node *prev = header;
    while (curr != NULL) {
      prev = curr;
      curr = curr->next;
    }
    
    if (header == NULL) {
      header = new Node (val);
    } else {
      curr = new Node(val);
      prev->next = curr;
    }
  }
  
  void linkEndTo(int val) {
    // find val Node and end
    Node *to = NULL;
    Node *end = header;
    assert(header != NULL);
    
    while (end->next != NULL) {
      if (end->val == val)
        to = end;
      
      end = end->next;
    }
    
    if (to != NULL) {
      end->next = to;
    } // TODO: add error report code
  }
  
  
  int findCirBeginPoint() const {
    Node *slower = header;
    Node *faster = header;
    
    while (slower->next != NULL && faster->next != NULL
           && faster->next->next != NULL) {
      slower = slower->next;
      faster = faster->next->next;
      
      
      if (slower == faster) {
        // find a meet point
        slower = header;
        while (slower != faster) {
          slower = slower->next;
          faster = faster->next;
        }
        return slower->val;
      }
    }
    
    std::cout << "No meeting point found " << std::endl;
    return -1;
  }
  
private:
  Node *header;
};


int main(void) {
  LinkList a;
  a.insertNode(1);
  a.insertNode(2);
  a.insertNode(3);
  a.insertNode(4);
  a.insertNode(5);
  a.insertNode(6);
  a.linkEndTo(3);
  
  std::cout << "The start of the circle is: " << a.findCirBeginPoint()
    << std::endl;
}