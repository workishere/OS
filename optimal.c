#include <stdio.h>

int main() {
    int frames[10] = {-1}, pages[30], faults = 0, nof, nop;

    printf("Enter number of frames: ");
    scanf("%d", &nof);

    printf("Enter number of pages: ");
    scanf("%d", &nop);

    printf("Enter page reference string: ");
    for (int i = 0; i < nop; i++) scanf("%d", &pages[i]);

    for (int i = 0; i < nop; i++) {
        int page = pages[i], found = 0;

        for (int j = 0; j < nof; j++) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }

        if (!found) {
            int replace_index = -1, farthest = -1;

            for (int j = 0; j < nof; j++) {
                int k;
                for (k = i + 1; k < nop; k++) {
                    if (frames[j] == pages[k]) break;
                }
                if (k > farthest) {
                    farthest = k;
                    replace_index = j;
                }
                if (k == nop) {
                    replace_index = j;
                    break;
                }
            }

            frames[replace_index] = page;
            faults++;
        }

        for (int j = 0; j < nof; j++)
            printf("%d\t", frames[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}
