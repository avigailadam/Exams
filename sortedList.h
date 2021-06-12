#ifndef EXAMS_SORTEDLIST_H
#define EXAMS_SORTEDLIST_H

#include <iostream>
#include <cassert>

namespace mtm {
    template<class T>
    class SortedList {
        class Node;

        Node *head;
        int size;


    public:

        class const_iterator;

        SortedList() : size(0), head(nullptr) {}

        ~SortedList();

        SortedList(const SortedList<T> &other);

        SortedList<T> &operator=(const SortedList<T> &other);

        void insert(T new_element);

        void remove(const_iterator iterator);

        int length() const {
            return size;
        }

        template<class Condition>
        SortedList<T> filter(Condition c);

        template<class Function>
        SortedList<T> apply(Function f);

        const_iterator begin() {
            const_iterator first(head);
            return first;
        }

        const_iterator end() {
            const_iterator result(nullptr);
            return result;
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
                    current_node = current_node->next;
                }
                return *this;
            }

            const_iterator operator++(int) //iterator++
            {
                if (current_node == nullptr) {
                    throw std::out_of_range("End of list");
                }
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

            Node() = default;

        public:
            explicit Node(T element, Node *node_next = nullptr) : data(element) {
                next = node_next;
            };

            Node(Node &other) = default;

            ~Node() = default;
        };
    };

    template<class T>
    SortedList<T>::~SortedList() {
        if (head == nullptr) {
            return;
        }
        Node *current = head;
        while (current != nullptr) {
            Node *temp = current->next;
            delete current;
            current = temp;
        }
    }

    template<class T>
    void SortedList<T>::remove(const_iterator iterator) {
        if (iterator == begin()) {
            Node *temp = head->next;
            delete head;
            head = temp;
            size--;
            return;
        }
        Node *current = this->head;
        for (SortedList::const_iterator i = ++begin(); i != end(); ++i) {
            if (i != iterator) {
                continue;
            }
            Node *before = current;
            current = current->next;
            before->next = current->next;
            delete current;
            size--;
            return;
        }
    }

    template<class T>
    SortedList<T>::SortedList(const SortedList &other) : size(other.size) {
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

    template<class T>
    SortedList<T> &SortedList<T>::operator=(const SortedList<T> &other) {
        if (this == &other) {
            return *this;
        }

        Node *i = head;

        while (i != nullptr) {
            Node *temp = i->next;
            delete i;
            i = temp;
        }

        delete end().current_node;
        size = other.size;
        head = new Node(*other.head);
        Node *current = head;
        Node *current_other = other.head;
        while (current_other->next != nullptr) {
            current->next = new Node(*current_other->next);
            current_other = current_other->next;
            current = current->next;
        }
        return *this;
    }

    template<class T>
    void SortedList<T>::insert(T new_element) {
        Node *new_node = new Node(new_element);
        if (head == nullptr) {
            head = new_node;
            size++;
            return;
        }
        //assert(begin()!= nullptr);
        Node *before = begin().current_node;
        for (const_iterator i = begin(); i != end(); ++i) {
            if (i.current_node->data < new_element) {
                before = i.current_node;
                continue;
            }

            Node *current = i.current_node;
            new_node->next = current;
            if (current == head) {
                head = new_node;
            } else {
                before->next = new_node;
            }
            size++;
            return;
        }
        before->next = new_node;
        size++;
    }

    template<class T>
    template<class Condition>
    SortedList<T> SortedList<T>::filter(Condition c) {
        SortedList filtered_list;
        for (const_iterator i = begin(); i != end(); ++i) {
            if (!c(i.current_node->data)) {
                continue;
            }
            filtered_list.insert(i.current_node->data);
        }
        return filtered_list;
    }

    template<class T>
    template<class Function>
    SortedList<T> SortedList<T>::apply(Function f) {
        SortedList<T> transformed_list;
        for (const_iterator i = begin(); i != end(); ++i) {
            transformed_list.insert(f(i.current_node->data));
        }
        return transformed_list;
    }

}
#endif //EXAMS_SORTEDLIST_H

