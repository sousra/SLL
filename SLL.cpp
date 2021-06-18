#include "SLL.h"

#include <cassert>

SLL::Node* SLL::getNode(size_t idx) {
    assert(idx < _size);
    Node* cur = _head;
    size_t i = 0;
    while(i != idx) {
        cur = cur->_next;
        ++i;
    }
    return cur;
}

SLL::SLL() {
    _head = nullptr;
    _size = 0;
}

SLL::SLL(const SLL& other) {
    Node* curNode = other._head;
    while(curNode) {
        insert(_size, curNode->_value);
        curNode = curNode->_next;
    }
}

SLL& SLL::operator=(const SLL& other) {
    clear();
    Node* curNode = other._head;
    while(curNode) {
        insert(_size, curNode->_value);
        curNode = curNode->_next;
    }
}

SLL::SLL(SLL&& other) noexcept {
    _head = other._head;
    _size = other._size;
    other._head = nullptr;
    other._size = 0;
}

SLL& SLL::operator=(SLL&& other) noexcept {
    std::swap(_head, other._head);
    std::swap(_size, other._size);
    return *this;
}

SLL::~SLL() {
    clear();
}

void SLL::pushFront(ValueType value) {
    Node* temp = new Node(value);
    temp->_next = _head;
    _head = temp;
    ++_size;
}

void SLL::insert(size_t idx, ValueType value) {
    if (idx == 0) {
        pushFront(value);
    }
    else {
        Node* cur = new Node(value);
        Node* prev = getNode(idx - 1);
        cur->_next = prev->_next;
        prev->_next = cur;
        ++_size;
    }
}

void SLL::popFront() {
    assert(_size != 0);
    Node* temp = _head;
    _head = _head->_next;
    delete temp;
    --_size;
}

void SLL::erase(size_t idx) {
    Node* prev = getNode(idx - 1);
    Node* temp = prev->_next;
    prev->_next = prev->_next->_next;
    delete temp;
    --_size;
}

void SLL::clear() {
    while(_size != 0) {
        popFront();
    }
}

ValueType& SLL::front() {
    return _head->_value;
}
ValueType& SLL::operator[](size_t idx) {
    Node* cur = getNode(idx);
    return cur->_value;

}

const ValueType& SLL::operator[](size_t idx) const {
    return operator[](idx);
}