//
// Created by dom on 15/09/2026.
//

#ifndef ENGINEMAN_PARSER_H
#define ENGINEMAN_PARSER_H

#include <vector>
#include <string>

namespace tagvalue
{
  typedef struct field
  {
    int tag;
    std::string value;
  } field;

  std::vector<field> parse(std::string);
}

#endif //ENGINEMAN_PARSER_H