#include "parser.h"

static inline size_t medusa_find(
    const char *src,
    const char needle
) {
    size_t offset = 0;
    while (src[offset] != '\0') {
        if (src[offset++] == needle) return offset - 1;
    }

    return N_POS;
}

static bool medusa_cmp_until(
    const char *src,
    const char *value,
    const char until1,
    const char until2
) {
    size_t offset = 0;
    while (src[offset] != '\0' && src[offset] != until1 && src[offset] != until2) {
        if ((value[offset] == '\0') || (src[offset] != value[offset])) {
            return false;
        }
        
        ++offset;
    }

    return value[offset] == '\0';
}

static inline void medusa_split_pair(
    const char *src,
    const char sep,

    const char **first,
    const char **second
) {
    size_t offset = medusa_find(src, ' ');

    *first  = src;
    if (offset == N_POS) {
        *second = src;
    } else {
        *second = src + offset + 1;
    }
}

static inline bool medusa_cmp_cmd(
    const char *src,
    const char *with
) {
    return medusa_cmp_until(
        src,
        with,
        ' ',
        '\n'
    );
}

VMEmitter *medusa_compile(
    const char *src
) {
    size_t offset = 0;
    VMEmitter *emitter = malloc(sizeof(VMEmitter));
    emitter_new(emitter, 1024);

    while ((src[offset] != '\0') && offset != N_POS) {
        size_t pos = medusa_find(src + offset, '\n');
        const char *ptr = src + offset;
        
        if (pos == N_POS) {
            offset = N_POS;
        } else {
            offset += pos + 1;
        }

        const char *cmd  = NULL;
        const char *args = NULL;
        medusa_split_pair(
            ptr,
            ' ',
            &cmd,
            &args
        );

        if (ptr[0] == ';') {
            continue;
        } else if (medusa_cmp_cmd(cmd, "println")) {
            printf("Println - %s\n", cmd);
        }
    }

    return emitter;
}
