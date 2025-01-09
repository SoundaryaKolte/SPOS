#include <iostream>
using namespace std;

struct Process {
    int id;
    int burstTime;
    int arrivalTime;
};

void fcfsScheduling(Process processes[], int n) {
    int waitTime = 0, turnAroundTime = 0, currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrivalTime)
            currentTime = processes[i].arrivalTime;
        waitTime += (currentTime - processes[i].arrivalTime);
        currentTime += processes[i].burstTime;
        turnAroundTime += (currentTime - processes[i].arrivalTime);
        cout << "Process " << processes[i].id << " | Waiting Time: " << (currentTime - processes[i].burstTime - processes[i].arrivalTime)
             << " | Turnaround Time: " << (currentTime - processes[i].arrivalTime) << "\n";
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

    fcfsScheduling(processes, n);
    return 0;
}
