#include <stdio.h>
#include <string.h>

// Print disk, stripe, and third value if required
void print_data (int A, int B, int C) {
    if (C == -1)
        printf("%d %d\n", A, B);
    else
        printf("%d %d %d\n", A, B, C);
}

// Calculate raid mapping
void raid_mapping(char T[], int N, int C, int S, int query) {
    int disk, stripe, second, factor;
    
    if (strcmp(T, "0") == 0) { // Level 0
        factor = N * C;
        disk = (query / C) % N;
        int offset = (query / factor) * C;
        int temp = query % C;
        stripe = offset + temp;

        print_data(disk, stripe, -1);
    }
    else if (strcmp(T, "1") == 0) { // Level 1
        print_data(0, query, 1);
    }
    else if (strcmp(T, "01") == 0) { // Level 01
        factor = N / 2;
        disk = query % factor;
        stripe = query / factor;
        second = disk + factor;
        
        print_data(disk, stripe, second);
    } 
    else if (strcmp(T, "10") == 0) { // Level 10
        /*factor = N / 2;
        if (query % factor == 0)
            disk = 0;
        else
            disk = 2;

        stripe = query / factor;
        second = disk + 1;*/

        factor = N / 2;
        disk = (query % factor) * 2;
        stripe = query / factor;
        second = disk + 1;
        
        print_data(disk, stripe, second);
    } 
    else if (strcmp(T, "4") == 0) { // Level 4
        factor = N - 1;
        disk = query % factor;
        stripe = query / factor;

        print_data(disk, stripe, factor);
    } 
    else if (strcmp(T, "5") == 0) { // Level 5
        factor = N - 1;
        stripe = query / factor;
        int parity = factor - (stripe % N);
        disk = query % N;
        
        print_data(disk, stripe, parity);
    }
}

int main() {
    char T[3];
    int N, C, S, Q;
    // Get specifications
    scanf("%s %d %d %d %d", T, &N, &C, &S, &Q);
    
    // Get all queries
    int queries[Q];
    for (int i = 0; i < Q; i++) {
        scanf("%d", &queries[i]);
    }

    // For each query perform raid mapping
    for (int i = 0; i < Q; i ++) {
        raid_mapping(T, N, C, S, queries[i]);
    }
    
    return 0;
}
