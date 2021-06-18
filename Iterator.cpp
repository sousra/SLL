#include "SLL.h"

ValueType& SLL::Iterator::operator*() {
    return _ptr->_value;
}

SLL::Iterator& SLL::Iterator::operator++() {
    _ptr = _ptr->_next;
    return *this;
}

SLL::Iterator SLL::Iterator::operator++(int) {
    SLL::Iterator it(_ptr);
    _ptr = _ptr->_next;
    return it;
}

SLL::Iterator& SLL::Iterator::operator+=(size_t value) {
    for (size_t i = 0; i < value; ++i) {
        _ptr = _ptr->_next;
    }
    return *this;
}

bool SLL::Iterator::operator!=(const Iterator& other) {
    return _ptr != other._ptr;
}

bool SLL::Iterator::operator==(const Iterator& other) {
    return _ptr == other._ptr;
}

SLL::Iterator SLL::begin() {
    return SLL::Iterator(_head);
}

SLL::Iterator SLL::end() {
    return SLL::Iterator(nullptr);
}