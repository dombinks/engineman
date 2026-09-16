//
// Created by dom on 15/09/2026.
//

#include <iostream>

#include "parser.h"

int main()
{
  std::string in = "3=C";
  in.push_back('\x01');
  in.append("2=B");
  in.push_back('\x01');
  in.append("1=A");
  in.push_back('\x01');
  in.append("1.0=A");
  in.push_back('\x01');
  in.append("01=A");
  in.push_back('\x01');
  in.append("0=");
  in.push_back('\x01');
  in.append("=Z");
  in.push_back('\x01');
  in.append("=");
  in.push_back('\x01');
  in.push_back('\x01');
  const std::vector<tagvalue::field> out = tagvalue::parse(in);

  for (const tagvalue::field& f : out)
  {
    std::cout << f.tag << " " << f.value << std::endl;
  }

  return 0;
}