#include <stdio.h>
#include <string.h>
#include "words.h"

#define ROTL(a, b) (((a) << (b)) | ((a) >> (32 - (b))))

int
main(int argc, char **argv)
{
    if (argc != 2) {
        printf("usage: %s STRING\n", argv[0]);
        return 0;
    }

    unsigned n = sizeof(words) / sizeof(words[0]);
    unsigned l = (unsigned)strlen(argv[1]);
    unsigned a = 0xdeadbeef + l, b = l << 1, c = l << 2, d = l << 3;

    for (unsigned j = 0; j < l; j++) {
        d ^= argv[1][j];
        a += b; d ^= a; d = ROTL(d,16);
        c += d; b ^= c; b = ROTL(b,12);
        a += b; d ^= a; d = ROTL(d, 8);
        c += d; b ^= c; b = ROTL(b, 7);
    }

    printf("%s-%s-%s\n", words[a % n], words[b % n], words[c % n]);

    return 0;
}
