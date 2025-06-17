// LPT Heuristic
#include <stdio.h>
#include <stdlib.h>

//int M;  //number of machines
//int n; //number of jobs

typedef struct Job {
    int id; //job identificador
    int p;  //time of processing
} Job;
/*

typedef struct Machine {
    int id;     //machine id
    Job* jobs;  //set of jobs in the machine
    float C_m;  //machine completion time
} Machine;

typedef struct Schedule {
    Machine machines[M];  //machines assignment
    float Cmax; //makespan of schedule
} Schedule;
*/

//Job* jobs = malloc(n * sizeof(Job));

Job* instance(int* n_ptr, int* M_ptr){
    int n = 9;
    int M = 3;
    
    if (n_ptr) *n_ptr = n;
    if (M_ptr) *M_ptr = M;

    Job* jobs = malloc(n * sizeof(Job));
    if (!jobs) {
        perror("Error allocating memory for jobs");
        exit(EXIT_FAILURE);
    }
    
    for(int i=0; i<n; i++){
        Job j = { .id = i+1, .p = i+1 };
        jobs[i] = j;
    }
    
    return jobs;
}

int main() {
    int n, M;
    Job* jobs = instance(&n, &M);

    printf("Se generaron %d trabajos para %d máquinas:\n", n, M);
    for (int i = 0; i < n; i++) {
        printf("Trabajo %d: p = %d\n", jobs[i].id, jobs[i].p);
    }

    free(jobs);
    return 0;
}
