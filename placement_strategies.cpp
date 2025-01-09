#include <iostream>
using namespace std;

// Function to implement the First Fit strategy
void firstFit(int blockSize[], int blockCount, int processSize[], int processCount) {
    int allocation[processCount];
    fill(allocation, allocation + processCount, -1); // Initialize allocation array with -1 (unallocated)

    for (int i = 0; i < processCount; i++) {
        for (int j = 0; j < blockCount; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i]; // Reduce available memory in the block
                break;
            }
        }
    }

    cout << "\nFirst Fit Allocation:" << endl;
    for (int i = 0; i < processCount; i++) {
        if (allocation[i] != -1)
            cout << "Process " << i + 1 << " allocated to Block " << allocation[i] + 1 << endl;
        else
            cout << "Process " << i + 1 << " not allocated" << endl;
    }
}

// Function to implement the Best Fit strategy
void bestFit(int blockSize[], int blockCount, int processSize[], int processCount) {
    int allocation[processCount];
    fill(allocation, allocation + processCount, -1);

    for (int i = 0; i < processCount; i++) {
        int bestIndex = -1;
        for (int j = 0; j < blockCount; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIndex == -1 || blockSize[j] < blockSize[bestIndex]) {
                    bestIndex = j;
                }
            }
        }

        if (bestIndex != -1) {
            allocation[i] = bestIndex;
            blockSize[bestIndex] -= processSize[i];
        }
    }

    cout << "\nBest Fit Allocation:" << endl;
    for (int i = 0; i < processCount; i++) {
        if (allocation[i] != -1)
            cout << "Process " << i + 1 << " allocated to Block " << allocation[i] + 1 << endl;
        else
            cout << "Process " << i + 1 << " not allocated" << endl;
    }
}

// Function to implement the Worst Fit strategy
void worstFit(int blockSize[], int blockCount, int processSize[], int processCount) {
    int allocation[processCount];
    fill(allocation, allocation + processCount, -1);

    for (int i = 0; i < processCount; i++) {
        int worstIndex = -1;
        for (int j = 0; j < blockCount; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIndex == -1 || blockSize[j] > blockSize[worstIndex]) {
                    worstIndex = j;
                }
            }
        }

        if (worstIndex != -1) {
            allocation[i] = worstIndex;
            blockSize[worstIndex] -= processSize[i];
        }
    }

    cout << "\nWorst Fit Allocation:" << endl;
    for (int i = 0; i < processCount; i++) {
        if (allocation[i] != -1)
            cout << "Process " << i + 1 << " allocated to Block " << allocation[i] + 1 << endl;
        else
            cout << "Process " << i + 1 << " not allocated" << endl;
    }
}

int main() {
    int blockCount, processCount;

    cout << "Enter the number of memory blocks: ";
    cin >> blockCount;
    int blockSize[blockCount];
    cout << "Enter the sizes of the memory blocks: ";
    for (int i = 0; i < blockCount; i++)
    {   cout<<"\nB"<<i+1<<"  ";
        cin >> blockSize[i];
    }
    cout << "Enter the number of processes: ";
    cin >> processCount;
    int processSize[processCount];
    cout << "Enter the sizes of the processes: ";
    for (int i = 0; i < processCount; i++)
     {   cout<<"\nP"<<i+1<<"  ";
         cin >> processSize[i];
     }
    // First Fit Strategy
    int blockSizeCopy1[blockCount];
    copy(blockSize, blockSize + blockCount, blockSizeCopy1);
    firstFit(blockSizeCopy1, blockCount, processSize, processCount);

    // Best Fit Strategy
    int blockSizeCopy2[blockCount];
    copy(blockSize, blockSize + blockCount, blockSizeCopy2);
    bestFit(blockSizeCopy2, blockCount, processSize, processCount);

    // Worst Fit Strategy
    int blockSizeCopy3[blockCount];
    copy(blockSize, blockSize + blockCount, blockSizeCopy3);
    worstFit(blockSizeCopy3, blockCount, processSize, processCount);

    return 0;
}

