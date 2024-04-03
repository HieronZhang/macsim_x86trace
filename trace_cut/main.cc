#include <iostream>
#include <fstream>
#include <zlib.h>
#include <vector>
#include <string>

// Define the size of each element
const int ELEMENT_SIZE = 80;

int main() {

    for (size_t i = 0; i < 4; i++)
    {
        std::cout<<"Now working the "<<i<<"th file"<<std::endl;
        std::string filename = "trace_" + std::to_string(i) + ".raw";
    
        // const char* filename = "trace_0.raw";
        std::string newFilename = "new/" + filename;

        gzFile file = gzopen(filename.c_str(), "rb");
        if (!file) {
            std::cerr << "Error: Unable to open file." << std::endl;
            return 1;
        }

        // Open the output file
        gzFile newFile = gzopen(newFilename.c_str(), "wb");
        if (!newFile) {
            std::cerr << "Error: Unable to create new file." << std::endl;
            return 1;
        }


        char buffer[ELEMENT_SIZE*1000];
        long instruction_total_num = 0;
        long index = 0;

        while (gzread(file, buffer, ELEMENT_SIZE*1000) > 0)
        {
            instruction_total_num+=1000;
            index+=1000;

            // if (index > 20 && index < 41 || index > 50)
            // {
            //     gzwrite(newFile, buffer, ELEMENT_SIZE*1000);
            // }

            if (instruction_total_num % 1000000 == 0)
            {
                std::cout << "Current number of instructions: " << instruction_total_num << std::endl;
            }
        }

        std::cout << "Total number of instructions: " << instruction_total_num << std::endl;

        // Close the input file
        gzclose(file);

        // Close the output file
        gzclose(newFile);

        // std::cout << "Successfully copied elements 20 to 40 and 50 to end to new file." << std::endl;

    }

    return 0;

}