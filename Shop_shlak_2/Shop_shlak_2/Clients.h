#pragma once
#include <string>

#include "Clients.h"

class Client {
 public:
  int id;            // уникальный идентификатор
  std::string race;  // раса: "человек", "эльф", "дварф", "орк"
  std::string role;  // роль: "воин", "маг", "плут", "клоун"
  Client* next;      // указатель на следующего клиента
  Client* prev;      // указатель на предыдущего клиента

  // Конструктор
  Client(int id_, std::string race_, std::string role_);
  Client() = default;
  ~Client();
};
