#pragma once

#define MAX_INT 2147483647

#include "../libmx/inc/libmx.h"

//              VALIDATION AND PARSING

void mx_validate_sysargs(int argc);
char *mx_validate_file(const char *filename);
void mx_print_line_err(int i);
int mx_validate_firstline(char *file);
int mx_validate_lines(char *file);
char **mx_create_link(const char *str);
void mx_parse_nums_and_names(char **strarr, int size,
char **num_split, char **names_split);
void mx_validate_weights(char **weights);
t_list *mx_parse_input(const char *filename, int *islands, int ***paths);
int mx_validate_islands(char **names, int num, char **text, char ***names_splitted, char ***numbers_splitted);
t_list *mx_create_names_list(char **names);

//              PATHFINDER ALGORITHM FUNCTIONS

void dijkstra(int **matrix, int n, int startnode, t_list *t_names);
int **mx_create_paths_matrix(t_list *names, char **lines, int l_count, int islands_count);
void mx_index_of(t_list **paths, t_list **lists, t_list * names, int *buf, int index, const int cur, int start);

//              PRINT FUNCTIONS

void mx_printerr(const char *str);
void print_results(int distance[], int startnode, int n, int **matrix, t_list *t_names, t_list **pred_lists);
void mx_print_delim();
void print_distance(int **matrix, int *index, int dist);
void print_path(t_list *names, int *path, int last);
void print_route(t_list *names, int *path);

// other functions
bool mx_isalpha(char c);
bool mx_isdigit(char c);
int mx_get_by_value(t_list *list, void *value);
void mx_clear_list(t_list **list, bool is_free);
bool mx_node_in_list(t_list *list, char *data);
void *mx_get_by_index(t_list *list, int i);

bool compare_routes(void * a, void *b);

