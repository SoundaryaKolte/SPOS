#include <iostream>
using namespace std;

struct Process {
    int id;
    int burstTime;
    int remainingTime; // To track remaining burst time
    int arrivalTime;
    int waitTime;
    int turnAroundTime;
};

void roundRobinScheduling(Process processes[], int n, int timeQuantum) {
    int currentTime = 0;
    bool done = false;
    int completedProcesses = 0;

    // Initialize waitTime and turnAroundTime to 0 for each process
    for (int i = 0; i < n; i++) {
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].waitTime = 0;
        processes[i].turnAroundTime = 0;
    }

    while (completedProcesses < n) {
        done = true;  // Assume all processes are completed

        for (int i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0) {
                done = false;  // There are still processes to execute

                // If remaining time is greater than time quantum, execute for time quantum
                if (processes[i].remainingTime > timeQuantum) {
                    currentTime += timeQuantum;
                    processes[i].remainingTime -= timeQuantum;
                } else {
                    // Process finishes, update time and calculate wait and turnaround times
                    currentTime += processes[i].remainingTime;
                    processes[i].waitTime = currentTime - processes[i].burstTime - processes[i].arrivalTime;
                    processes[i].turnAroundTime = currentTime - processes[i].arrivalTime;
                    processes[i].remainingTime = 0;
                    completedProcesses++;
                }
            }
        }

        // If all processes are completed, break out of the loop
        if (done) break;
    }

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << "Process " << processes[i].id 
             << " | Waiting Time: " << processes[i].waitTime 
             << " | Turnaround Time: " << processes[i].turnAroundTime << "\n";
    }

    // Calculate and print average waiting time and turnaround time
    float avgWaitTime = 0, avgTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        avgWaitTime += processes[i].waitTime;
        avgTurnaroundTime += processes[i].turnAroundTime;
    }
    cout << "Average Waiting Time: " << avgWaitTime / n << "\n";
    cout << "Average Turnaround Time: " << avgTurnaroundTime / n << "\n";
}

int main() {
    int n, timeQuantum;

    cout << "Enter number of processes: ";
    cin >> n;

    Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "Enter arrival time and burst time for Process " << processes[i].id << ": ";
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
    }

    cout << "Enter time quantum: ";
    cin >> timeQuantum;

    roundRobinScheduling(processes, n, timeQuantum);

    return 0;
}
