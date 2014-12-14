#include "llvm/ADT/ArrayRef.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/IRBuilder.h"
#include <vector>
#include <string>

//reference: http://www.ibm.com/developerworks/cn/opensource/os-createcompilerllvm1/

int main()
{
  llvm::LLVMContext & context = llvm::getGlobalContext();
  llvm::Module *module = new llvm::Module("asdf", context);
  llvm::IRBuilder<> builder(context);

  llvm::FunctionType *funcType = llvm::FunctionType::get(builder.getVoidTy(), false);
  llvm::Function *mainFunc = 
    llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "main", module);
  llvm::BasicBlock *entry = llvm::BasicBlock::Create(context, "entrypoint", mainFunc);
  builder.SetInsertPoint(entry);

  llvm::Value *helloWorld = builder.CreateGlobalStringPtr("hello world!\n");

  std::vector<llvm::Type *> putsArgs;
  putsArgs.push_back(builder.getInt8Ty()->getPointerTo());
  llvm::ArrayRef<llvm::Type*>  argsRef(putsArgs);

  llvm::FunctionType *putsType = 
    llvm::FunctionType::get(builder.getInt32Ty(), argsRef, false);
  llvm::Constant *putsFunc = module->getOrInsertFunction("puts", putsType);

  builder.CreateCall(putsFunc, helloWorld);
  builder.CreateRetVoid();
  module->dump();
}