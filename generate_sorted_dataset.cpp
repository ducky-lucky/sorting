#include <iostream>
#include <vector>

#include "functions.hpp"

int main(int argc, char** argv){

    if(argc != 3){
        std::cerr << "ERROR! USE:\n" << argv[0] << " <filename> <n>" << std::endl;
        return -1;
    }
    
    std::string filename = argv[1];
    unsigned int n = atol(argv[2]);

    std::vector<unsigned int> datas(n);
    for(unsigned int i = 0; i < n; i++){
        datas[i] = i;
    }
    
    write_dataset(datas, filename);

    return 0;
}