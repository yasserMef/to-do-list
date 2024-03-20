#ifndef TASK_H_
#define TASK_H_

void addTask(const char *task);
void listTasks();
void markCompleted(int index);
void deleteTsks(int index);
void editTask(int index , const char* task);
#endif
