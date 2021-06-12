#ifndef EXAMS_SORTEDLIST_H
#define EXAMS_SORTEDLIST_H

#include <iostream>

typedef int T;

class SortedList {
    class Node;

    Node *head;
    int size;


public:

    class const_iterator;

    SortedList() : size(0), head(nullptr) {}

    ~SortedList();

    SortedList(const SortedList &other);

    SortedList &operator=(const SortedList &other);

    void insert(Node node);

    void remove(const_iterator iterator);

    int length() const {
        return size;
    }

    //todo: filter
    //todo: apply
    const_iterator begin() {
        const_iterator first(head);
        return first;
    }

    const_iterator end() {

        const_iterator item = begin();
        if (item.current_node == nullptr) {
            return item;
        }
        while (item.current_node->next != nullptr) {
            item++;
        }
        return item;
    }

    class const_iterator {
    private:
        Node *current_node;

        explicit const_iterator(Node *node) :
                current_node(node) {}

        friend class SortedList;

    public:
        const_iterator &operator=(Node *node) {
            current_node = node;
            return *this;
        }

        const_iterator &operator++() //++iterator
        {
            if (current_node) {
                current_node = current_node->next;//todo:and what if not?
            }
            return *this;
        }

        const_iterator operator++(int) //iterator++
        {
//            if(current_node== nullptr){
//                throw std::out_of_range();
//            }
            const_iterator iterator = *this;
            ++(*this);

            return iterator;
        }

        const_iterator(const const_iterator &other) = default;

        ~const_iterator() = default;

        bool operator!=(const const_iterator &other) const {
            return current_node != other.current_node;
        }

        bool operator==(const const_iterator &other) const {
            return !(*this != other);
        }

        T operator*() const {
            return current_node->data;
        }
    };

private:
    class Node {
        T data;
        struct Node *next;

        friend class SortedList;
    };

//            T getData() const {
//                return data;
//            }
//
//            Node *&NodesetNext(const Node *new_next) {
//                this->next = new_next;
//            }
//
//            bool operator<(const Node &other) {
//                if (this->data() < other.data()) {
//                    return true;
//                }
//                return false;
//            }
//
//        };
};

SortedList::~SortedList() {
    // there is at least one item
    if (head != nullptr) {
        // release memory starting from the second item
        Node *soon = nullptr;
        Node *current = this->head->next;
        while (current != nullptr)  // if there are at least two items
        {
            if (current->next != nullptr) {
                soon = current->next;
                delete current;
                current = soon;
            } else {
                delete current;
                break;
            }
        }
    }
    delete this->head;
}

void SortedList::remove(const_iterator iterator) {
    if (iterator == begin()) {
        Node *temp = head->next;
        delete head;
        head = temp;
        size--;
        return;
    }
    Node *current = this->head;
    Node *after = nullptr;
    Node *before = this->head;
    for (SortedList::const_iterator i = ++begin(); i != end(); ++i) {
        if (i != iterator) {
            continue;
        }
        before = current;
        current = current->next;
        before->next = current->next;
        delete current;
        size--;
        return;
    }
}

SortedList::SortedList(const SortedList &other) : size(other.size) {
    if (other.head == nullptr) {
        head = nullptr;
        return;
    }
    head = new Node(*other.head);
    Node *current = head;
    Node *current_other = other.head;
    while (current_other->next != nullptr) {
        current->next = new Node(*current_other->next);
        current_other = current_other->next;
        current = current->next;
    }
}

SortedList &SortedList::operator=(const SortedList &other) {
    if (this == &other) {
        return *this;
    }

    size = other.size;

}

#endif //EXAMS_SORTEDLIST_H
