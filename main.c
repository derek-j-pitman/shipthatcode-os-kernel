#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* TODO (what-is-kernel): implement per the lesson description. */

int main(void) {
    char line[1024];
    int state = 3;
    while (fgets(line, sizeof line, stdin)) {
        char cmd[64];
        if (line[0] == '\n' || line[0] == 0) continue;
        if (sscanf(line, "%63s", cmd) != 1) continue;
        if (strcmp(cmd, "SYSCALL") == 0) {
            state = 0;
        }
        else if (strcmp(cmd, "IRET") == 0) {
            state = 3;
        }
        else if (strcmp(cmd, "INTR") == 0) {
            state = 0;
        }
        else if (strcmp(cmd, "PROBE") == 0) {
            printf("%d\n", state);
        }
    }
    return 0;
}
