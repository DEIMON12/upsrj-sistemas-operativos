#include <stdio.h>
#include "process.h"

#define QUANTUM 2

int main() {
    int n;
    printf("Número de procesos: ");
    scanf("%d", &n);

    Process p[n];
    read_processes(p, n);
    init_processes(p, n);

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

    

    print_results(p, n, "RR Scheduling");
    return 0;
}
