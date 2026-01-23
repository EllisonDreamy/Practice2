#include "Listik.h"

#include <iostream>
#include <string>

#include "Clients.h"

#ifdef _WIN32
#include <Windows.h>
#endif

void initTerminal() {
#ifdef _WIN32
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
#endif
};

Listik::Listik(Client firstNodeData) {
  firstNode = firstNodeData;
  firstNode.id = 0;
  firstNode.next = NULL;
  currentNode = firstNode;
};

void Listik::addClient(Client newData) {
  Client newNode = newData;
  currentNode.next = &newNode;
  newNode.next = NULL;
  newNode.prev = &currentNode;
  currentNode = newNode;
};

Client Listik::getFirstClient() const { return firstNode; };

int Listik::size() { return currentNode.id; };

void Listik::deleteFirstClient() {
  Client tmpNode = *firstNode.next;
  tmpNode.prev = NULL;
  tmpNode.id -= 1;
  // delete firstNode;

  firstNode = tmpNode;
  while (tmpNode.next != NULL) {
    tmpNode = *tmpNode.next;
    tmpNode.id -= 1;
  };
};
