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
        SortedList<int> list;
        list.insert(9);
        list.insert(2);
        list.insert(1);
        list.insert(5);
        list.insert(3);
 //       cout<<*list.end()<<endl;
        for (auto it = list.begin(); !(it == list.end()); ++it) {
            cout << *it << endl;
        }
    }
}

