#include <stdio.h>
#include "analyzer.h"


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
    }

    return 0;

}