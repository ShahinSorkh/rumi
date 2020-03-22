#pragma once
#include "../Expression.h"

class PointerExpr: public Expression{
public:
  Expression *exp;
  PointerExpr(Expression *e):exp(e){}

  virtual ~PointerExpr();
  virtual llvm::Value *exprGen(Context *cc);
  virtual llvm::Value *getAlloca(Context *cc);
  virtual void compile(Context *cc);
  virtual Type *resolveType(Context *cc);
};