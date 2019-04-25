#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main() {

int pid = fork();
if (pid == 0) {
    printf("********* CHILD1 ***********");
    char* args[] = {"/bin/ps", "-ef", NULL};
    if(execvp("/bin/ps", args) < 0){
      printf("Fail to execute \"ps -ef\"\n");
    }
} else {
    waitpid(pid, NULL, 0);
    int pid2 = fork();
    if(pid2 == 0){
      printf("********* CHILD2 ***********");
      char* args[] = {"/usr/bin/free", "-h", NULL};
      if(execvp("/usr/bin/free", args) < 0){
        printf("Fail to execute \"free -h\"\n");
      }
    } else {
      	waitpid(pid2, NULL, 0);
    }
} 
return 0;
}
