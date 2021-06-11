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

    SortedList() : size(0),head(nullptr) {}

    ~SortedList();

    SortedList(const SortedList &other);

    SortedList &operator=(const SortedList &other);

    void insert(Node node);

    void remove(const_iterator iterator);

    static int length();

    //todo: filter
    //todo: apply
    const_iterator begin(){
        const_iterator first(head);
        return first;
    }

    const_iterator end(){
        const_iterator item= begin();
        for(int i=0;i<size;i++){
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
        Node* createNode(T data) {
            Node *new_node = new Node;
            new_node->data = data;
            new_node->next = nullptr;
            return new_node;
        }

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
//todo dtor is not done!
//SortedList::~SortedList() {
//        // there is at least one item
//        if(head != nullptr)
//        {
//            // release memory starting from the second item
//            Node *current, *soon;
//            current = this->head->next;
//            while(current != nullptr)  // if there are at least two items
//            {
//                /* When there is no more items after current,
//                 * delete current and leave.
//                 * Otherwise, free up current and move on to
//                 * the next item.
//                 */
//                if(current->next != nullptr)
//                {
//                    soon = current->next;
//                    delete current;
//                    current = soon;
//                }
//                else
//                {
//                    delete current;
//                    break;
//                }
//
//            }
//        }

//        delete this->head;
//        delete this->();
//    }
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
