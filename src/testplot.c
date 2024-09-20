#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <math.h>
#include <pthread.h>


void *test_gnuplot(void* arg) {
    system("gnuplot realtime.gnuplot");
    return NULL;
}


void *test_WriteData(void* arg) {
    FILE *f1;
    FILE *f2;
    f1 = fopen("test1.dat", "w");
    f2 = fopen("test2.dat", "w");
    if (!f1 && !f2) {
        perror("Error opening files");
        goto out;
    }

    for (float i = 1; i <= 20; i+=0.5) {
        fprintf(f1, "%f\t%f\n", i, i * i);
        fprintf(f2, "%f\t%f\n", i, 100*sin(i));
        fflush(f1); 
        fflush(f2); 
        sleep(1); 
        printf(".\n");
    }

    fclose(f1);
    fclose(f2);

out:
    return NULL;
}

int testplot(void){
    pthread_t gnuplot_thread;
    pthread_t writeData_thread;

    if (pthread_create(&gnuplot_thread, NULL, test_gnuplot, NULL) != 0) {
        perror("Failed to create thread");
        exit(EXIT_FAILURE);
    }
    if (pthread_create(&writeData_thread, NULL, test_WriteData, NULL) != 0) {
        perror("Failed to create testWrite thread");
        return EXIT_FAILURE;
    }

    pthread_join(gnuplot_thread, NULL);
    pthread_join(writeData_thread, NULL);

    return EXIT_SUCCESS;
}

