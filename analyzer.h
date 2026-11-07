struct LogResult {
    char filename[100];
    int total_lines;
    int error_lines;
};

struct LogResult analyzer_result (char filename[]);