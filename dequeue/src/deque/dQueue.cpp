#include "dQueue.h"
void DQueue::pushLeft(int value) {
  if (head == nullptr) {
    assert(tail == nullptr &&
           "If the head is a nullptr, the tail must be too\n");
    head = tail = new QNode{value};
  } else {
    head->left = new QNode{value};
    head->left->right = head;
    head = head->left;
  }
}

void DQueue::pushRight(int value) {
  if (tail == nullptr) {
    assert(head == nullptr &&
           "If the tail is a nullptr, the head must be too\n");
    head = tail = new QNode{value};
  } else {
    tail->right = new QNode{value};
    tail->right->left = tail;
    tail = tail->right;
  }
}

int DQueue::popLeft() {
  if (tail == nullptr) {
    assert(head == nullptr &&
           "If the tail is a nullptr, the head must be too\n");
    throw "Cannot popLeft an empty DQueue!\n";
  }
  QNode *tempHead = head;
  int out = head->value;
  if (head == tail) {
    head = tail = nullptr;
  } else {
    head = head->right;
    head->left = nullptr;
  }
  delete tempHead;
  return out;
}

int DQueue::popRight() {
  if (tail == nullptr) {
    assert(head == nullptr &&
           "If the tail is a nullptr, the head must be too\n");
    throw "Cannot popRight an empty DQueue!\n";
  }
  QNode *tempTail = tail;
  int out = tail->value;
  if (head == tail) {
    head = tail = nullptr;
  } else {
    tail = tail->left;
    tail->right = nullptr;
  }
  delete tempTail;
  return out;
}

bool DQueue::contains(int value) {
  QNode *currentNode{head};
  while (currentNode != nullptr) {
    if (currentNode->value == value)
      return true;
    currentNode = currentNode->right;
  }
  return false;
}

std::ostream &operator<<(std::ostream &out, const DQueue &dqueue) {
  QNode *currentNode{dqueue.head};
  while (currentNode != nullptr) {
    out << currentNode->value << ' ';
    currentNode = currentNode->right;
  }
  return out;
}

DQueue::~DQueue() {
  while (head != nullptr) {
    QNode *tempNode = head;
    head = head->right;
    delete tempNode;
  }
}
