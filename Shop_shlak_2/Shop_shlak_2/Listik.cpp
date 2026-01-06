#include <iostream>
#include <string>
#include "Clients.h"



struct NodeList {
    Client data;
    NodeList* next;
    int number;
};


Listik::Listik {
    NodeList* firstNode;
    NodeList* currentNode;

    Listik(Client firstNodeData) {
        firstNode = new NodeList();
        firstNode->number;
        firstNode->data = firstNodeData;
        firstNode->next = NULL;
        currentNode = firstNode;
    }

    void addClient(Client newData) {
        NodeList* newNode = new NodeList();
        newNode->number = currentNode->number + 1;
        currentNode->next = newNode;
        newNode->data = newData;
        newNode->next = NULL;
        currentNode = newNode;
    };

    NodeList* getFirstNode() const { return firstNode; };

    void deleteFirstNode() {
        NodeList* tmpNode = firstNode->next;
        delete firstNode;
        firstNode = tmpNode;
    };

    //void deleteId(int id) {
    //    NodeList* tmpNode = firstNode;
    //    while (id) {
    //        NodeList* nextNode = tmpNode->next;
    //        if (delNode == nextNode) {
    //            tmpNode->next = nextNode->next;
    //            delete delNode;
    //            return;
    //        }
    //        tmpNode = tmpNode->next;
    //    }
    //    /* void goNextNode() {
    //         currentNode = currentNode->next;
    //     };*/

        //void printAll() const {
        //    NodeList* tmpNode = firstNode;
        //    while (tmpNode != NULL) { //currentNode
        //        std::cout << tmpNode->number << " " << tmpNode->data << " "
        //            << " " << &tmpNode->next
        //            << std::endl;
        //        tmpNode = tmpNode->next;
        //    }
        //};

        ~List() {}
    };