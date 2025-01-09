#include <iostream>
using namespace std;

struct Process {
    int id;
    int burstTime;
    int arrivalTime;
};

void sjnScheduling(Process processes[], int n) {
    int completed = 0, currentTime = 0, waitTime = 0, turnAroundTime = 0;
    bool visited[n] = {false};

    while (completed < n) {
        int shortest = -1;
        int minBurstTime = 1e9;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && processes[i].arrivalTime <= currentTime && processes[i].burstTime < minBurstTime) {
                minBurstTime = processes[i].burstTime;
                shortest = i;
            }
        }

        if (shortest == -1) {
            currentTime++;
            continue;
        }

        visited[shortest] = true;
        waitTime += (currentTime - processes[shortest].arrivalTime);
        currentTime += processes[shortest].burstTime;
        turnAroundTime += (currentTime - processes[shortest].arrivalTime);

        cout << "Process " << processes[shortest].id
             << " | Waiting Time: " << (currentTime - processes[shortest].burstTime - processes[shortest].arrivalTime)
             << " | Turnaround Time: " << (currentTime - processes[shortest].arrivalTime) << "\n";

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
        cout << "Enter arrival time and burst time for Process " << processes[i].id << ": ";
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
    }

    sjnScheduling(processes, n);
    return 0;
}
