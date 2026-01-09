#include <iostream>
#include <string>
#include "Clients.h"
#include "Listik.h"







Listik::Listik (Client firstNodeData) {
    firstNode = new NodeList();
    firstNode->number;
    firstNode->data = firstNodeData;
    firstNode->next = NULL;
    currentNode = firstNode;
};

void Listik::addClient(Client newData) {
    NodeList* newNode = new NodeList();
    newNode->number = currentNode->number + 1;
    currentNode->next = newNode;
    newNode->data = newData;
    newNode->next = NULL;
    newNode->prev = currentNode;
    currentNode = newNode;
};

NodeList* Listik::getFirstClient() const { return firstNode; };

void Listik::deleteFirstClient() {
    NodeList* tmpNode = firstNode->next;
    tmpNode->prev = NULL;
    delete firstNode;
    firstNode = tmpNode;
};