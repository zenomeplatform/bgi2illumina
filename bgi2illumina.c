#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { int lane, xpos, ypos, tile, read; } DataFields;


int main(int argc, char *argv[])
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <instrument>:<run_number>:<flowcell_id>\n", argv[0]);
        exit(EXIT_FAILURE);
    }    

    while ((nread = getline(&line, &len, stdin)) != -1)
    {
        if (line[0] == '@') {
            char *suffix = line;
            while (*suffix != 'L' && *suffix != '\0' && *suffix != '\n') suffix++;
            DataFields data = { 0, 0, 0, 0, 0 };
            sscanf(suffix, "L%1dC%3dR%3d%7d/%1d", &data.lane, &data.xpos, &data.ypos, &data.tile, &data.read);
            while (*suffix != '_' && *suffix != '\0' && *suffix != '\n') suffix++;
            if (*suffix == '_') *suffix = ':';
            //fwrite(suffix, strlen(suffix), 1, stdout);
            printf("@%s:%d:%d:%d:%d %d:N:0%s", argv[1], data.lane, data.tile, data.xpos, data.ypos, data.read, suffix);
        } else {
            fwrite(line, nread, 1, stdout);
        }
    }

    free(line);
    printf("\n");
    exit(EXIT_SUCCESS);
}
