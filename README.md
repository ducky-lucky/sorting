# Sorting evaluation

Hi! This is my first experimental framework. I implemented some sorting algorithms and I tested them revising the execution time.

The algorithms selected are the following:
- **Bubble Sort**: a basic $O(n^2)$ algorithm.
- **Insertion Sort**: a second $O(n^2)$ algorithm.
- **Selection Sort**: a thrid $O(n^2)$ algorithm.
- **Merge Sort**: a $O(n \log_2 n)$ algorithm that requires $O(n)$ space.
- **Quick Sort**: a $O(n \log_2 n)$ algorithm that for some datasets uses $O(n^2)$ time.
- **Standar Sort**: the $O(n \log_2 n)$ algorithm created by the C++ Standar Library.

### Datasets

I generated synthetic datasets with different distributions. The dataset's types are the following:

- **random**: a dataset with $n$ integers values in the range $[0,n]$, shuffle randomly. The dataset does not have repeated values.
- **random2**: simmilary to **random**, but the the range is $[0,n/2]$ and each value is repeated twice.
- **sorted**: simmilary to **random**, but all values are sorted increasing.
- **inversed**: simmilary to **random**, but all values are sorted decreasing.
- **same**: a a dataset with $n$ integers values in which all values are the same (the value is 0).

For each type, we generated two groups of datasets, for $O(n^2)$ algorithms, and XL for $O(n \log_2 n)$ algorithms. The first group contains 10 datasets of the following size: 10,000, 20,000, 30,000, 40,000, 50,000, 60,000, 70,000, 80,000, 90,000 and 100,000. The second group contains 10 datasets of the following size: 1,000,000, 2,000,000, 3,000,000, 4,000,000, 5,000,000, 6,000,000, 7,000,000, 8,000,000, 9,000,000 and 10,000,000.

## Software required and versions used

- g++: 13.3.0

Python (optional)

- python3 : 3.12.3
- pip: 24.3
- pandas

## How to use it?

For generate our selected datasets, use:

`make`\
`chmod +x generate_datasets.sh`\
`./generate_datasets.sh`

For execute our experimental framework, use:

`make`\
`chmod +x execute.sh`\
`./execute.sh`

For to generate a example dataset, use:

`./generate_<type>_dataset <filename> <size>`

Where `<type>` can be: `random`, `rand2`, `sorted`, `inverse`, or `same`; `<filename>` is the dataset filename and `<size>` is the dataset size.

For to execute a sorting algorithm, use: 

`./<type> <filename> `

Where `<type>` can be: `bubble_sort`, `selection_sort`, `inserted_sort`, `merge_sort`, `quick_sort`, or `standar_sort`; and `<filename>` is the dataset filename.

## Results

In `results` folder, you will find our personal results, including the python scripts for to generate graphics.

Additionally, in `results` folder I included the datasets generated for these results.

## About the developer

- ducky-lucky
- d32747117@gmail.com
- [https://github.com/ducky-lucky](https://github.com/ducky-lucky)

