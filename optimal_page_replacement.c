#include <stdio.h>

#define MAX_PAGES 20

// Function to find the index of the page that will be used farthest in the future
int findFarthest(int pages[], int n, int frame[], int f) {
    int farthest = -1, index = -1;

    for (int i = 0; i < f; i++) {
        int j;
        for (j = n; j < MAX_PAGES; j++) {
            if (frame[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }
        if (j == MAX_PAGES) {
            return i; // Page will not be used again, replace this one
        }
    }

    return index;
}

void optimalPageReplacement(int pages[], int n, int f) {
    int frame[f];
    int pageFaults = 0;

    // Initialize all frames to -1 (empty)
    for (int i = 0; i < f; i++) {
        frame[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        // Check if the page is already in one of the frames
        for (int j = 0; j < f; j++) {
            if (frame[j] == page) {
                found = 1;
                break;
            }
        }

        // If the page is not found, we need to replace one
        if (!found) {
            int replaceIndex = findFarthest(pages, i + 1, frame, f);
            frame[replaceIndex] = page; // Replace the page
            pageFaults++;
            printf("Page %d -> %d Page Fault = %d\n", page, page, pageFaults);
        } else {
            printf("Page %d -> %d Page Fault = %d\n", page, page, pageFaults);
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[MAX_PAGES], n, frames;

    // Input reference string
    printf("Enter number of pages in the reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string (separate pages by space): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Input number of frames
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    // Calling the Optimal Page Replacement function
    optimalPageReplacement(pages, n, frames);

    return 0;
}
