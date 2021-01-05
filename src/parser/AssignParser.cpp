#include "AssignParser.h"
#include "Symbols.h"

ParseResult AssignParser::scheme(CC *cc, Source *s, int pos){
  return ip.parse(cc, s, pos) >> esp >> vp;
}


AssignParser::AssignParser()
  : esp(s_eq)
{}