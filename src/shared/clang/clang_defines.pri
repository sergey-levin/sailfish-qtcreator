DEFINES += CLANG_VERSION=\\\"$${LLVM_VERSION}\\\"
CLANG_INCLUDE_DIR=$$clean_path($${LLVM_LIBDIR}/clang/$${LLVM_VERSION}/include)
DEFINES += "\"CLANG_INCLUDE_DIR=\\\"$${CLANG_INCLUDE_DIR}\\\"\""
CLANG_BINDIR=$$clean_path($${LLVM_BINDIR})
DEFINES += "\"CLANG_BINDIR=\\\"$${CLANG_BINDIR}\\\"\""
