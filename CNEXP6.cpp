#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define ll as long long (you were missing the space)
#define ll long long

int transmission(int i, int N, int tf, int tt) {
    int k;
    while (i <= tf) {
        int z = 0;
        printf("\nSending Window starting at Frame %d...\n", i); // Indicate window start

        for (k = i; k < i + N && k <= tf; k++) {
            printf("\nSending Frame %d ...", k);
            tt++;
        }

        for (k = i; k < i + N && k <= tf; k++) {
            int f = rand() % 2;
            if (f == 0) {
                printf("\nAcknowledgment for Frame %d...", k);
                z++;
            } else {
                printf("\nTimeout!! Frame Number : %d", k);
                printf("\nRetransmitting Window starting at Frame %d...\n", i); // Indicate retransmission start
                break; // Important: Exit the inner loop on timeout
            }
        }
        printf("\n");
        i = i + z; // Move i by the number of acknowledged frames
        if (z == 0) { // Handle the case where no acknowledgements were received (timeout on all frames in the window)
            // i remains the same, retransmission happens from the same starting frame
        }
    }
    return tt;
}

int main() {
    int tf, N, tt = 0;
    time_t t;
    srand((unsigned)time(&t));

    printf("Enter the Total number of frames : ");
    scanf("%d", &tf); // Use %d for integers

    printf("\nEnter the Window Size : ");
    scanf("%d", &N); // Use %d for integers

    int i = 1;
    tt = transmission(i, N, tf, tt);
    printf("\nTotal number of frames which were sent and resent are : %d", tt); // Use %d for integers
    return 0;
}
