#include "a1.h"
#include <stdio.h>
#include <stdlib.h>

void init(list_t * list) {
   list->age = 0;
   list->occurs = 0;
   list->next = NULL;
}

bool insert(list_t * list, int val) {
   list_t * tmp = list;
   //check the list, if it is empty return 0
   if (list == NULL) {
      printf("ERROR: The list is NULL!\n");
      return 0;
   } else {

      while (tmp->next != NULL) {
         tmp = tmp->next;
         if (tmp->age == val) {
            tmp->occurs++;
            return 1;
         }
         //tmp = tmp -> next;
      }

      list_t * newNode = malloc(sizeof(list_t));
      //newNode -> word = malloc(sizeof(char) * 1024);
      init(newNode);

      if (newNode == NULL) {
         printf("ERROR: Cannot malloc memory!");
         return 0;
      } else {
         newNode->age = val;
         newNode->next = tmp->next;
         tmp->next = newNode;
         newNode->occurs++;
         return 1;
      }
   }
}

bool raw_insert(list_t * list, int val) {
   list_t * tmp = list;
   //check the list, if it is empty return 0
   if (list == NULL) {
      printf("ERROR: The list is NULL!\n");
      return 0;
   } else {
      while (tmp->next != NULL) {
         tmp = tmp->next;
      }
      list_t * newNode = malloc(sizeof(list_t));
      //newNode -> word = malloc(sizeof(char) * 1024);
      init(newNode);

      if (newNode == NULL) {
         printf("ERROR: Cannot malloc memory!");
         return 0;
      } else {
         newNode->age = val;
         newNode->next = tmp->next;
         tmp->next = newNode;
         return 1;
      }
   }
}

// check each and every it
int * set_width(list_t * list) {
   int i;
   int *a;
   // remember must use malloc
   a = malloc(sizeof(int) * 8);
   a[7] = 0;
   list_t * tmp = list;
   if (list == NULL) {
      printf("ERROR: The list is NULL!\n");
      return 0;
   } else {
      while (tmp->next != NULL) {
         tmp = tmp->next;
         if (tmp->age >= 0 && tmp->age < 10) {
            //stuff
            a[0]++;
         } else if (tmp->age >= 10 && tmp->age < 20) {
            //stuff
            a[1]++;
         } else if (tmp->age >= 20 && tmp->age < 30) {
            //stuff
            a[2]++;
         } else if (tmp->age >= 30 && tmp->age < 40) {
            //stuff
            a[3]++;
         } else if (tmp->age >= 40 && tmp->age < 50) {
            //stuff
            a[4]++;
         } else if (tmp->age >= 50 && tmp->age < 60) {
            //stuff
            a[5]++;
         } else if (tmp->age >= 60 && tmp->age < 70) {
            //stuff
            a[6]++;
         } else if (tmp->age >= 70 && tmp->age < 80) {
            //stuff
            a[7]++;
         }
      }
   }
   return a;
}

void fd_mode(list_t * list) {
   int max_mode = 0, modality = 0;
   int i;
   list_t * tmp = list;
   if (list == NULL) {
      printf("ERROR: The list is NULL!\n");
   } else {
      while (tmp->next != NULL) {
         tmp = tmp->next;
         if (tmp->occurs > max_mode) {
            max_mode = tmp->occurs;
         }
      }
   }
   tmp = list;
   while (tmp->next != NULL) {
      tmp = tmp->next;
      if (tmp->occurs == max_mode) {
         modality++;
      }
   }
   if (modality == 2)
      printf("The data set is bimodal.\n");
   else
      printf("The data set is trimodal.\n");
}
