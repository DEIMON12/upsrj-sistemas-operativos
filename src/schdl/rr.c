#include <stdio.h>
#include "process.h"

<<<<<<< HEAD
#define QUANTUM 2

int main() {
=======
/* ============================================================
 * Student implementation area
 * ============================================================ */
void rr_schedule(Process p[], int n, int quantum)
{
    (void)p;
    (void)n;
    (void)quantum;
    /* TODO: Implement RR scheduling algorithm here */
}

/* ============================================================
 * DO NOT MODIFY MAIN
 * ============================================================ */
#ifndef UNIT_TEST
int main(void)
{
>>>>>>> 412d236 (Merge branch 'feature/schedulers' into develop)
    int n;
    int quantum;

    printf("Número de procesos: ");
    scanf("%d", &n);

    printf("Quantum: ");
    scanf("%d", &quantum);

    Process p[n];
    read_processes(p, n);
    init_processes(p, n);

<<<<<<< HEAD
    // Round Robin Scheduling

    int time = 0;
    int completed = 0;
    int i = 0;

    while (completed < n) {
        // Si el proceso aún no llega, avanzar tiempo
        if (p[i].arrival_time > time) {
            time++;
            continue;
        }

        // Si el proceso ya terminó, saltarlo
        if (p[i].remaining_time == 0) {
            i = (i + 1) % n;
            continue;
        }

        // Ejecutar proceso por un quantum
        if (p[i].remaining_time > QUANTUM) {
            time += QUANTUM;
            p[i].remaining_time -= QUANTUM;
        } else {
            time += p[i].remaining_time;
            p[i].remaining_time = 0;

            // Proceso termina aquí
            p[i].turnaround_time =
                time - p[i].arrival_time;

            p[i].waiting_time =
                p[i].turnaround_time - p[i].burst_time;

            completed++;
        }

        // Siguiente proceso (cola circular)
        i = (i + 1) % n;
    }

    
=======
    rr_schedule(p, n, quantum);
>>>>>>> 412d236 (Merge branch 'feature/schedulers' into develop)

    print_results(p, n, "RR Scheduling");
    return 0;
}
<<<<<<< HEAD
=======
#endif
>>>>>>> 412d236 (Merge branch 'feature/schedulers' into develop)
