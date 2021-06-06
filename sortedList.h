#ifndef EXAMS_SORTEDLIST_H
#define EXAMS_SORTEDLIST_H
typedef int T;

class Node {
    T element;
    T *next;
};


class SortedList {
    Node head;
    int size;
public:
    class const_iterator {
        const_iterator() = delete;

        const_iterator(const const_iterator &other);

        ~const_iterator();

        const_iterator &operator=(const const_iterator &other);

        const_iterator &operator++();

        bool operator==(const const_iterator &other);

        Node &operator*(const const_iterator &other) const;


    };

    SortedList(Node node = NULL);

    ~SortedList();

    SortedList(const SortedList &other);

    SortedList &operator=(const SortedList &other);

    void insert(T element);

    void remove(const_iterator iterator);

    int length();

    //todo: filter
    //todo: apply
    const_iterator begin();

    const_iterator end();
};


#endif //EXAMS_SORTEDLIST_H
