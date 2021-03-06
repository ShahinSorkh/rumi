#include "PrimitiveTypeParser.h"
#include "../Source.h"
#include "../CC.h"
#include "parser.h"
#include "../ast/PrimitiveType.h"

TypeToken::TypeToken(TypeEnum key, int spos, int epos, CC *cc, Source *s)
  : key(key)
{
  this->spos = spos;
  this->epos = epos;
  this->cc = cc;
  this->s = s;
}

AST *TypeToken::toAST(CC *cc){
  return new PrimitiveType(key);
}

std::string TypeToken::desc(){
  return typeEnumToString(key);
}

ParseResult PrimitiveTypeParser::scheme(CC *cc, Source *s, int pos){
  int end = extractNextAlphaNumerical(&s->str, pos);
  if(end == -1) return ParseResult();
  std::string w = s->str.substr(pos, end-pos);
  end--;
  if(w == "int")
    return new TypeToken(t_int, pos, end, cc, s);
  if(w == "f32")
    return new TypeToken(t_f32, pos, end, cc, s);
  if(w == "f64")
    return new TypeToken(t_f64, pos, end, cc, s);
  if(w == "any")
    return new TypeToken(t_any, pos, end, cc, s);
  if(w == "u8")
    return new TypeToken(t_u8, pos, end, cc, s);
  if(w == "u16")
    return new TypeToken(t_u16, pos, end, cc, s);
  if(w == "u32")
    return new TypeToken(t_u32, pos, end, cc, s);
  if(w == "u64")
    return new TypeToken(t_u64, pos, end, cc, s);
  if(w == "s8")
    return new TypeToken(t_s8, pos, end, cc, s);
  if(w == "s16")
    return new TypeToken(t_s16, pos, end, cc, s);
  if(w == "s32")
    return new TypeToken(t_s32, pos, end, cc, s);
  if(w == "s64")
    return new TypeToken(t_s64, pos, end, cc, s);
  if(w == "string")
    return new TypeToken(t_string, pos, end, cc, s);
  if(w == "unit")
    return new TypeToken(t_unit, pos, end, cc, s);
  if(w == "void")
    return new TypeToken(t_void, pos, end, cc, s);
  if(w == "bool")
    return new TypeToken(t_bool, pos, end, cc, s);
  return ParseResult();
}

std::string typeEnumToString(TypeEnum key){
  switch(key){
  case t_int:
    return "int";
  case t_f32:
    return "f32";
  case t_f64:
    return "f64";
  case t_any:
    return "any";
  case t_u8:
    return "u8";
  case t_u16:
    return "u16";
  case t_u32:
    return "u32";
  case t_u64:
    return "u64";
  case t_s8:
    return "s8";
  case t_s16:
    return "s16";
  case t_s32:
    return "s32";
  case t_s64:
    return "s64";
  case t_string:
    return "string";
  case t_unit:
    return "unit";
  case t_void:
    return "void";
  default:
    return "invalid type";
  }
}

TypeEnum typeEnumFromString(std::string key){
  if(key == "int") return t_int;
  if(key == "f32") return t_f32;
  if(key == "f64") return t_f64;
  if(key == "any") return t_any;
  if(key == "u8") return t_u8;
  if(key == "u16") return t_u16;
  if(key == "u32") return t_u32;
  if(key == "u64") return t_u64;
  if(key == "s8") return t_s8;
  if(key == "s16") return t_s16;
  if(key == "s32") return t_s32;
  if(key == "s64") return t_s64;
  if(key == "string") return t_string;
  if(key == "unit") return t_unit;
  if(key == "void") return t_void;
  if(key == "bool") return t_bool;

  // TODO
  return t_any;
}
