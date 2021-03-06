#pragma once
#include "Expression.h"

class ConstBool: public Expression{
 public:
  bool truth;
  ConstBool(bool truth);

  virtual void compile(CC *cc) override;
  virtual void prepare(CC *cc) override;
  virtual void* exprgen(CC *cc) override;
  virtual Type* type(CC *cc) override;
  virtual void* allocagen(CC *cc) override;
};
