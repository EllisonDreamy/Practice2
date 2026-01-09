#pragma once
#include "Clients.h"

struct NodeList {
    Client data;
    NodeList* next;
    NodeList* prev;
    int number;

    NodeList();
};

class Listik {
private:
    NodeList* firstNode;
    NodeList* currentNode;
public:
    Listik(Client firstNodeData);

    void addClient(Client newData);

    NodeList* getFirstClient() const;

    void deleteFirstClient();
};