#include <stdio.h>

#define MAX_FRAMES 3

int findLRUIndex(int pageReference[], int frames[], int n) {
    int index = -1, farthest = -1;
    for (int i = 0; i < MAX_FRAMES; i++) {
        int j;
        for (j = n - 1; j >= 0; j--) {
            if (frames[i] == pageReference[j] && j > farthest) {
                farthest = j;
                index = i;
                break;
            }
        }
        if (j == -1) return i;
    }
    return (index == -1) ? 0 : index;
}

void printFrames(int frames[]) {
    for (int i = 0; i < MAX_FRAMES; i++) {
        if (frames[i] == -1) printf(" -");
        else printf(" %d", frames[i]);
    }
    printf("\n");
}

int main() {
    int pageReference[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 1, 2, 0};
    int frames[MAX_FRAMES] = {-1};
    int pageFaults = 0;
    int n = sizeof(pageReference) / sizeof(pageReference[0]);

    printf("Incoming \t\t Frame\n\t\t\tF1 F2 F3\n");

    for (int i = 0; i < n; i++) {
        int pageFound = 0;
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == pageReference[i]) {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound) {
            int lruIndex = findLRUIndex(pageReference, frames, i);
            frames[lruIndex] = pageReference[i];
            pageFaults++;
        }

        printf("\n%d\t\t\t", pageReference[i]);
        printFrames(frames);
    }

    printf("\nTotal Page Faults:\t%d\n", pageFaults);
    return 0;
}

