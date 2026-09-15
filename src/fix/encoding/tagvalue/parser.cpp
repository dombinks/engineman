//
// Created by dom on 15/09/2026.
//

#include "parser.h"

std::vector<tagvalue::pair> tagvalue::parse(std::string data)
{
  std::vector<tagvalue::pair> pairs;

  for (std::string::iterator it = data.begin(); it != data.end();)
  {
    std::string tag;

    while (*it != '=')
    {
     tag.push_back(*it++);
    }
    ++it;

    std::string value;

    while (*it != '\01')
    {
      value.push_back(*it++);
    }
    ++it;

    pairs.push_back({std::stoi(tag), value});
  }

  return pairs;
}