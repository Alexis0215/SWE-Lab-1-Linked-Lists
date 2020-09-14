#include <stdio.h>

#include "list.h"

int main() {
  printf("Test your implementation\n");
  list_t* my_list = list_alloc();
  list_add_to_back(my_list, 21);
  list_add_to_back(my_list, 2);
  list_add_to_back(my_list, 9);
  list_add_to_back(my_list, 17);
  list_print(my_list);
  
  list_add_to_front(my_list,5);
  list_add_to_front(my_list,109);
  list_add_to_front(my_list,13);
  list_add_to_front(my_list,45);
  list_print(my_list);
  
	list_add_at_index(my_list, 6, 2);
  list_add_at_index(my_list, 26, 5);
  list_add_at_index(my_list, 37, 8);
  list_add_at_index(my_list, 6, 4);
  
  int x = list_length(my_list);
  printf("%d elements in the list!\n", x);
  list_print(my_list);
  
  list_remove_from_back(my_list);
  list_print(my_list);
  list_remove_at_index(my_list, 2);
  list_print(my_list);
  int y = list_get_elem_at(my_list, 0);
  printf("%d is at the given index\n", y);
  int z = list_get_index_of(my_list, 7);
  printf("%d holds the given element\n", z);
  list_is_in(my_list, 2);
  list_free(my_list);
  //list_print(my_list);
 
  
  
  
  return 0;
}