#include <stdio.h>
#include "analyzer.h"
#include <string.h>
#include <stdlib.h>

struct LogResult analyzer_result(char filename[]) {
    struct LogResult result;
    strcpy(result.filename, filename);
    result.total_lines = 0;
    result.error_lines = 0;
    result.warning_lines = 0;
    result.info_lines = 0;
    result.error_messages = NULL;

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
            result.error_messages = realloc(result.error_messages, result.error_lines * sizeof(char *));
            result.error_messages[result.error_lines - 1] = malloc((strlen(line) + 1) * sizeof(char));
            strcpy(result.error_messages[result.error_lines - 1], line);
        }
        else if (strstr(line, "WARNING")) {
            result.warning_lines++;
        }
        else if (strstr(line, "INFO")) {
            result.info_lines++;
        }

    }

    fclose(file);

    return result;
    
}