#include "perf.h"
#include <stdio.h>

void perf_test() {
    init_perf_events();
    start_counting_events();
    volatile int x=0;
    for (int i=0; i<10; i++) {
        x++;
    }
    stop_and_read_events();
    printf("%i \n", x);
    int c = get_total_cycles();
    printf("Total Cycles: %i", c);
    print_counter();
    cleanup_perf_events();
}

int main() {
    perf_test();
}