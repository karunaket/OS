#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n]; // Arrays to store burst time, waiting time, and turnaround time

    // Input burst time for each process
    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Calculate waiting time for each process
    wt[0] = 0; // First process doesn't wait
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }

    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    // Calculate total waiting time and total turnaround time
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Calculate average waiting time and average turnaround time
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;

    // Output waiting time and turnaround time for each process
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    // Output average waiting time and average turnaround time
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);

    return 0;
}