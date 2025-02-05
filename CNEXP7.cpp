#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TOTAL_FRAMES 500
#define WINDOW_SIZE 10

int frames_sent_at_instance;

int frames[TOTAL_FRAMES];
int window[WINDOW_SIZE];
char received_ack[WINDOW_SIZE];
int sender_window_start;
int receiver_window_start;

void initialize_frames(int num_bits);
void sender(int modulus);
void receiver(int modulus);

void initialize_frames(int num_bits) {
    int modulus = pow(2, num_bits);
    int frame_number = 0;

    frames_sent_at_instance = (modulus / 2);

    for (int i = 0; i < TOTAL_FRAMES; i++) {
        frames[i] = frame_number;
        frame_number = (frame_number + 1) % modulus;
    }

    for (int i = 0; i < frames_sent_at_instance; i++) {
        window[i] = frames[i];
        received_ack[i] = 'n'; // Initialize acknowledgements to 'n' (not received)
    }

    receiver_window_start = sender_window_start = frames_sent_at_instance;
}

void sender(int modulus) {
    int i = 0;
    while (i < frames_sent_at_instance) {
        if (received_ack[i] == 'n') {
            printf("SENDER: Frame %d sent\n", window[i]);
        }
        i++;
    }
    receiver(modulus);
}

void receiver(int modulus) {
    time_t t;
    int random_number;

    srand((unsigned)time(&t));

    for (int i = 0; i < frames_sent_at_instance; i++) {
        if (received_ack[i] == 'n') {
            random_number = rand() % 10;

            if (random_number != 5) { // Frame received correctly
                printf("RECEIVER: Frame %d received correctly\n", window[i]);

                int j;
                for (j = 0; j < frames_sent_at_instance; j++) {
                    if (window[j] == window[i]) {
                        window[j] = frames[receiver_window_start];
                        receiver_window_start = (receiver_window_start + 1) % modulus;
                        break;
                    }
                }

                if (j == frames_sent_at_instance) {
                    printf("RECEIVER: Duplicate frame %d discarded\n", window[i]);
                }

                random_number = rand() % 5;

                if (random_number == 3) { // Acknowledgement lost
                    printf("RECEIVER: Acknowledgement %d lost\n", window[i]);
                    printf("SENDER TIMEOUT: Resending the frame\n");
                    received_ack[i] = 'n'; // Resend this frame
                } else { // Acknowledgement received
                    printf("RECEIVER: Acknowledgement %d received\n", window[i]);
                    received_ack[i] = 'p';
                }
            } else { // Frame damaged or lost
                random_number = rand() % 2;
                if (random_number == 0) {
                    printf("RECEIVER: Frame %d damaged\n", window[i]);
                    printf("RECEIVER: Negative Acknowledgement sent\n");
                } else {
                    printf("RECEIVER: Frame %d lost\n", window[i]);
                    printf("SENDER TIMEOUT: Resending the frame\n");
                }
                received_ack[i] = 'n'; // Resend this frame
            }
        }
    }

    // Slide the sender's window
    int j = 0;
    for (int k = 0; k < frames_sent_at_instance; k++) {
        if (received_ack[k] == 'n') {
            break; // Stop at the first unacknowledged frame
        }
        j++; // Count acknowledged frames
    }

    if (j < frames_sent_at_instance) { // If not all frames were acknowledged
        int k;
        for (k = j; k < frames_sent_at_instance; k++) {
            window[k - j] = window[k]; // Shift unacknowledged frames to the left
            received_ack[k - j] = received_ack[k];
        }
        int num_new_frames = frames_sent_at_instance - j;
        for (k = 0; k < num_new_frames; k++) {
            window[frames_sent_at_instance - num_new_frames + k] = frames[sender_window_start];
            sender_window_start = (sender_window_start + 1) % modulus;
            received_ack[frames_sent_at_instance - num_new_frames + k] = 'n';
        }
    } else { // All frames acknowledged, move the window fully
        for (int k = 0; k < frames_sent_at_instance; k++) {
            window[k] = frames[sender_window_start];
            sender_window_start = (sender_window_start + 1) % modulus;
            received_ack[k] = 'n';
        }
    }


    char ch;
    printf("Want to continue? (y/n): ");
    scanf(" %c", &ch); // Note the space before %c to consume any leftover newline

    if (ch == 'y' || ch == 'Y') {
        sender(modulus);
    } 
}

int main() {
    int num_bits;
    printf("Enter the number of bits for the sequence number: ");
    scanf("%d", &num_bits);

    initialize_frames(num_bits);
    sender(pow(2, num_bits)); // Pass the modulus to sender

    return 0;
}
