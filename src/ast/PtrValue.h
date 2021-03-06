#pragma once
#include "Expression.h"

class PtrValue: public Expression{
 public:
  Expression *ptr;
  
  PtrValue(Expression *ptr);

  virtual void compile(CC *cc) override;
  virtual void prepare(CC *cc) override;
  virtual void* exprgen(CC *cc) override;
  virtual Type *type(CC *cc) override;
  virtual void *allocagen(CC *cc) override;
};
