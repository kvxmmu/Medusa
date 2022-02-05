#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "medusa/compiler/parser.h"
#include "medusa/executor/codegen.h"

int compile() {
    const char *lang = "push 10\n"
                       "push 20\n"
                       "sub\n"
                       "; This will be interpreted as 20 - 10\n\n"
                       "println";
    
    printf("Compiling:\n%s\n----------------------\n", lang);

    VMEmitter *emitter = medusa_compile(
        lang
    );
    if (emitter == NULL) {
        fprintf(stderr, "Failed to compile code\n");
        return 1;
    }

    FILE *fp = fopen("output.vmdsu", "wb");
    if (fp == NULL) {
        perror("Can't open output.vmdsu");
        return 2;
    }

    fwrite(emitter->buffer, 4, emitter->insns, fp);
    fclose(fp);

    free(emitter);

    return 0;
}

int execute() {
    return 0;
}

void help(const char *bin) {
    fprintf(stderr, "%s usage: %s (compile|exec)\n", bin, bin);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        help(argv[0]);
    }

    if (strcmp(argv[1], "exec") == 0) {
        return execute();
    } else if (strcmp(argv[1], "compile") == 0) {
        return compile();
    } else {
        help(argv[0]);
    }
}