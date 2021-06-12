//
// Created by hagai on 6/6/2021.
//

#include <iostream>
#include "sortedList.h"
#include "examDetails.h"

using std::cout;
using std::endl;
using std::string;
using namespace mtm;

int main() {
    {
        SortedList<string> list;
        list.insert("C");
        list.insert("B");
        list.insert("A");
        for (auto it = list.begin(); !(it == list.end()); ++it) {
            cout << *it << endl;
        }
    }
}

