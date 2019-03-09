#include <iostream>
using namespace std;

#include "List.h"
#include "Collector.h"

void test_1();

int main() {

    test_1();

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