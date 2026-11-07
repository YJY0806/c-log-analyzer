struct LogResult {
    char filename[100];
    int total_lines;
    int error_lines;
    int info_lines;
    int warning_lines;
    char **error_messages;
};

struct LogResult analyzer_result (char filename[]);