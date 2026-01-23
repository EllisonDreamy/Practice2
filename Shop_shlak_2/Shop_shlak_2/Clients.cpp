#include "Clients.h"

#include <string>

Client::Client(int id_, std::string race_, std::string role_) {
  id = id_;
  race = race_;
  role = role_;
};

Client::~Client() {};
