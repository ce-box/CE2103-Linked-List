//
// Created by Erick Barrantes & Esteban Alvarado (2019).
// Instituto Tecnologico de Costa Rica
// Computer Engineering | Algorithms and data structures II
//

#ifndef LINKED_LIST_V2_COLLECTOR_H
#define LINKED_LIST_V2_COLLECTOR_H

// Libraries
#include <ostream>
#include <iostream>

class Node; // Forward Declaration

/// @brief Class responsible for recycling the memory released in List.

class Collector{

    /*----------------------------------
     *         +---------------+
     *         |   ATTRIBUTES  |
     *         +---------------+
     -----------------------------------*/

    static Collector* collector;
    Node* p_Head;

private:

    // Private constructor

    Collector(){
        this->p_Head = nullptr;
    }

public:

    /*----------------------------------
     *       +------------------+
     *       |  PUBLIC METHODS  |
     *       +------------------+
     -----------------------------------*/

    // These methods will be implemented as members by the class Node.h

    /// @brief It is responsible for creating a single instance of Collector.
    /// @brief ** Implements the Singleton design pattern.
    ///
    /// @return An instance of Collector.

    static Collector* getCollector();

    /// @brief It is responsible for adding the pointer to the list to be recycled.
    /// @param [in] memory Memory address to be recycled

    void addMemoryReference(void* memory);

    /// @brief Returns a recycled memory address.
    /// @brief If there is none, it returns null.
    /// @return A memory address available

    Node* getMemoryReference();

    /// @brief Method responsible for displaying the recycled memory locations stored in the collector list.

    void printCollector();
};


    /*----------------------------------
     *       +------------------+
     *       |     SINGLETON    |
     *       +------------------+
     -----------------------------------*/

Collector* Collector::collector = nullptr;
Collector* Collector::getCollector() {
    if(!collector) collector = new Collector();
    return collector;
}

#endif //LINKED_LIST_V2_COLLECTOR_H
