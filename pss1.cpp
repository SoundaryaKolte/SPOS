#include <iostream>
#include <cstring>

using namespace std;

// Constants
const int MAX_LABELS = 10;  // Maximum number of labels
const int MAX_INSTRUCTIONS = 10;  // Maximum number of instructions

// Structure to store label and its corresponding memory address
struct Label {
    char name[20];  // Label name
    int address;    // Memory address
};

int main() {
    // Sample assembly code
    const char *assemblyCode[MAX_INSTRUCTIONS] = {
        "START:  MOV A, B",
        "LOOP:  ADD C, D",
        "END:   HLT",
        "NEXT:  MOV B, A",
        "START: MOV D, E"  // Duplicate label (for testing)
    };
    
    // Array to store labels
    Label labelTable[MAX_LABELS];
    int labelCount = 0;  // To count the number of labels
    int memoryAddress = 0;  // Initial memory address
    
    // Process each line of the assembly code
    for (int i = 0; i < MAX_INSTRUCTIONS; i++) {
        // Temporary variables for extracting label and instruction
        char label[20], instruction[20];
        bool hasLabel = false;
        
        // Extract label (if present) and instruction
        int j = 0;
        while (assemblyCode[i][j] != '\0' && assemblyCode[i][j] != ' ' && assemblyCode[i][j] != ':') {
            label[j] = assemblyCode[i][j];
            j++;
        }
        label[j] = '\0';  // End of label
        
        // Skip past the label and the colon (if any)
        if (assemblyCode[i][j] == ':') {
            hasLabel = true;
            j++;  // Skip the colon
        }
        
        // Extract the instruction
        int k = 0;
        while (assemblyCode[i][j] != '\0') {
            instruction[k] = assemblyCode[i][j];
            j++;
            k++;
        }
        instruction[k] = '\0';  // End of instruction
        
        // If a label is present, add it to the label table
        if (hasLabel) {
            // Check if the label is already in the table (duplicate label check)
            bool labelExists = false;
            for (int j = 0; j < labelCount; j++) {
                if (strcmp(labelTable[j].name, label) == 0) {
                    labelExists = true;
                    break;
                }
            }
            
            // If label doesn't exist, add it
            if (!labelExists) {
                strcpy(labelTable[labelCount].name, label);
                labelTable[labelCount].address = memoryAddress;
                cout << "Label: " << label << " -> Address: " << memoryAddress << endl;
                labelCount++;
            } else {
                cout << "Warning: Duplicate label found: " << label << endl;
            }
        }

        // Increment memory address for the next instruction
        memoryAddress++;
    }

    // Print the final symbol table
    cout << "\nSymbol Table: " << endl;
    for (int i = 0; i < labelCount; i++) {
        cout << labelTable[i].name << " -> " << labelTable[i].address << endl;
    }

    return 0;
}
