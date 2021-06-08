#ifndef EXAMS_SORTEDLIST_H
#define EXAMS_SORTEDLIST_H

#include <iostream>

typedef int T;

template<class T>
class Node {
    T data;
    struct Node *next;
public:
    Node(T data = nullptr);

    Node(const T other);

    ~Node();

    Node &operator=(const T &other);

    T &NodeGetData(const Node &node);

    Node &NodeGetNext(const Node &node);

    void NodeSetNext(const Node &node);

    bool operator<(const Node node);

};


class SortedList {
    Node *head;
    int size;
public:


    SortedList(Node *head= nullptr, int size=0) : head(head), size(size) {}

    ~SortedList();

    SortedList(const SortedList &other);

    SortedList &operator=(const SortedList &other);

    void insert(Node node);

    void remove(const_iterator iterator);

    int length();

    //todo: filter
    //todo: apply
    const_iterator begin();

    const_iterator end();
};

SortedList:: class const_iterator {
private:
    Node *itr;

    const_iterator();

public:
    const_iterator(const const_iterator &other);

    ~const_iterator();

    const_iterator &operator=(const const_iterator &other);

    const_iterator &operator++();

    bool operator==(const const_iterator &other);

    Node &operator*(const const_iterator &other) const;

};

SortedList::~SortedList() {
    while (head != nullptr) {
        Node next = NodeGetNext(head);
        ~Node(head);
        size--;
        head = next;
    }
    delete[] SortedList;
}

//SortedList::SortedList(const SortedList &other) {
//    size(other.size);
//    for (typename SortedList::const_iterator it = begin();it != end(); ++it) {
//        Node node= new Node(Node::NodeGetData(other);
//        head=node;
//
//    }
//    }

#endif //EXAMS_SORTEDLIST_H
