#include <iosfwd>
#include <algorithm>
#include <gtest/gtest.h>

#define protected public
#define private public
#include "sortedList.h"
#undef private
#undef protected

using std::cout;
using std::endl;
using std::ostringstream;
using std::string;
using mtm::SortedList;

string getLen(const string& str) {
    return std::to_string(str.length());
}

template <typename T>
void printList(const SortedList<T>& list, ostringstream& out) {
    for (auto it = list.begin(); !(it == list.end()); ++it) {
        out << *it << endl;
    }
    out << endl;
}

TEST(SortedList, ExampleSnippet1) {
    ostringstream out{};
    SortedList<string> lst1 = SortedList<string>();
    lst1.insert("Charlie");
    lst1.insert("Bob");
    lst1.insert("Alice");
    lst1.insert("Donald");
    printList(lst1, out);

    SortedList<string> lst2 = lst1;
    lst2 = lst2.apply(getLen);
    printList(lst2, out);

    SortedList<string>::const_iterator it = lst2.begin();
    out << *it << endl << endl;
    ++it;
    lst2.remove(it);
    printList(lst2, out);

    const char * const expected =
            "Alice\n"
            "Bob\n"
            "Charlie\n"
            "Donald\n"
            "\n"
            "3\n"
            "5\n"
            "6\n"
            "7\n"
            "\n"
            "3\n"
            "\n"
            "3\n"
            "6\n"
            "7\n"
            "\n";
    EXPECT_STREQ(expected, out.str().c_str());
}

TEST(SortedList, VerifyInternalOrder) {
    SortedList<int> list;
    int const repetitions = 30;
    std::srand(std::time(nullptr));
    for (int i = 0; i < repetitions; ++i) {
        list.insert(std::rand() % 100);
    }
    EXPECT_TRUE(std::is_sorted(std::begin(list), std::end(list)));
}

TEST(SortedList, TestCopyConstructor) {
    SortedList<int> list;
    list.insert(10);
    list.insert(5);
    list.insert(0);
    SortedList<int> list2{list};
    EXPECT_TRUE(std::is_sorted(std::begin(list), std::end(list)));
}

TEST(SortedList, TestAssignment) {
    SortedList<int> list;
    list.insert(10);
    list.insert(5);
    list.insert(0);
    SortedList<int> list2;
    list2 = list;
    EXPECT_TRUE(std::is_sorted(std::begin(list), std::end(list)));
    EXPECT_TRUE(std::is_sorted(std::begin(list2), std::end(list2)));
}

TEST(SortedList, TestRemove) {
    SortedList<int> list;
    list.insert(1);
    list.insert(2);
    list.insert(-2);
    list.remove(++list.begin());
    EXPECT_EQ(2, list.length());
    auto iterator = list.begin();
    EXPECT_EQ(-2, *iterator);
    ++iterator;
    EXPECT_EQ(2, *iterator);
    ++iterator;
    EXPECT_EQ(list.end(), iterator);
}
