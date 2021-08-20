#include <string>
#include <strstream>
#include <fstream>

#include "llvm/ADT/Statistic.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Value.h"

#include "llvm/IR/AbstractCallSite.h"

#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/Obfuscation/CryptoUtils.h"
#include "llvm/Transforms/Obfuscation/StringObfuscation.h"

#include "llvm/Transforms/Obfuscation/ObfuscatioDebug.h"

using namespace std;
using namespace llvm;
using namespace llvm::Obfuscation;

#define OLLVM_DEBUG_FILE               ("/Volumes/Work/OLLVM.txt")
#define LOG_BUG_SIZE                   (1024 * 10)


Debug::Debug() {
   
   return;
}

Debug::~Debug() {
   
   return;
}

void Debug::Info(const char *aFormat, ...) {
   
   va_list      args;
   static char s_MSG[LOG_BUG_SIZE]  = {0};
   
   bzero(s_MSG, sizeof(s_MSG));
   
   va_start (args, aFormat);
   vsnprintf(s_MSG, sizeof(s_MSG), aFormat, args);
   va_end (args);
   
   if (false == Debug::mDEBUG_FILE.is_open()) {
      
      Debug::mDEBUG_FILE.open(OLLVM_DEBUG_FILE, std::ios::app);
      
   } /* End if () */

   Debug::mDEBUG_FILE << s_MSG << std::endl;
   
   return;
}

void Debug::Warn (const char *aFormat, ...) {
   
   va_list      args;
   static char s_MSG[LOG_BUG_SIZE]  = {0};
   
   bzero(s_MSG, sizeof(s_MSG));
   
   va_start (args, aFormat);
   vsnprintf(s_MSG, sizeof(s_MSG), aFormat, args);
   va_end (args);
   
   if (false == Debug::mDEBUG_FILE.is_open()) {
      
      Debug::mDEBUG_FILE.open(OLLVM_DEBUG_FILE, std::ios::app);
      
   } /* End if () */
   
   Debug::mDEBUG_FILE << s_MSG << std::endl;
   
   return;
}

ofstream llvm::Obfuscation::Debug::mDEBUG_FILE(OLLVM_DEBUG_FILE);
