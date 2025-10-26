#include "LinkedQueue.hpp"
template <typename T>
LinkedQueue<T>::LinkedQueue() {
    // TODO

    head = nullptr;
    last = nullptr;
    this->length = 0;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();

}

template <typename T>
T LinkedQueue<T>::back() const {
    // TODO
     if (head == nullptr) {
        throw string("back(): error, empty queue");
    }
    return last->value;
}

template <typename T>
void LinkedQueue<T>::clear() {
    // TODO
    Node* n = this->head;
  

    while (n != nullptr) {
        Node* prev = n;
        n = n->next;
        delete prev;
    }

    head = nullptr;
    last = nullptr;
    this->length = 0;

}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    // TODO
    this->head = nullptr;
    this->last = nullptr;
    this->length = 0;
    
    Node* curr = copyObj.head;
    while (curr != nullptr) {
        this->enqueue(curr->value);
        curr = curr->next;
    }

}

template <typename T>
void LinkedQueue<T>::dequeue() {
    // TODO

    if (head == nullptr) {
        throw string("dequeue(): error empty queue");
    }

    Node* curr = head;
    head = curr->next;
    delete curr;

    if (head == nullptr) {
        last = nullptr;
    }
    this->length--;
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    // TODO

    Node* n = new Node(elem);
    n->next = nullptr;

   if (head == nullptr) {
        head = n;
        last = n;

    } else { 
        last->next = n;
        last = n;
    }
    this->length++;
}

template <typename T>
T LinkedQueue<T>::front() const {
    // TODO

    if (this->length == 0) {
        throw string("front(): error no front access, empty queue");
    }

    return head->value;

}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}
