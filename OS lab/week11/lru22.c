#include <stdio.h>

#define MAX_FRAMES 3

int main() {
    int incomingStream[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 1, 2, 0};
    int frames[MAX_FRAMES];
    int pageFaults = 0;
    int pages = sizeof(incomingStream) / sizeof(incomingStream[0]);

    printf("Incoming \t\t Frame\n\t\t\tF1 F2 F3\n");

    for (int i = 0; i < pages; i++) {
        int pageFound = 0;

        for (int j = 0; j < MAX_FRAMES; j++) {
            if (incomingStream[i] == frames[j]) {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound) {
            if (pageFaults < MAX_FRAMES) {
                frames[pageFaults] = incomingStream[i];
            } else {
                int lruIndex = i;
                for (int j = 0; j < MAX_FRAMES; j++) {
                    int k;
                    for (k = i - 1; k >= 0; k--) {
                        if (frames[j] == incomingStream[k]) {
                            lruIndex = k;
                            break;
                        }
                    }
                    if (k == -1)
                        break;
                }
                frames[lruIndex % MAX_FRAMES] = incomingStream[i];
            }
            pageFaults++;
        }

        printf("\n%d\t\t\t", incomingStream[i]);
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
