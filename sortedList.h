#ifndef EXAMS_SORTEDLIST_H
#define EXAMS_SORTEDLIST_H

#include <iostream>

typedef int T;

class SortedList {
    //Node *head;
    int size;
    class Node;

public:

    class const_iterator;

    SortedList(Node *head = nullptr, int size = 0) :  size(size) {}

    ~SortedList();

    SortedList(const SortedList &other);

    SortedList &operator=(const SortedList &other);

    void insert(Node node);

    void remove(const_iterator iterator);

    static int length();

    //todo: filter
    //todo: apply
    const_iterator begin();

    const_iterator end();
};


class SortedList::Node {
    T data;
    struct Node *next;
public:
    Node(T data, Node *next = nullptr);

    Node(const T other);

    ~Node();

    Node &operator=(const T &other);

    T &NodeGetData(const Node &node);

    Node &NodeGetNext(const Node &node);

    void NodeSetNext(const Node &node);

    bool operator<(const Node node);

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
            if (current_node){
                current_node=current_node->next;
            }
        }

        const_iterator &operator++(int) //iterator++
        {const_iterator iterator = *this;
            ++(*this);
            return iterator;}

        const_iterator(const const_iterator &other) = default;

        ~const_iterator() = default;

        bool operator==(const const_iterator &other) const;

        bool operator!=(const const_iterator &other) const;

        const Node &operator*() const;

    };
};


//SortedList::~SortedList() {
//    while (head != nullptr) {
//        Node next = NodeGetNext(head);
//        ~Node(head);
//        size--;
//        head = next;
//    }
//    delete[] SortedList;
//}

//SortedList::SortedList(const SortedList &other) {
//    size(other.size);
//    for (typename SortedList::const_iterator it = begin();it != end(); ++it) {
//        Node node= new Node(Node::NodeGetData(other);
//        head=node;
//
//    }
//    }

#endif //EXAMS_SORTEDLIST_H
