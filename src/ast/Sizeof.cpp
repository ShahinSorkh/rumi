#include "Sizeof.h"
#include "../base.h"
#include "../LLContext.h"
#include "PrimitiveType.h"

Sizeof::Sizeof(Type *type_)
  : type_(type_)
{}

void Sizeof::compile(CC *cc){
  this->type_->compile(cc);
}

void Sizeof::prepare(CC *cc){
  this->type_->prepare(cc);
}

void *Sizeof::exprgen(CC *cc){
  auto dl = cc->llc->module->getDataLayout();
  auto size = dl.getTypeAllocSize((llvm::Type *)type_->typegen(cc));

  return llvm::ConstantInt::get(llvm::IntegerType::getInt8Ty(cc->llc->context), size, true);
}

Type *Sizeof::type(CC *cc){
  return new PrimitiveType(t_u8);
}

void *Sizeof::allocagen(CC *cc){
  graceFulExit(dbg, "Calling alloca on unsupported type");
  return 0;
}
