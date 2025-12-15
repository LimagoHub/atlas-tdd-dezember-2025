#pragma once

#include "gmock/gmock.h"
#include "../../source/persistence/person.h"
#include "../../source/persistence/personen_repository.h"



class Mockpersonen_repository : public personen_repository {
 public:
  MOCK_METHOD(void, save_or_update, (const person& person), (const, override));
  MOCK_METHOD(std::optional<person>, find_by_id, (std::string id), (const, override));
  MOCK_METHOD(std::vector<person>, find_all, (), (const, override));
  MOCK_METHOD(bool, delete_by_id, (std::string id), (const, override));
};
