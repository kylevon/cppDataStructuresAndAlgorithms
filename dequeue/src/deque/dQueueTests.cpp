#include "dQueueTests.h"
namespace DQueueTests {
void unitTests() {
  DQueue *myQueue = new DQueue{};
  for (int i = 0; i < 50; i++)
    myQueue->pushLeft(i);
  for (int i = 49; i >= 0; i--)
    assert(myQueue->popLeft() == i && "pushLeft and popLeft not working");
  for (int i = 0; i < 50; i++)
    myQueue->pushRight(i);
  for (int i = 49; i >= 0; i--) {
    assert(myQueue->popRight() == i && "pushRight and popRight not working");
  }
  for (int i = 0; i < 50; i++)
    myQueue->pushLeft(i);
  for (int i = 0; i < 50; i++) {
    assert(myQueue->popRight() == i && "pushLeft and popRight not working");
  }
  for (int i = 0; i < 50; i++)
    myQueue->pushRight(i);
  for (int i = 0; i < 50; i++) {
    assert(myQueue->popLeft() == i && "pushRight and popLeft not working");
  }
  for (int i = 0; i < 50; i++) {
    myQueue->pushLeft(i);
    assert(myQueue->contains(i) &&
           "contains doesn't works when inmediately adding");
    assert(!myQueue->contains(i + 1) && "false contains doesn't work");
  }
  for (int i = 0; i < 50; i++) {
    assert(myQueue->contains(i) && "contains does not work after adding");
  }
  delete myQueue;
}
} // namespace DQueueTests
