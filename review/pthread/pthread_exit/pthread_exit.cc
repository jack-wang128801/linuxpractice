#include<stdio.h>
#include<unistd.h>
#include<pthread.h>


void *ThreadEntry(void *arg){
  (void) arg;

  int count=5;
  while(count--){
    printf("In ThreadEntry:%lu\n",pthread_self());
    sleep(1);

  }
  pthread_exit(NULL);
  return NULL;
}

int main(){
  pthread_t tid;
  pthread_create(&tid,NULL,ThreadEntry,NULL);
  while(1){
    printf("In main Thread=%lu\n",pthread_self());
    sleep(1);
  }

  return 0;
}
