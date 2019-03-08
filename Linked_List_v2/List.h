//
// Created by Erick Barrantes & Esteban Alvarado (2019).
// Instituto Tecnologico de Costa Rica
// Computer Engineering | Algorithms and data structures II
//

#ifndef LINKED_LIST_V2_LIST_H
#define LINKED_LIST_V2_LIST_H

// Libraries
#include <ostream>
#include <iostream>

// Imports
#include "Node.h"

///@brief Implementation of a simple linked list formed by Node objects.
///@note ** This list has a memory manager called collector.
class List{

public:

    /*----------------------------------
     *         +---------------+
     *         |   ATTRIBUTES  |
     *         +---------------+
     -----------------------------------*/

    Node* p_Head;

    List(){
        p_Head = nullptr;
    }

    /*----------------------------------
     *       +------------------+
     *       |  PUBLIC METHODS  |
     *       +------------------+
     -----------------------------------*/

    /// @brief Method responsible for adding nodes to the list.
    /// @param data int value that will be stored in this node.

    void add(int data){
        Node* newNode = new Node(data);
        if(!p_Head){
            this->p_Head = newNode;
        } else {
            newNode->setNextNode(p_Head);
            this->p_Head = newNode;
        }

        std::cout<< "-> Adding: { "<< data << " | "<<newNode<<" }"<<std::endl;
    }

    /// @brief Method responsible for removing nodes from the list.
    /// @param data item that will be removed from list.

    void remove(int data){
        Node *auxNode = p_Head, *prev = nullptr;
        while(auxNode->data != data){
            prev = auxNode;
            auxNode = auxNode->getNextNode();
        }

        removeSwapping(prev, auxNode);
    }

    ///@brief Method responsible for displaying the list.

    void printList(){
        for(Node *node = p_Head;node!= nullptr;node=node->getNextNode()) std::cout <<"[ "<<node->getData()<<" | "<<node<<" ] ->";
        std::cout <<" NULL "<<std::endl;
    }

private:

    /*----------------------------------
     *       +------------------+
     *       | PRIVATE METHODS  |
     *       +------------------+
     -----------------------------------*/

    /// @brief It is responsible for analyzing the possible cases of elimination of a node:
    /// If it is a head or if it is in the middle of other nodes.
    /// @param prev Previous node to which you want to delete.
    /// @param aux  Node which you want to remove. 

    void removeSwapping(Node *prev, Node *aux){
        if(aux){

            if(!prev){
                p_Head = aux->p_Next;
            } else {
                prev->p_Next = aux->p_Next;
            }
        }

        std::cout << "-> Removing: {"<< aux->getData()<<" | "<<aux<<" }"<<std::endl;
        delete(aux);

    }

};

#endif //LINKED_LIST_V2_LIST_H
