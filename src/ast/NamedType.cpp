#include "NamedType.h"
#include "Named.h"
#include "../base.h"

NamedType::NamedType(std::string id)
  : id(id)
{}

void NamedType::prepare(CC *cc){
  // TODO
}

void NamedType::compile(CC *cc){
  Named *named = cc->lookup(id);
  if(!named || !named->isType){
    cc->debug(NONE) << id << " is not a type!" << std::endl;
    exit(1);
  }

  resolvedType = named->type;
}

void* NamedType::typegen(CC *cc){
  return resolvedType->typegen(cc);
}

bool NamedType::hasOp(CC *cc, std::string op, Expression *rhs){
  return resolvedType->hasOp(cc, op, rhs);
}

void *NamedType::opgen(CC *cc, Expression *lhs, std::string op, Expression *rhs){
  return resolvedType->opgen(cc, lhs, op, rhs);
}

Type* NamedType::optyperesolve(CC *cc, std::string op, Expression *rhs){
  return resolvedType->optyperesolve(cc, op, rhs);
}

Compatibility NamedType::compatible(Type *t){
  return resolvedType->compatible(t);
}

void* NamedType::castgen(CC *cc, Expression *e){
  return resolvedType->castgen(cc, e);
}

bool NamedType::hasMem(CC *cc, Expression *exp, std::string id){
  return resolvedType->hasMem(cc, exp, id);
}

void *NamedType::memgen(CC *cc, Expression *exp, std::string id){
  return resolvedType->memgen(cc, exp, id);
}

void *NamedType::memalloca(CC *cc, Expression *exp, std::string id){
  return resolvedType->memalloca(cc, exp, id);
}

Type *NamedType::memtyperesolve(CC *cc, Expression *exp, std::string id){
  return resolvedType->memtyperesolve(cc, exp, id);
}

Type *NamedType::baseType(CC *cc){
  return resolvedType->baseType(cc);
}
