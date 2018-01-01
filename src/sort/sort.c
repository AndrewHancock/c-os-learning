#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* fill_array(int count) {
  int* array;
  int i;

  array = malloc(count * sizeof(int));
  for(i = 0; i < count; i++) {
    array[i] = rand();
  }
  return array;

}

int* copy_array(int* array, int count) {
  int* new_array;
  int size;
  size = sizeof(int) * count;
  new_array = malloc(size);
  memcpy(new_array, array, size);
  return new_array;
}

void insertion_sort(int* array, int count) {
  int i, j, tmp;
  for(i = 0; i < count; i++) {
    if(i > 0 && array[i] < array[i-1]) {
      tmp = array[i];
      for(j = i; j > 0 && array[j-1] > tmp; j--) {
	array[j] = array[j -1];
      }
      array[j] = tmp;
    }
  }
}

void print_array(int* array, int count) {
  int i;
  for(i = 0; i < count; i++) {
    printf("array[%d] == %d\n", i, array[i]);
  }
}

void is_sorted_msg(int* array, int count) {
  int i, sorted;
  sorted = 1;
  for(i = 0; i < count - 1 && array[i] > array[i + 1]; i++) {
    if(array[i] > array[i + 1]) {
      sorted = 0;
      printf("Array is not sorted. array[%d] = %d, array[%d] = %d\n", i, array[i], i+1, array[i+1]);
    }
  }
  if(sorted == 1) {
    printf("Array is sorted.\n");
  }

}

#define COUNT 100000
int main(int argc, char *argv) {
  int i;
  int *array, *copy;
  long elaps_us;

  printf("Filling array...\n");
  array = fill_array(COUNT);
  is_sorted_msg(array, COUNT);

  
  copy = copy_array(array, COUNT);
  printf("Sorting...\n");
  elaps_us = get_func_time(&insertion_sort, copy, COUNT);
  printf("%d elapsed microseconds.", elaps_us);
  is_sorted_msg(copy, COUNT);


  free(copy);
  free(array);
}
