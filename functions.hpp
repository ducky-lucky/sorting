#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>
#include <fstream>
#include <climits>

bool check(std::vector<unsigned int>& datas);
void read_dataset(std::vector<unsigned int>& datas, std::string& filename);
void write_dataset(std::vector<unsigned int>& datas, std::string& filename);
void bubble_sort(std::vector<unsigned int>& datas);
void selection_sort(std::vector<unsigned int>& datas);
void insertion_sort(std::vector<unsigned int>& datas);
void merge_sort(std::vector<unsigned int>& datas);
void quick_sort(std::vector<unsigned int>& datas);

#endif