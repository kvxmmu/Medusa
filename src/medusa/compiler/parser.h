#ifndef MDSU_PARSER_H
#define MDSU_PARSER_H

#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <inttypes.h>
#include <stdio.h>

#include "../executor/codegen.h"

#define N_POS ((size_t)-1)

VMEmitter *medusa_compile(
    const char *src
);

#endif
