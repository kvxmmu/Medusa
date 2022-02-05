#ifndef MDSU_COMPILER_INTRIN_H
#define MDSU_COMPILER_INTRIN_H

#if defined(__GNUC__) || defined(__llvm__)
#define GNU_EXTENSIONS
#endif

#ifdef GNU_EXTENSIONS
#define likely(x)   __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)
#else
#define likely(x)   (x)
#define unlikely(x) (!!(x))
#endif

#endif