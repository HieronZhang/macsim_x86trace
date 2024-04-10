#include <iostream>
#include <fstream>
#include <zlib.h>
#include <vector>
#include <string>
#include <pthread.h>

// Define the size of each element
const int ELEMENT_SIZE = 80;


// Define a struct to hold thread arguments
struct ThreadArgs {
    int index;
    // Add other arguments as needed by the thread function
};


void* do_trace_cut(void* arg) {

    // Extract thread arguments
    ThreadArgs* args = static_cast<ThreadArgs*>(arg);
    int i = args->index;

    std::cout<<"Now working the "<<i<<"th file"<<std::endl;
    std::string filename = "trace_" + std::to_string(i) + ".raw";

    // const char* filename = "trace_0.raw";
    std::string newFilename = "new/" + filename;

    gzFile file = gzopen(filename.c_str(), "rb");
    if (!file) {
        std::cerr << "Error: Unable to open file." << std::endl;
        exit(1);
    }

    // Open the output file
    gzFile newFile = gzopen(newFilename.c_str(), "wb");
    if (!newFile) {
        std::cerr << "Error: Unable to create new file." << std::endl;
        exit(1);
    }


    char buffer[ELEMENT_SIZE*10000];
    long instruction_total_num = 0;
    long index = 0;
    long start_offset = 100;
    long total = 31943952625;
    long ck1 = total / 10 * 1;
    long ck2 = total / 10 * 3;
    long ck3 = total / 10 * 5;
    long ck4 = total / 10 * 7;
    long ck5 = total / 10 * 9;
    long delta = 1000000;

    while (gzread(file, buffer, ELEMENT_SIZE*10000) > 0)
    {
        instruction_total_num+=10000;
        index+=10000;

        if(i==0){
            if ((index > ck1+start_offset && index <= ck1+start_offset  + delta) || (index > ck2+start_offset  && index <= ck2+start_offset  + delta) || (index > ck3+start_offset  && index <= ck3+start_offset  + delta) || (index > ck4+start_offset  && index <= ck4+start_offset  + delta) || (index > ck5+start_offset  && index <= ck5+start_offset + delta))
            {
                gzwrite(newFile, buffer, ELEMENT_SIZE*10000);
            }
            else if(index > ck5 + delta+start_offset )
                break;
        }
        else
        {
            if ((index > ck1 && index <= ck1 + delta) || (index > ck2 && index <= ck2 + delta) || (index > ck3 && index <= ck3 + delta) || (index > ck4 && index <= ck4 + delta) || (index > ck5 && index <= ck5 + delta))
            {
                gzwrite(newFile, buffer, ELEMENT_SIZE*10000);
            }
            else if(index > ck5 + delta)
                break;
        }
        
        
        if (instruction_total_num % 10000000 == 0)
        {
            std::cout << "Current number of instructions: " << instruction_total_num << std::endl;
        }
    }

    std::cout << "Total number of instructions: " << instruction_total_num << std::endl;

    // Close the input file
    gzclose(file);

    // Close the output file
    gzclose(newFile);

    // Clean up and exit
    delete args;
    pthread_exit(NULL);
    
}

int main() {

    const int NUM_THREADS = 4;
    pthread_t threads[NUM_THREADS];

    
    // Create threads
    for (int i = 0; i < NUM_THREADS; ++i) {

        // Create thread arguments
        ThreadArgs* args = new ThreadArgs();
        args->index = i;

        int rc = pthread_create(&threads[i], NULL, do_trace_cut, static_cast<void*>(args));
        if (rc) {
            std::cerr << "Error: Unable to create thread, " << rc << std::endl;
            return 1;
        }
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;

}