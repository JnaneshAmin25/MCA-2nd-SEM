#include <stdio.h>

#define FRAMES 3

int main() {
    int incomingStream[] = {0,7,7,2,3,0,9,7,0,0,7,7};
    int pageFaults = 0;
    int temp[FRAMES] = {-1, -1, -1};
    int pages = sizeof(incomingStream) / sizeof(incomingStream[0]);

    printf("Incoming \t\t Frame\n\t\t\tF1 F2 F3\n");

    for (int m = 0; m < pages; m++) {
        int pageFound = 0;

        for (int n = 0; n < FRAMES; n++) {
            if (incomingStream[m] == temp[n]) {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound) {
            int replaceIndex = pageFaults % FRAMES;
            temp[replaceIndex] = incomingStream[m];
            pageFaults++;
        }

        printf("\n%d\t\t\t", incomingStream[m]);
        for (int n = 0; n < FRAMES; n++) {
            if (temp[n] != -1)
                printf(" %d", temp[n]);
            else
                printf(" -");
        }
    }

    printf("\nTotal Page Faults:\t%d\n", pageFaults);
    return 0;
}
