#include "functions.hpp"

bool check(std::vector<unsigned int>& datas){
    unsigned int n = datas.size();

    for(unsigned int i = 0; i < n-1; i++){
        if(datas[i] > datas[i+1]){
            return false;
        }
    }
    return true;
}

void read_dataset(std::vector<unsigned int>& datas, std::string& filename){
    std::ifstream f(filename, std::ios::in | std::ios::binary);
    f.seekg(0, std::ios::end);
    unsigned int n = f.tellg() / sizeof(int);
    f.seekg(0, std::ios::beg);
    datas.resize(n);

    int v;
    for(unsigned int i = 0; i < n; i++){
        f.read((char*)&v, sizeof(unsigned int));
        datas[i] = v;
    }

    f.close();
}

void write_dataset(std::vector<unsigned int>& datas, std::string& filename){
    std::ofstream f(filename, std::ios::out | std::ios::binary);
    unsigned int n = datas.size();

    for(unsigned int i = 0; i < n; i++){
        f.write((char*)(&(datas[i])), sizeof(unsigned int));
    }

    f.close();
}

void bubble_sort(std::vector<unsigned int>& datas){
    unsigned int n = datas.size();

    unsigned int aux;
    for(int i = n; i > 0; i--){
        for(unsigned int j = 1; j < i; j++){
            if(datas[j-1] > datas[j]){
                aux = datas[j];
                datas[j] = datas[j-1];
                datas[j-1] = aux;
            }
        }
    }
}

void selection_sort(std::vector<unsigned int>& datas){
    unsigned int n = datas.size();

    unsigned int min = UINT_MAX;
    unsigned int min_pos;
    unsigned int aux;
    for(unsigned int i = 0; i < n; i++){
        min = UINT_MAX;
        for(unsigned int j = i; j < n; j++){
            if(datas[j] < min){
                min = datas[j];
                min_pos = j;
            }
        }
        
        aux = datas[i];
        datas[i] = min;
        datas[min_pos] = aux;

    }
}

void insertion_sort(std::vector<unsigned int>& datas){
    unsigned int n = datas.size();

    unsigned int aux;
    for(unsigned int i = 1; i < n; i++){
        for(int j = i; j > 0; j--){
            if(datas[j-1] > datas[j]){
                aux = datas[j];
                datas[j] = datas[j-1];
                datas[j-1] = aux;
            }
        }
    }
}

void recursive_merge_sort(std::vector<unsigned int>& datas, unsigned int start, unsigned int end){
    unsigned int n = end-start;
    if(n == 2){
        if(datas[start] > datas[start+1]){
            unsigned int aux = datas[start+1];
            datas[start+1] = datas[start];
            datas[start] = aux;
        }
        return;
    }else if(n < 2){
        return;
    }
    unsigned int pivot = start + (unsigned int)(n / 2);

    recursive_merge_sort(datas, start, pivot);
    recursive_merge_sort(datas, pivot, end);

    // Merge step
    unsigned int* arr_aux = new unsigned int[n];
    unsigned int left_index = start;
    unsigned int right_index = pivot;
    unsigned int aux_index = 0;

    while(left_index < pivot && right_index < end){
        if(datas[left_index] < datas[right_index]){
            arr_aux[aux_index] = datas[left_index];
            left_index++;
        }else{
            arr_aux[aux_index] = datas[right_index];
            right_index++;
        }
        aux_index++;
    }

    while(left_index < pivot){
        arr_aux[aux_index] = datas[left_index];
        left_index++;
        aux_index++;
    }

    while(right_index < end){
        arr_aux[aux_index] = datas[right_index];
        right_index++;
        aux_index++;
    }

    for(unsigned int i = 0; i < n; i++){
        datas[start+i] = arr_aux[i];
    }

    delete[] arr_aux;
    return;
}

void merge_sort(std::vector<unsigned int>& datas){
    unsigned int n = datas.size();

    recursive_merge_sort(datas, 0, n);
}

unsigned int get_pivot(std::vector<unsigned int>& datas, unsigned int start, unsigned int end){
    unsigned int first = datas[start];

    unsigned int left_pivot = start+1;
    unsigned int right_pivot = end-1;
    unsigned int aux;
    while(left_pivot < right_pivot){
        while(datas[left_pivot] < first && left_pivot <= right_pivot){
            left_pivot++;
        }
        while(datas[right_pivot] >= first && left_pivot <= right_pivot){
            right_pivot--;
        }
        if(left_pivot <= right_pivot){
            aux = datas[left_pivot];
            datas[left_pivot] = datas[right_pivot];
            datas[right_pivot] = aux;
        }
    }
    
    aux = datas[left_pivot-1];
    datas[left_pivot-1] = datas[start];
    datas[start] = aux;
    return left_pivot-1;
}

void recursive_quick_sort(std::vector<unsigned int>& datas, unsigned int start, unsigned int end){
    unsigned int n = end-start;
    if(n == 2){
        if(datas[start] > datas[start+1]){
            unsigned int aux = datas[start+1];
            datas[start+1] = datas[start];
            datas[start] = aux;
        }
        return;
    }else if(n < 2){
        return;
    }
    
    unsigned int pivot = get_pivot(datas, start, end);
    
    recursive_quick_sort(datas, start, pivot);
    recursive_quick_sort(datas, pivot+1, end);

}

void quick_sort(std::vector<unsigned int>& datas){
    unsigned int n = datas.size();

    recursive_quick_sort(datas, 0, n);
}