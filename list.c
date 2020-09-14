// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>

#include "list.h"

list_t *list_alloc() { 
  list_t* new_list = (list_t*) malloc(sizeof(list_t));
  new_list->head = NULL;
  return new_list;
}

void list_free(list_t *l) {
  if (!l) {
    return;
  }
  free(l);
}

void list_print(list_t *l) {
  if (l->head == NULL){
    printf("Empty");
  }
  node_t* current = l->head;
  while(current != NULL){
    printf("%d ", current->value);
    current = current->next;
  }
  printf("\n");
}

int list_length(list_t *l) { 
  int i =0;
  node_t *temp = l->head;
  while(temp){
    i++;
    temp = temp->next;
  }
  return i;
}

void list_add_to_back(list_t *l, elem value) {
  if(l->head == NULL){
    l->head = (node_t *) malloc(sizeof(node_t));
    l->head->value = value;
    l->head->next = NULL;
  } else{
    node_t* temp = l->head;
    node_t* new_node = (node_t *) malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = NULL;
    while(temp->next != NULL){
      temp = temp->next;
    }
    temp->next = new_node;
  } 
}
void list_add_to_front(list_t *l, elem value) {
  if(l->head == NULL){
    l->head = (node_t *) malloc(sizeof(node_t));
    l->head->value = value;
    l->head->next = NULL;
  } else{
    node_t* new_node = (node_t *) malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = l->head;
    l->head = new_node;
  }
}
  
void list_add_at_index(list_t *l, elem value, int index) {
  if(l->head == NULL){
    l->head = (node_t *) malloc(sizeof(node_t));
    l->head->value = value;
    l->head->next = NULL;
  } else if (index == 0){
    list_add_to_front(l, value);
  }else {
    node_t* temp = l->head;
    node_t* new_node = (node_t *) malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = NULL;
		int i = 1;
    while(i != index){
      temp = temp->next;
      i++;
    }
    new_node->next = temp->next;
    temp->next = new_node;
  }
}


elem list_remove_from_back(list_t *l) { 
  if(l->head == NULL){
      return -1; 
   
  }else{
    node_t* temp = l->head;
    while(temp->next->next != NULL){
      temp = temp->next;
    }
    node_t *found = (node_t *) malloc(sizeof(node_t));
    found = temp->next;
    temp->next = NULL;
    free(found);
  } 
}

elem list_remove_from_front(list_t *l) { 
  if(l->head == NULL){
    return -1; 
   
  }else{
    node_t* temp = l->head;
    l->head = l->head->next;
    free(temp);
    
   
  }
  
 }
elem list_remove_at_index(list_t *l, int index) { 
  
  if(l->head == NULL){
    return -1; 
   
  }else if(index == 0){
    return list_remove_from_front(l);
    
  }else{
    node_t* curr = l->head;
    int i;
    for(i=0;i<(index-1);i++){
      if(curr->next == NULL){
        return -1;
      }
      curr = curr->next;
    }
    node_t *temp = (node_t *) malloc(sizeof(node_t));
    temp = curr->next;
    curr->next = temp->next;
     free(temp);
    
  }
}

bool list_is_in(list_t *l, elem value) {
  node_t* curr = l->head;  
  while(curr != NULL){
    if (curr->value == value){
      return true;
    }else{
      curr = curr->next;
    }
  }
  return false;
}
  


elem list_get_elem_at(list_t *l, int index) { 
  if(l->head == NULL){
    return -1; 
    
  }else{
    node_t* curr = l->head;
    int i;
     for(i=0;i<index;i++){
       if(curr == NULL){
         return -1;
       }
       curr = curr->next;
     }
     elem found = curr->value;
     return found;
    
  }
} 
int list_get_index_of(list_t *l, elem value) { 
  if(l->head == NULL){
    return -1; 
    
  }else{
    node_t* curr = l->head;
    int length = list_length(l);
    int i;
    for(i=0;i<length;i++){
       if(curr->value == value){
         return i;
       }
       curr = curr->next;
    }

  }
} 