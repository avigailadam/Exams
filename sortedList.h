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

    SortedList(Node *head = nullptr, int size = 0) : size(size) {}

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
    Node(T data= nullptr){
        Node* new_node =new Node;
        new_node->data=data;
        new_node->next= nullptr;
    }

    ~Node();

    Node &operator=(const Node& other){
        if(this==other){
            return *this
        }
        data=other.data;
        next=other.next;
    }

    T getData() const {
        return data;
    }

    Node *getNext() const {
        return next;
    }

    Node*& NodesetNext(const Node *new_next) {
        this->next = new_next;
    }

    bool operator<(const Node& other){
        if(this->data()<other.data()) {
            return true;
        }
        return false;
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

        T operator*() const{
            return current_node->data;
        }
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
