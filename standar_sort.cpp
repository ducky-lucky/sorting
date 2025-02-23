#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

#include "functions.hpp"

int main(int argc, char** argv){

    if(argc != 2){
        std::cerr << "ERROR! USE:\n" << argv[0] << " <filename> " << std::endl;
        return -1;
    }

    std::string filename = argv[1];

    std::vector<unsigned int> datas;
    read_dataset(datas, filename);

    auto start = std::chrono::high_resolution_clock::now();
    sort(datas.begin(), datas.end());
    auto finish = std::chrono::high_resolution_clock::now();
    long time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();

    if(check(datas)){
        std::cout << "Standar sort time\t" << filename << "\t" << time << " ms" << std::endl;
    }else{
        std::cerr << "Error sorting data." << std::endl;
    }
    
    return 0;
}