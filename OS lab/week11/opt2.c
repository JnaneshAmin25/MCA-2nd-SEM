#include<stdio.h>

int main() {
    int num_pages, pages[30], frames[10], faults = 0;
    printf("Enter the total number of pages: ");
    scanf("%d", &num_pages);
    printf("Enter the sequence of pages: ");
    for(int i = 0; i < num_pages; i++)
        scanf("%d", &pages[i]);
    int frame_size;
    printf("Enter frame size: ");
    scanf("%d", &frame_size);

    for(int i = 0; i < frame_size; i++)
        frames[i] = -1;

    for(int i = 0; i < num_pages; i++) {
        int page = pages[i];
        int found = 0;
        for(int j = 0; j < frame_size; j++) {
            if(frames[j] == page) {
                found = 1;
                break;
            }
        }
        if(!found) {
            faults++;
            int farthest_index = -1, farthest_future = -1;
            for(int j = 0; j < frame_size; j++) {
                int future_distance = 0;
                for(int k = i + 1; k < num_pages; k++) {
                    if(frames[j] == pages[k]) {
                        future_distance = k - i;
                        break;
                    }
                }
                if(future_distance == 0) {
                    farthest_index = j;
                    break;
                }
                if(future_distance > farthest_future) {
                    farthest_future = future_distance;
                    farthest_index = j;
                }
            }
            frames[farthest_index] = page;
        }
        printf("\nPage %d\tFrame: ", page);
        for(int j = 0; j < frame_size; j++)
            printf("%d\t", frames[j]);
    }
    printf("\nTotal number of faults = %d", faults);
    return 0;
}
