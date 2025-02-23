#include <iostream>
#include <vector>

#include "functions.hpp"

int main(int argc, char** argv){

    if(argc != 2){
        std::cerr << "ERROR! USE:\n" << argv[0] << " <filename> " << std::endl;
        return -1;
    }

    std::string filename = argv[1];
    
    std::vector<unsigned int> datas;
    read_dataset(datas, filename);
    unsigned int n = datas.size();
    
    for(unsigned int i = 0; i < n; i++){
        std::cout << "[" << datas[i] << "]";
    }
    std::cout << std::endl;
    

    return 0;
}