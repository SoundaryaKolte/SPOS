#include <iostream>
using namespace std;

struct Process {
    int id;
    int burstTime;
    int arrivalTime;
    int priority;
};

void priorityScheduling(Process processes[], int n) {
    bool visited[n] = {false};
    int completed = 0, currentTime = 0, waitTime = 0, turnAroundTime = 0;

    while (completed < n) {
        int highestPriority = -1;
        int minPriority = 1e9;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && processes[i].arrivalTime <= currentTime && processes[i].priority < minPriority) {
                minPriority = processes[i].priority;
                highestPriority = i;
            }
        }

        if (highestPriority == -1) {
            currentTime++;
            continue;
        }

        visited[highestPriority] = true;
        waitTime += (currentTime - processes[highestPriority].arrivalTime);
        currentTime += processes[highestPriority].burstTime;
        turnAroundTime += (currentTime - processes[highestPriority].arrivalTime);

        cout << "Process " << processes[highestPriority].id
             << " | Waiting Time: " << (currentTime - processes[highestPriority].burstTime - processes[highestPriority].arrivalTime)
             << " | Turnaround Time: " << (currentTime - processes[highestPriority].arrivalTime) << "\n";

        completed++;
    }

    cout << "Average Waiting Time: " << (float)waitTime / n << "\n";
    cout << "Average Turnaround Time: " << (float)turnAroundTime / n << "\n";
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "Enter arrival time, burst time, and priority for Process " << processes[i].id << ": ";
        cin >> processes[i].arrivalTime >> processes[i].burstTime >> processes[i].priority;
    }

    priorityScheduling(processes, n);
    return 0;
}
