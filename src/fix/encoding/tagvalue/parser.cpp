//
// Created by dom on 15/09/2026.
//

#include "parser.h"

#include <iostream>

int parse_tag(std::string::iterator& it, const std::string::iterator& end)
{
  std::string tag;
  int tag_num = 0;

  if (*it >= '1' && *it <= '9')
  {
    while (it != end && *it >= '0' && *it <= '9')
    {
      tag.push_back(*it++);
    }

    for (char c : tag)
    {
      (tag_num *= 10) += (c - '0');
    }

    return tag_num;
  }

  return -1;
}

void next_field(std::string::iterator& it, const std::string::iterator& end)
{
  while (it != end && *it != '\x01')
    ++it;

  if (it != end)
    ++it;
}

// Parse a string of raw data into a vector of tagvalue fields
// Any malformed field is ignored
std::vector<tagvalue::field> tagvalue::parse(std::string data)
{
  std::vector<field> fields;

  for (std::string::iterator it = data.begin(); it != data.end();)
  {
    int tag = parse_tag(it, data.end());
    if (tag == -1 || (it != data.end() && *it++ != '='))
    {
      next_field(it, data.end());
      continue;
    }

    std::string value;

    while (it != data.end() && *it != '\x01')
    {
      value.push_back(*it++);
    }

    if (it == data.end())
      break;
    ++it;

    fields.push_back({tag, value});
  }

  return fields;
}
