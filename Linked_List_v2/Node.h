//
// Created by Erick Barrantes & Esteban Alvarado (2019).
// Instituto Tecnologico de Costa Rica
// Computer Engineering | Algorithms and data structures II
//

#ifndef LINKED_LIST_V2_NODE_H
#define LINKED_LIST_V2_NODE_H

// Libraries
#include <ostream>
#include <iostream>

// Imports
#include "Collector.h"

///@brief Structure that stores a data type int and a pointer to the next node.
class Node {

public:

    /*----------------------------------
     *         +---------------+
     *         |   ATTRIBUTES  |
     *         +---------------+
     -----------------------------------*/
    int data;
    Node* p_Next;


    Node(int data){
        this->data = data;
    }


    /*----------------------------------
     *      +-------------------+
     *      |   PUBLIC METHODS  |
     *      +-------------------+
     -----------------------------------*/

    /// @brief The new operator is overloaded to access the collector in search of a recycled
    /// memory space, if it is not available a new space is reserved in the memory.
    /// @param size Size that the compiler assigns to the Node class.
    /// @return Memory address where the Node is stored.

    void* operator new(size_t size){

        void* p_Node;
        void* reference;
        Collector* collector = Collector::getCollector();
        reference = collector->getMemoryReference();

        if(reference){
            p_Node = reference;
        } else{
            p_Node = malloc(size);
        }

        return p_Node;
    }

    /// @brief It is responsible for sending the memory nodes to the Collector to be recycled.
    /// @param memory Memory space that will be recycled.

    void operator delete(void* memory){

        Collector* collector = Collector::getCollector();
        collector->addMemoryReference(memory);
    }

    /// @brief Shows the Node data on console.

    void printNode(){
        std::cout<< "Node: [ Data: "<<data<<"]"<<std::endl;
    }

    /*----------------------------------
     *      +-------------------+
     *      |  GETTER & SETTER  |
     *      +-------------------+
     -----------------------------------*/

    /// @brief Returns the Node data.
    /// @return int value stored in this node.

    int getData(){
        return this->data;
    }

    /// @brief Allows to modify the data of the node.
    /// @param data new int value that will be stored in this node.

    void setData(int data){
        this->data = data;
    }

    /// @brief Returns the next node.
    /// @return Next node.

    Node* getNextNode(){
        return this->p_Next;
    }

    /// @brief Allows to set the next Node.
    /// @param nextNode New node that will be added.

    void setNextNode(Node* nextNode){
        this->p_Next = nextNode;
    }

};

    /*----------------------------------
     *      +-------------------+
     *      |     COLLECTOR     |
     *      +-------------------+
     -----------------------------------*/

void Collector::addMemoryReference(void* memory) {

    Node* newMemory = (Node*) memory;
    newMemory->setNextNode(nullptr); //It's very important to clean the p_Next to avoid errors
    if(!p_Head){
        this->p_Head = newMemory;
    } else {
        newMemory->setNextNode(this->p_Head);
        this->p_Head = newMemory;
    }
}

Node* Collector::getMemoryReference() {

    Node* ansNode = nullptr;

    if(p_Head){
        ansNode = p_Head;
        p_Head = p_Head->getNextNode();
        ansNode->setNextNode(nullptr);
    }

    return ansNode;
}

void Collector::printCollector() {

    for (Node* auxNode = p_Head;auxNode!= nullptr;auxNode=auxNode->getNextNode()) {
        std::cout<< "[ "<<auxNode<<" ] ->";
    }
    std::cout<< " NULL" << std::endl;
}

#endif //LINKED_LIST_V2_NODE_H
