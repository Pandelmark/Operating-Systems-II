#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

struct arg_struct{
        int t_num;
        int n;
        int div;
        int *arr;
        int *start;
        int threads;
}; /* Δημιουργία μίας struct έτσι ωσότου να μπορέσουμε να περάσουμε πολλαπλά στοιχεία από τη παράμετρο της εντολής
      pthread_create για να αξιοποιηθούν στη συνέχεια από το κάθε thread. */

int total_sum=0;
pthread_mutex_t mutex;

void *local_sum(void *param){
        struct arg_struct *ptr = (struct arg_struct *)param; //Δήλωση struct μέσα στη συνάρτηση.
        int local_sum=0, i;
        int pos = ptr->start[ptr->threads]; /* Σε αυτή τη γραμμή δηλώνεται μία μεταβλητή που αποσκοπεί τον
                                               κατάλληλο διαμοιρασμό των τιμών του πίνακα arr στα νήματα. */

        pthread_mutex_lock(&mutex); /* Σε αυτό το σημείο κλειδώνουμε τη λειτουργία όλων εκτός από του τρεχούμενου thread για τις συγκεκριμένες τιμές χρησιμοποιόντας την "mutex". */
        for(int i = 0; i<ptr->div; i++)
                local_sum += ptr->arr[pos + i]*ptr->arr[pos + i];
        total_sum += local_sum;

        pthread_mutex_unlock(&mutex); //Σε αυτή τη γραμμή γίνεται η αποδέσμευση του περιορισμού λειτουργίας της mutex.
        printf("\n\n***Τοπικό σύνολο %dου νήματος (local sum): %d\n", ptr->threads+1, local_sum);
        if(ptr->threads+1 == ptr->t_num){
                printf("==========================\n");
                printf("Τελικό αποτέλεσμα (total sum): %d\n", total_sum);
        }
}

int main(){
        struct arg_struct elements;
        pthread_mutex_init(&mutex, NULL); /*Εν μέσω αυτής της δήλωσης γίνεται μέσω του "mutex" thread η σειριοποίηση
                                            των κρίσιμων πόρων όπου θα χρησιμοποιηθούν στο πρόγραμμα από τα threads. */
        int i;

        //Έναρξη εισαγωγής στοιχείων από τον Χρήστη.
        printf("\nΤοποθετήστε τον επιθυμητό αριθμό των όρων του πίνακα: ");
        scanf("%d", &elements.n);

        printf("\nΤοποθετήστε τον επιθυμητό αριθμό νημάτων: ");
        scanf("%d", &elements.t_num);
        pthread_t threads[elements.t_num]; //Δήλωση πίνακα νημάτων-threads.

        elements.start = (int *)malloc(elements.t_num*sizeof(int)); /*Δέσμευση χώρου για τα δεδομένα όπου θα αποθηκεύει
                                                                      το κάθε thread. */
        elements.arr = (int *)malloc(elements.n*sizeof(int)); /*Δέσμευση χώρου για τις τιμές του πίνακα arr
                                                                όπου θα αποθηκευτούν οι τιμές που δίνει ο χρήστης. */
        if (elements.arr == NULL){
                printf("Σφάλμα: Μη διαθέσιμη μνήμη!\n");
        exit(EXIT_FAILURE);
        }

        elements.div=elements.n/elements.t_num; //Διαμοιρασμός ίσου αριθμού τιμών του συνόλου n στα δοθέντα threads.

        for(i=0; i<elements.n; i++){
            printf("\nΤοποθετήστε τιμή μεταβλητής: ");
            scanf("%d", &elements.arr[i]);
        }

        for(i=0; i<elements.t_num; i++){
            elements.threads = i;
            elements.start[i] = i * elements.div;
            pthread_create(&threads[i], NULL, &local_sum, (void *)&elements);/* Σε αυτή τη γραμμή γίνεται η δημιουργία
                                                                            του κάθε thread καθώς και η ένδειξη 
                                                                            σε αυτά της συνάρτησης που θέλουμε να
                                                                            χρησιμοποιήσουν και η παράμετρος με τα
                                                                            στοιχεία που θέλουμε να περάσουν σε αυτή.*/
            pthread_join(threads[i], NULL); //Συγχρονισμός των threads.
        }

        pthread_mutex_destroy(&mutex); //Πλέον δε μας χρειάζεται το "mutex" άρα και το διαγράφουμε με την εντολή αυτή.
        return 0;
}
