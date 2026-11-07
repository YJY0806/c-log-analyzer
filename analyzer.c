#include <stdio.h>
#include "analyzer.h"
#include <string.h>

struct LogResult analyzer_result(char filename[]) {
    struct LogResult result;
    strcpy(result.filename, filename);
    result.total_lines = 0;
    result.error_lines = 0;

    FILE *file;
    file = fopen(filename, "r");
    char line[256];
    if (file == NULL) {
        printf("Input File is invalid %s\n", filename);
        return result;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        result.total_lines++;

        if (strstr(line, "ERROR")) {
            result.error_lines++;
        }
    }

    fclose(file);

    return result;
    
}