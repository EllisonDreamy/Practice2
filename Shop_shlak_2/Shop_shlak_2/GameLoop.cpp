#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <utility>
#include <vector>

#include "Clients.h"
#include "Listik.h"

// Пример соответствий раса+роль -> подходящий товар
std::map<std::pair<std::string, std::string>, std::vector<std::string>>
    correctItems = {
        {{"человек", "воин"}, {"стальной меч", "латный доспех", "щит"}},
        {{"человек", "маг"},
         {"волшебная палочка", "свиток огня", "простой амулет"}},
        {{"человек", "плут"}, {"стальной кинжал", "арболет", "тёмная мантия"}},
        {{"человек", "клоун"}, {"колотушка", "красный нос", "парик"}},
        {{"эльф", "воин"}, {"древестный меч", "элегантные стрелы", "лук"}},
        {{"эльф", "маг"},
         {"магический посох", "свиток леса", "эльфийский амулет"}},
        {{"эльф", "плут"},
         {"лунный кинжалы", "отравленный кинжал", "лунная мантия"}},
        {{"эльф", "клоун"},
         {"элегантный грим", "булавы джонглёра", "цветочки"}},
        {{"дварф", "воин"},
         {"боевой топор", "молот гномов", "руническая броня"}},
        {{"дварф", "маг"},
         {"посох с рубином", "посох с аметистом", "посох с алмазом"}},
        {{"дварф", "плут"},
         {"лёгкая кирка", "трос", "косплей асасина маленького размера"}},
        {{"дварф", "клоун"},
         {"скрипящие ботинки", "цветные шары", "светящиеся колотушка"}},
        {{"орк", "воин"},
         {"двухручный меч", "шкура бронемедведя", "шипастый щит"}},
        {{"орк", "маг"},
         {"каменный посох", "череп предков", "амулет из костей"}},
        {{"орк", "плут"},
         {"зазубренные кинжалы", "отравленные стрелы", "шкура вепря"}},
        {{"орк", "клоун"},
         {"тяжёлая колотушка", "огромный парик", "цветной костюм"}},
        // ... и другие комбинации
};
std::vector<std::string> allItems = {"стальной меч",
                                     "латный доспех",
                                     "щит",
                                     "волшебная палочка",
                                     "свиток огня",
                                     "простой амулет",
                                     "стальной кинжал",
                                     "арболет",
                                     "тёмная мантия",
                                     "колотушка",
                                     "красный нос",
                                     "парик",
                                     "древестный меч",
                                     "элегантные стрелы",
                                     "лук",
                                     "магический посох",
                                     "свиток леса",
                                     "эльфийский амулет",
                                     "лунный кинжалы",
                                     "отравленный кинжал",
                                     "лунная мантия",
                                     "элегантный грим",
                                     "булавы джонглёра",
                                     "цветочки",
                                     "боевой топор",
                                     "молот гномов",
                                     "руническая броня",
                                     "посох с рубином",
                                     "посох с аметистом",
                                     "посох с алмазом",
                                     "лёгкая кирка",
                                     "трос",
                                     "косплей асасина маленького размера",
                                     "скрипящие ботинки",
                                     "цветные шары",
                                     "светящиеся колотушка",
                                     "двухручный меч",
                                     "шкура бронемедведя",
                                     "шипастый щит",
                                     "каменный посох",
                                     "череп предков",
                                     "амулет из костей",
                                     "зазубренные кинжалы",
                                     "отравленные стрелы",
                                     "шкура вепря",
                                     "тяжёлая колотушка",
                                     "огромный парик",
                                     "цветной костюм"};
std::vector<std::string> races = {"человек", "эльф", "дварф", "орк"};
std::vector<std::string> roles = {"воин", "маг", "плут", "клоун"};

std::vector<std::string> rand_vect(std::vector<std::string> base_vector) {
  std::vector<std::string> temp_vector;
  int reps = base_vector.size();

  for (int i = 0; i < reps; i++) {
    int random_number = rand() % base_vector.size();
    temp_vector.push_back(base_vector[random_number]);
    base_vector.erase(base_vector.begin() + random_number);
  }

  return temp_vector;
}

Client getRndClient(int id) {
  std::string race = races[rand() % races.size()];
  std::string role = roles[rand() % roles.size()];
  return Client(id, race, role);
}

Listik gamePrep(int leng) {
  Client nclient = getRndClient(0);
  allItems = rand_vect(allItems);
  Listik clientLst(nclient);
  for (int i = 1; i < leng; i++) {
    Client nclient = getRndClient(i);
    clientLst.addClient(nclient);
  };
  return clientLst;
};

int gameLoop(Listik gameData, int optionsAmount, int scoreAddition = 10,
             int scoreSubtraction = 5) {
  int score = 0;
  int roundsAmount = gameData.size();
  for (int cround = 0; cround < roundsAmount; cround++) {
    // generate answers
    std::vector<std::string> rightAns = correctItems[{
        gameData.getFirstClient().race, gameData.getFirstClient().role}];
    std::vector<std::string> ansLst = {};
    for (int i = 0; i < (optionsAmount - 1); i++) {
      ansLst.push_back(allItems.back());
      allItems.pop_back();
    };
    ansLst.push_back(rightAns[rand() % rightAns.size()]);
    ansLst = rand_vect(ansLst);

    // visible part here
    std::cout << "\n\n\n\n"
              << "В твоё заведение зашёл " << gameData.getFirstClient().race
              << " " << gameData.getFirstClient().role << std::endl
              << "Он просит тебя подобрать ему подходящее снаряжение."
              << std::endl;
    for (int option = 0; option < ansLst.size(); option++) {
      std::cout << option << ") " << ansLst[option] << std::endl;
    };
    std::cout << "впиши сюда номер снаряжения: ";
    int inAns;
    while ((!(std::cin >> inAns)) || (inAns >= ansLst.size())) {
      std::cout
          << "Неправильное значение! Нужно число входящее в данный диапозон."
          << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Попробуй снова: ";
    }

    // answer check
    std::cout << "---------------" << std::endl;
    if (std::find(rightAns.begin(), rightAns.end(), ansLst[inAns]) !=
        rightAns.end()) {
      std::cout << gameData.getFirstClient().race << " оценил твой выбор <3"
                << std::endl;
      score += scoreAddition;
    } else {
      std::cout << gameData.getFirstClient().race
                << "у не понравилось это снаряжение :(" << std::endl;
      score -= scoreSubtraction;
      if (score < 0) score = 0;
    }
    gameData.deleteFirstClient();
  }
  std::cout << "Твой счёт: " << score << std::endl;
  return 0;
};
