#include "deque.h"
void Deque::pushLeft(int value) {
  if (head == nullptr) {
    assert(tail == nullptr &&
           "If the head is a nullptr, the tail must be too\n");
    head = tail = new Deque::Node{value};
  } else {
    head->left = new Deque::Node{value};
    head->left->right = head;
    head = head->left;
  }
}

void Deque::pushRight(int value) {
  if (tail == nullptr) {
    assert(head == nullptr &&
           "If the tail is a nullptr, the head must be too\n");
    head = tail = new Deque::Node{value};
  } else {
    tail->right = new Deque::Node{value};
    tail->right->left = tail;
    tail = tail->right;
  }
}

int Deque::popLeft() {
  if (tail == nullptr) {
    assert(head == nullptr &&
           "If the tail is a nullptr, the head must be too\n");
    throw "Cannot popLeft an empty Deque!\n";
  }
  Deque::Node *tempHead = head;
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

int Deque::popRight() {
  if (tail == nullptr) {
    assert(head == nullptr &&
           "If the tail is a nullptr, the head must be too\n");
    throw "Cannot popRight an empty Deque!\n";
  }
  Deque::Node *tempTail = tail;
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

bool Deque::contains(int value) {
  Deque::Node *currentNode{head};
  while (currentNode != nullptr) {
    if (currentNode->value == value)
      return true;
    currentNode = currentNode->right;
  }
  return false;
}

std::ostream &operator<<(std::ostream &out, const Deque &dqueue) {
  Deque::Node *currentNode{dqueue.head};
  while (currentNode != nullptr) {
    out << currentNode->value << ' ';
    currentNode = currentNode->right;
  }
  return out;
}

Deque::~Deque() {
  while (head != nullptr) {
    Deque::Node *tempNode = head;
    head = head->right;
    delete tempNode;
  }
}
