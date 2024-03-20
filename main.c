#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"

int main() {
    int running = 1;
    int choice ;
    char taskInput[100];
    int indexInput ;
    int size;


    printf("\nOptions\n");
    printf(".1 Add a task\n");
    printf(".2 List all tasks\n");
    printf(".3 Mark as complete\n");
    printf(".4 Edite task\n");
    printf(".5 Delete task\n");
    printf(".6 Exit\n");
    while(running){

        printf("Enter choice (1,2,3,4,5,6): ");
        scanf("%d", &choice);
        switch(choice){
               case 1:
                printf("Enter task: ");
                getchar();
                fgets(taskInput , sizeof(taskInput) , stdin);
                taskInput[strcspn(taskInput , "\n")] = '\0';
                addTask(taskInput);
                break;
               case 2:
                listTasks();
                break;
               case 3:
                printf("Enter index :");
                scanf("%d" ,&indexInput );
                markCompleted(indexInput);
                break;
               case 4:
                printf("Enter index :");
                scanf("%d" ,&indexInput );
                printf("Enter edited task: ");
                getchar();
                fgets(taskInput , sizeof(taskInput) , stdin);
                taskInput[strcspn(taskInput , "\n")] = '\0';
                editTask(indexInput , taskInput);
                break;
               case 5:
                printf("Enter index :");
                scanf("%d" ,&indexInput );
                deleteTsks(indexInput);
                break;
               case 6:
                   running =0;
               default:
                  printf("Invalide choice\n");
                  break;
            }
        }
    return 0;
}
