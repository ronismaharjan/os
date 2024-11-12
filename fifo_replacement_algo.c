#include <stdio.h>

void FIFO(int frames, int n, int reference_string[]) {
    int page[frames];  // Array to hold the pages in memory
    int page_faults = 0;  // Variable to count page faults
    int front = 0, rear = 0;  // Queue pointers
    int i, j, page_found;

    // Initialize the page array with -1 (representing empty frames)
    for (i = 0; i < frames; i++) {
        page[i] = -1;
    }

    // Iterate through each page in the reference string
    for (i = 0; i < n; i++) {
        page_found = 0;

        // Check if the current page is already in memory
        for (j = 0; j < frames; j++) {
            if (page[j] == reference_string[i]) {
                page_found = 1;
                break;
            }
        }

        // If the page is not found in memory, it is a page fault
        if (!page_found) {
            // If there is space in memory, add the page
            if (page[rear] == -1) {
                page[rear] = reference_string[i];
            }
            // If there is no space, replace the oldest page (FIFO)
            else {
                page[front] = reference_string[i];
                front = (front + 1) % frames;  // Move the front pointer
            }

            // Move the rear pointer to the next position
            rear = (rear + 1) % frames;
            page_faults++;  // Increment page fault count

            // Print the page in memory after the page fault
            printf("Page %d -> ", reference_string[i]);
            for (j = 0; j < frames; j++) {
                if (page[j] != -1) {
                    printf("%d ", page[j]);
                }
            }
            printf("Page Fault = %d\n", page_faults);
        }
        else {
            // If it's a page hit, simply print the page number
            printf("Page %d -> ", reference_string[i]);
            for (j = 0; j < frames; j++) {
                if (page[j] != -1) {
                    printf("%d ", page[j]);
                }
            }
            printf("Page Fault = %d\n", page_faults);
        }
    }

    printf("\nTotal Page Faults = %d\n", page_faults);
}

int main() {
    int n, frames;

    // Take user input for number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    // Take user input for reference string length and values
    printf("Enter the number of pages in the reference string: ");
    scanf("%d", &n);

    int reference_string[n];
    printf("Enter the reference string:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &reference_string[i]);
    }

    // Call the FIFO function
    FIFO(frames, n, reference_string);

    return 0;
}
