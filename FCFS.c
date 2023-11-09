#include <stdio.h>

int main() {
    int n, temp;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int pid[n];   // process ids
    int ar[n];    // arrival times
    int bt[n];    // burst or execution times
    int ct[n];    // completion times
    int ta[n];    // turnaround times
    int wt[n];    // waiting times
    float avgwt = 0, avgta = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter process %d arrival time: ", i + 1);
        scanf("%d", &ar[i]);
        printf("Enter process %d burst time: ", i + 1);
        scanf("%d", &bt[i]);
        pid[i] = i + 1;
    }

    // Sorting according to arrival times
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - (i + 1); j++) {
            if (ar[j] > ar[j + 1]) {
                temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }

    // Finding completion times
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            ct[i] = ar[i] + bt[i];
        } else {
            if (ar[i] > ct[i - 1]) {
                ct[i] = ar[i] + bt[i];
            } else {
                ct[i] = ct[i - 1] + bt[i];
            }
        }
        ta[i] = ct[i] - ar[i];  // Turnaround time = completion time - arrival time
        wt[i] = ta[i] - bt[i];  // Waiting time = turnaround time - burst time
        avgwt += wt[i];         // Total waiting time
        avgta += ta[i];         // Total turnaround time
    }

    printf("\npid  arrival  burst  complete turn waiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d  \t %d\t%d\t%d\t%d\t%d\n", pid[i], ar[i], bt[i], ct[i], ta[i], wt[i]);
    }

    printf("\nAverage waiting time: %.2f\n", avgwt / n);     // Printing average waiting time.
    printf("Average turnaround time: %.2f\n", avgta / n);    // Printing average turnaround time.

    return 0;
}
