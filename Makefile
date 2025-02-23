
CPP=g++
FLAGS=-O9 -std=c++17
DEST=.
OBJECTS=functions.o
BINS=generate_random_dataset generate_sorted_dataset generate_inverse_dataset generate_same_dataset generate_rand2_dataset read_dataset selection_sort insertion_sort bubble_sort merge_sort quick_sort standar_sort

%.o: %.c
	$(CPP) $(FLAGS) -c $< -o $@

all: clean bin

bin: $(OBJECTS) $(BINS)

generate_random_dataset:
	$(CPP) $(FLAGS) generate_random_dataset.cpp -o $(DEST)/generate_random_dataset $(OBJECTS)

generate_sorted_dataset:
	$(CPP) $(FLAGS) generate_sorted_dataset.cpp -o $(DEST)/generate_sorted_dataset $(OBJECTS)

generate_inverse_dataset:
	$(CPP) $(FLAGS) generate_inverse_dataset.cpp -o $(DEST)/generate_inverse_dataset $(OBJECTS)

generate_same_dataset:
	$(CPP) $(FLAGS) generate_same_dataset.cpp -o $(DEST)/generate_same_dataset $(OBJECTS)

generate_rand2_dataset:
	$(CPP) $(FLAGS) generate_rand2_dataset.cpp -o $(DEST)/generate_rand2_dataset $(OBJECTS)

read_dataset:
	$(CPP) $(FLAGS) read_dataset.cpp -o $(DEST)/read_dataset $(OBJECTS)

selection_sort:
	$(CPP) $(FLAGS) selection_sort.cpp -o $(DEST)/selection_sort $(OBJECTS)

insertion_sort:
	$(CPP) $(FLAGS) insertion_sort.cpp -o $(DEST)/insertion_sort $(OBJECTS)

bubble_sort:
	$(CPP) $(FLAGS) bubble_sort.cpp -o $(DEST)/bubble_sort $(OBJECTS)

merge_sort:
	$(CPP) $(FLAGS) merge_sort.cpp -o $(DEST)/merge_sort $(OBJECTS)

quick_sort:
	$(CPP) $(FLAGS) quick_sort.cpp -o $(DEST)/quick_sort $(OBJECTS)

standar_sort:
	$(CPP) $(FLAGS) standar_sort.cpp -o $(DEST)/standar_sort $(OBJECTS)

clean:
	rm -f $(OBJECTS) $(BINS)