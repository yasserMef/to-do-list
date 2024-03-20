#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"

struct Task{
    char *task;
    int completed;// 1 represent true 0 -> false

};
struct Task *tasks = NULL;
int lenght = 0;
void addTask(const char *task){
    tasks = (Task *)realloc(tasks , (lenght +1)*sizeof(Task));
    // reserve taille task entrer
    tasks[lenght].task = (char *)malloc(strlen(task)+1);
    tasks[lenght].completed = 0;
    strcpy(tasks[lenght].task , task);
    lenght++;
    printf("task added \n");
}
void listTasks(){
    char status;
    for(int i=0 ; i<lenght ; i++){
        if(tasks[i].completed == 1){
            status = 'd';
            }else{
            status = 'n';
                }
    printf("%d. %s [%c]\n", i+1 ,tasks[i].task , status);

}
}

void markCompleted(int index){
    if(index <= lenght && index >0 ){
        tasks[index-1].completed = 1;
        printf("Task marked as completed\n");
    }else{
        printf("Invalid index\n");
        }
    }

void deleteTsks(int index){
    if(index <= lenght && index >0 ){
        index = index-1;
        free(tasks[index].task);
        for(int i = index ; i< lenght-1 ; i++){
            tasks[i]= tasks[i+1];
        }
        lenght--;
        tasks = (Task *)realloc(tasks , (lenght*sizeof(Task)));
    }else{
        printf("Invalid index\n");
        }
    }

void editTask(int index , const char* task){
        if(index <= lenght && index >0 ){
        index = index-1;
        char *editeTask = (char *)realloc(tasks[index].task , strlen(task)+1);
        if(editeTask != NULL){
            tasks[index].task = editeTask;
            strcpy(tasks[index].task , task);
            printf("Task updated successful\n");
            }else{
                 printf("Invalid index\n");
                }
    }else{
        printf("Invalid index\n");
        }
    }
