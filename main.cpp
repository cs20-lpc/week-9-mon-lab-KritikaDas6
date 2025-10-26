#include "LinkedQueue.hpp"
#include <iostream>
#include <string>
using namespace std;

int main() {

    cout << "=== LINKED QUEUE TEST DRIVER ===\n" << endl;


    cout << "Test 1: Integer Queue - Basic Operations\n";

    LinkedQueue<int> intQueue;
    cout << "Queue created. Is it empty? " << (intQueue.isEmpty() ? "Yes" : "No") << endl;

    // Try front/back on empty queue
    try {
        cout << "Front: " << intQueue.front() << endl;
    } catch (string& e) {
        cout << "Caught exception (front): " << e << endl;
    }
    try {
        cout << "Back: " << intQueue.back() << endl;
    } catch (string& e) {
        cout << "Caught exception (back): " << e << endl;
    }

  
    cout << "\nTest 2: Enqueuing 6 numbers...\n";
    for (int i = 1; i <= 6; i++) {
        intQueue.enqueue(i * 5);
        cout << "Enqueued: " << i * 5 << endl;
    }

    cout << "Front: " << intQueue.front() << endl;
    cout << "Back: " << intQueue.back() << endl;
    cout << "Length: " << intQueue.getLength() << endl;


    cout << "\nTest 3: Dequeuing two numbers...\n";
    intQueue.dequeue();
    intQueue.dequeue();
    cout << "After removing 2, front is now: " << intQueue.front() << endl;
    cout << "Length: " << intQueue.getLength() << endl;


    LinkedQueue<int> copyQueue(intQueue);
    cout << "\nTest 4: Copy Constructor\n";
    cout << "Copy created. Front: " << copyQueue.front()
         << ", Back: " << copyQueue.back()
         << ", Length: " << copyQueue.getLength() << endl;

   
    LinkedQueue<int> assignedQueue;
    assignedQueue.enqueue(100);
    assignedQueue.enqueue(200);
    assignedQueue = intQueue;

    cout << "\nTest 5: Assignment Operator\n";
    cout << "Assigned queue created. Front: " << assignedQueue.front()
         << ", Back: " << assignedQueue.back()
         << ", Length: " << assignedQueue.getLength() << endl;


    cout << "\nTest 6: Clear Function & Empty Queue Check\n";
    intQueue.clear();
    cout << "Queue cleared. Is empty? " << (intQueue.isEmpty() ? "Yes" : "No") << endl;

    // Test exceptions after clear
    try {
        intQueue.front();
    } catch (string& e) {
        cout << "Caught exception on front(): " << e << endl;
    }
    try {
        intQueue.dequeue();
    } catch (string& e) {
        cout << "Caught exception on dequeue(): " << e << endl;
    }

  
    cout << "\nTest 7: String Queue\n";

    LinkedQueue<string> strQueue;
    strQueue.enqueue("Red");
    strQueue.enqueue("Green");
    strQueue.enqueue("Blue");

    cout << "Front: " << strQueue.front() << endl;
    cout << "Back: " << strQueue.back() << endl;
    cout << "Length: " << strQueue.getLength() << endl;

    strQueue.dequeue();
    cout << "After one dequeue, new front: " << strQueue.front() << endl;

    // Copy and assignment for string queue
    LinkedQueue<string> strCopy(strQueue);
    LinkedQueue<string> strAssigned;
    strAssigned = strQueue;

    strAssigned.enqueue("Yellow");

    cout << "Copied string queue - length: " << strCopy.getLength()
         << ", front: " << strCopy.front() << ", back: " << strCopy.back() << endl;
    cout << "Assigned + modified string queue - front: " << strAssigned.front()
         << ", back: " << strAssigned.back() << ", length: " << strAssigned.getLength() << endl;

    strQueue.clear();
    cout << "Cleared string queue. Empty? " << (strQueue.isEmpty() ? "Yes" : "No") << endl;

    cout << "\n=== ALL TESTS COMPLETED SUCCESSFULLY ===" << endl;

    return 0;
}
