//
// Created by dom on 15/09/2026.
//

#include <iostream>

#include "parser.h"

int main()
{
  std::string in = "3=3";
  in.push_back('\01');
  in.append("2=2");
  in.push_back('\01');
  in.append("1=1");
  in.push_back('\01');

  const std::vector<tagvalue::pair> out = tagvalue::parse(in);

  for (tagvalue::pair p : out)
  {
    std::cout << p.tag << " " << p.value << std::endl;
  }

  return 0;
}