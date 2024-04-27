#include <omp.h>
#include <iostream>

int main() {
    int sharedVar = 0;
    omp_lock_t lock;
    omp_init_lock(&lock);  // Initialize the lock

    #pragma omp parallel num_threads(4)
    {
        // Each thread tries to update sharedVar 100 times
        for (int i = 0; i < 100; ++i) {
            omp_set_lock(&lock);  // Acquire the lock
            // Critical section begins
            ++sharedVar;
            // Critical section ends
            omp_unset_lock(&lock);  // Release the lock
        }
    }

    omp_destroy_lock(&lock);  // Destroy the lock when done

    std::cout << "Final value of sharedVar: " << sharedVar << std::endl;
    return 0;
}
