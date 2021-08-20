
#include <string>
#include <strstream>
#include <fstream>

// HARRY
#define OLLVM_DEBUG           (1)
#define OBFUSCATION_STRING    (0)

namespace llvm {

namespace Obfuscation {

class Debug {
   
public:
   static void Info (const char *aFormat, ...);
   static void Warn (const char *aFormat, ...);

private:
   Debug();
   ~Debug();

private:
   
   static std::ofstream mDEBUG_FILE;
};
};
};

#if OLLVM_DEBUG
#  define OBFUS_INFO(x)       llvm::Obfuscation::Debug::Info x
#  define OBFUS_WARN(x)       llvm::Obfuscation::Debug::Warn x
#else
#  define OBFUS_INFO(x)
#  define OBFUS_WARN(x)
#endif
