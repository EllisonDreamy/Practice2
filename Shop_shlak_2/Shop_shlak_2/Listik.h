#pragma once
#include "Clients.h"

void initTerminal();

class Listik {
 private:
  Client firstNode;
  Client currentNode;

 public:
  Listik(Client firstNodeData);

  void addClient(Client newData);

  Client getFirstClient() const;

  int size();

  void deleteFirstClient();
};
