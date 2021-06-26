#include "SLL.h"
#include <iostream>
#include <exception>

SLL::Node* SLL::getNode(size_t idx) {
    if (idx < 0 || idx >= _size) {
        throw std::out_of_range("Invalid index");
    }
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

SLL::SLL(SLL&& other) noexcept {
    _head = other._head;
    _size = other._size;
    other._head = nullptr;
    other._size = 0;
}

SLL& SLL::operator=(const SLL& other) {
    clear();
    Node* curNode = other._head;
    while(curNode) {
        insert(_size, curNode->_value);
        curNode = curNode->_next;
    }
    return *this;
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
    else if (idx > 0 && idx <= _size) {
        Node* cur = new Node(value);
        Node* prev = getNode(idx - 1);
        cur->_next = prev->_next;
        prev->_next = cur;
        ++_size;
    }
    else {
        throw std::out_of_range("Invalid index");
    }
}

void SLL::popFront() {
    if (_head) {
        Node* temp = _head;
        _head = _head->_next;
        delete temp;
        --_size;
    }
    else {
        throw std::logic_error("Empty linked list");
    }
}

void SLL::erase(size_t idx) {
    if (idx == 0) {
        popFront();
    }
    else if (0 < idx && idx < _size) {
        Node* prev = getNode(idx - 1);
        Node* temp = prev->_next;
        prev->_next = prev->_next->_next;
        delete temp;
        --_size;
    }
    else {
        throw std::out_of_range("Invalid index");
    }
}

void SLL::clear() {
    while(_size != 0) {
        popFront();
    }
}

ValueType& SLL::front() const {
    if (!_head) {
        throw std::logic_error("Empty linked list");
    }
    return _head->_value;
}

ValueType& SLL::operator[](size_t idx) {
    Node* cur = getNode(idx);
    return cur->_value;
}

const ValueType& SLL::operator[](size_t idx) const {
    return operator[](idx);
}