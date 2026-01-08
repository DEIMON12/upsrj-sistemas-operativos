#include <stdio.h>
#include "process.h"

int main() {
    int n;
    printf("Número de procesos: ");
    scanf("%d", &n);

    Process p[n];
    read_processes(p, n);
    init_processes(p, n);

    // Lógica FCFS
    int current_time = 0;

    for (int i = 0; i < n; i++) {

        // Si el proceso aún no llega, la CPU espera
        if (current_time < p[i].arrival_time) {
            current_time = p[i].arrival_time;
        }

        // Tiempo de espera
        p[i].waiting_time = current_time - p[i].arrival_time;

        // Tiempo de retorno
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;

        // Avanza el tiempo actual
        current_time += p[i].burst_time;
    }

    print_results(p, n, "FCFS Scheduling");
    return 0;
}