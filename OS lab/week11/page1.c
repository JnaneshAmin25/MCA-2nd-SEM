#include <stdio.h>

#define MAX_FRAMES 3

int main() {
    int incomingStream[] = {7,0,1,2,0,3,0,4,2,3,0,3,1,2,0};
    int frames[MAX_FRAMES] = {-1, -1, -1};
    int pageFaults = 0;
    int pages = sizeof(incomingStream) / sizeof(incomingStream[0]);

    printf("Incoming \t\t Frame\n\t\t\tF1 F2 F3\n");

    for (int i = 0; i < pages; i++) {
        int page = incomingStream[i];
        int pageFound = 0;

        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound) {
            int replaced = 0;
            for (int j = 0; j < MAX_FRAMES; j++) {
                if (frames[j] == -1) {
                    frames[j] = page;
                    replaced = 1;
                    break;
                }
            }

            if (!replaced) {
                frames[pageFaults % MAX_FRAMES] = page;
            }
            pageFaults++;
        }

        printf("\n%d\t\t\t", page);
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] != -1)
                printf(" %d", frames[j]);
            else
                printf(" -");
        }
    }

    printf("\nTotal Page Faults:\t%d\n", pageFaults);
    return 0;
}
