#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
        int status, pid1, pid2, pid3, pid4, pid5;
        int fd[2];
        char message0[30];
        char *message1 = "Hello from your first child!";

        if (pipe(fd) == -1){ //Έλεγχος ορθής λειτουργίας pipe.
                perror("--An error occured with opening the pipe--");
                return 1;
        }

        pid1=fork();
        if(pid1!=0){
                close(fd[1]);
                read(fd[0], message0, 30); //Ανάγνωση μηνύματος από τον πατέρα Ρ0 που πρόκειται να δεχτεί από το παιδί διεργασία Ρ1.
                printf("\nProcess P0 here! My child, process P1, sent me the following message: %s\n\n", message0);
                close(fd[0]);

                pid2=fork();
                if(pid2==0){
                        pid3=fork();
			if(pid3==0) //Κύριο μέρος εργασίας της διεργασίας Ρ3.
                                printf("I'm process P3!\nMy PID is %d and my PPID is %d.\n", getpid(), getppid());
                        else
                                wait(&status); //Αναμονή από διεργασία Ρ2 μέχρι την ολοκλήρωση της Ρ3.
                }
                else{ //Κύριο μέρος εργασίας της διεργασίας Ρ0.
                        waitpid(pid2, &status, 0); //Αναμονή από διεργασία Ρ0 μέχρι την ολοκλήρωση της Ρ2.
                        printf("I'm process P0!\nMy PID is %d and my PPID is %d.\n", getpid(), getppid());
                        execlp("ps", "ps", (char *)NULL); //Εκτέλεση Ρ0 διεργασίας ως 'ps'.
                }
                if((pid2==0)&&(pid3!=0)){
                        pid4=fork();
                        if(pid4==0) //Κύριο μέρος εργασίας της διεργασίας Ρ4.
                                printf("I'm process P4!\nMy PID is %d and my PPID is %d.\n", getpid(), getppid());
                        else
                                wait(&status); //Αναμονή από διεργασία Ρ2 μέχρι την ολοκλήρωση της Ρ4.
                }
                if((pid2==0)&&(pid3!=0)&&(pid4!=0)){
                        pid5=fork();
                        if(pid5==0) //Κύριο μέρος εργασίας της διεργασίας Ρ5.
                                printf("I'm process P5!\nMy PID is %d and my PPID is %d.\n", getpid(), getppid());
                        else{
                                wait(&status); //Αναμονή από διεργασία Ρ2 μέχρι την ολοκλήρωση της Ρ5.
                                printf("I'm process P2!\nMy PID is %d and my PPID is %d.\n", getpid(), getppid());
                                /*Πλέον που έχει ολοκληρώσει το κύριο μέρος της εργασίας του και η τελευταία διεργασία παιδί της Ρ2, 
                                  δηλαδή η Ρ5, εκτελεί το δικό της κύριο μέρος και να τερματίζεται.*/
                        }
                }
        }
        else if(pid1==0){ //Κύριο μέρος εργασίας διεργασίας Ρ1.
                printf("I'm process P1!\nMy PID is %d and my PPID is %d.\n", getpid(), getppid());
                close(fd[0]);
                write(fd[1], message1, strlen(message1)+1); /* Αποστολή μηνύματος από διεργασία Ρ1 στην γονική της, Ρ0,
                                                               με μήκος όσο είναι η πρόταση +1 */
                close(fd[1]);
        }
        else{ //Περίπτωση όπου δεν έγινε η ορθή δημιουργία νέας διεργασίας για pid1 κατά την εκτέλεση της fork().
                perror("--An error occured while executing fork--");
        }

        return 0;
}