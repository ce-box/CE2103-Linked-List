#include <iostream>
using namespace std;

#include "List.h"
#include "Collector.h"

void test_1();
void test_2();

int main() {

    test_1();
    test_2();

    return 0;
}

void test_1(){
    List* list = new List();
    Collector* collector = Collector::getCollector();

    cout << "------------------------"<<endl;
    cout << "    LINKED LIST TEST    "<<endl;
    cout << "------------------------"<<endl;

    // Items are added to the list
    list->add(1);
    list->add(4);
    list->add(8);
    list->add(2);

    // Printing the list
    cout << "------------------------"<<endl;
    cout<<"List : ";list->printList();
    cout << "------------------------"<<endl;

    // Removing a couple of items
    list->remove(8);
    list->remove(1);

    // Printing the new list
    cout << "------------------------"<<endl;
    cout<<"List : ";list->printList();
    cout << "------------------------"<<endl;

    // Printing the collector list
    cout<<"Collector:"; collector->printCollector();cout<<"\n";

    // Adding another item and showing the actual list
    list->add(12);
    cout << "------------------------"<<endl;
    cout<<"List : "; list->printList();
    cout << "------------------------"<<endl;

    // Printing the collector
    cout<<"Collector :"; collector->printCollector();cout<<"\n";

    // Adding another item and showing the actual list
    cout << "------------------------"<<endl;
    list->add(101);
    cout << "------------------------"<<endl;
    cout<<"List : ";list->printList();
    cout << "------------------------"<<endl;

    // For one last time, we print collector list
    cout<<"Collector :"; collector->printCollector();cout<<"\n";
}

void test_2(){

    List* list1 = new List();
    List* list2 = new List();
    Collector* collector = Collector::getCollector();

    cout << "------------------------"<<endl;
    cout << "    LINKED LIST TEST    "<<endl;
    cout << "    (Multiple Lists)    "<<endl;
    cout << "------------------------"<<endl;

    // Adding some elements to both Lists

    list1->add(11);
    list1->add(34);
    list1->add(1);

    list2->add(24);
    list2->add(99);
    list2->add(13);

    // Printing the lists
    cout << "------------------------"<<endl;
    cout<<"List 1 : ";list1->printList();
    cout<<"List 2 : ";list2->printList();
    cout << "------------------------"<<endl;

    // Removing elements

    list1->remove(34);
    list2->remove(13);

    // Print Collector

    cout << "------------------------"<<endl;
    cout<<"Collector: "; collector->printCollector();
    cout << "------------------------"<<endl;

    // Adding elements in reverse order from which they were removed

    list2->add(15);
    list1->add(8);

    // what happens if i try to remove an element that doesnt exist on the list?
    list1->remove(101);

    // Printing the lists
    cout << "------------------------"<<endl;
    cout<<"List 1 : ";list1->printList();
    cout<<"List 2 : ";list2->printList();
    cout << "------------------------"<<endl;

    // Print Collector

    cout << "------------------------"<<endl;
    cout<<"Collector: "; collector->printCollector();
    cout << "------------------------"<<endl;

    cout<<"\n\n";

}