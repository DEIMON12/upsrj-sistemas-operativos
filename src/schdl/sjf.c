#include <stdio.h>
#include "process.h"

/* ============================================================
 * Student implementation area
 * ============================================================ */
void sjf_schedule(Process p[], int n)
{
    (void)p;
    (void)n;
    /* TODO: Implement SJF scheduling algorithm here */
}

/* ============================================================
 * DO NOT MODIFY MAIN
 * ============================================================ */
#ifndef UNIT_TEST
int main(void)
{
    int n;
    printf("Número de procesos: ");
    scanf("%d", &n);

    Process p[n];

    read_processes(p, n);
    init_processes(p, n);

<<<<<<< HEAD
    /* ================================
       SJF Scheduling (No expropiativo)
       ================================ */

    int time = 0;
    int completed = 0;

    while (completed < n) {
        int idx = -1;
        int min_bt = 999999;

        for (int i = 0; i < n; i++) {
            if (p[i].remaining_time > 0 &&
                p[i].arrival_time <= time &&
                p[i].burst_time < min_bt) {

                min_bt = p[i].burst_time;
                idx = i;
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        p[idx].waiting_time = time - p[idx].arrival_time;
        time += p[idx].burst_time;

        p[idx].turnaround_time =
            p[idx].waiting_time + p[idx].burst_time;

        p[idx].remaining_time = 0;
        completed++;
    }

    /* ================================ */
=======
    sjf_schedule(p, n);
>>>>>>> 412d236 (Merge branch 'feature/schedulers' into develop)

    print_results(p, n, "SJF Scheduling");
    return 0;
}
<<<<<<< HEAD
=======
#endif
>>>>>>> 412d236 (Merge branch 'feature/schedulers' into develop)
