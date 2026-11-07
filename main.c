#include <stdio.h>
#include "analyzer.h"
#include <stdlib.h>


int main (int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct LogResult result = analyzer_result(argv[1]);

    if (argc == 2) {
        printf("File name: %s\n", result.filename);
        printf("Total lines: %d\n", result.total_lines);
        printf("Error lines: %d\n", result.error_lines);
        for (int i = 0; i < result.error_lines; i++) {
            printf("Full error message: %s", result.error_messages[i]);
        }

        for (int i = 0;  i < result.error_lines; i++) {
            free(result.error_messages[i]);
        }

        free(result.error_messages);
    }

    return 0;

}