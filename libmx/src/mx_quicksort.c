#include "libmx.h"
void swap(char **a, char **b) {
  char *t = *a;
  *a = *b;
  *b = t;
}

int partition(char** arr, int left, int right, int* c ) {
  char* pivot = arr[right];
  
  int i = (left - 1);

  for (int j = left; j < right; j++) {
    if (mx_strlen(arr[j]) <= mx_strlen(pivot)) {
        
      i++;
      swap(&arr[i], &arr[j]);
      c++;
    }
  }

  swap(&arr[i + 1], &arr[right]);
  c++;
  
  return (i + 1);
}

int mx_quicksort(char** arr, int left, int right) {
    
    int stack[right - left + 1];
 
    int top = -1;
    stack[++top] = left;
    stack[++top] = right;
    int c = 0;
    while (top >= 0) {
        right = stack[top--];
        left = stack[top--];
 
        
        int p = partition(arr, left, right, &c);
 
        if (p - 1 > left) {
            stack[++top] = left;
            stack[++top] = p - 1;
        }
 
        if (p + 1 < right) {
            stack[++top] = p + 1;
            stack[++top] = right;
        }
    }
    return c;
}
