//
// Created by dom on 15/09/2026.
//

#ifndef ENGINEMAN_PARSER_H
#define ENGINEMAN_PARSER_H

#include <vector>
#include <string>

namespace tagvalue
{
  typedef struct pair
  {
    int tag;
    std::string value;
  } pair;

  std::vector<pair> parse(std::string);
}

#endif //ENGINEMAN_PARSER_H