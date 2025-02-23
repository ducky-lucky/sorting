import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

def get_graphics(df, size, title, figname, quick_sort = False):
    fig, ax = plt.subplots()
    ax.plot(size, df["Bubble Sort"], label="Bubble Sort")
    ax.plot(size, df["Insertion Sort"], label="Insertion Sort")
    ax.plot(size, df["Selection Sort"], label="Selection Sort")
    if quick_sort:
        ax.plot(size, df["Quick Sort"], label="Quick Sort")

    ax.set(ylabel="Time [ms]", xlabel="Dataset Size (x10$^3$)", title=title, ylim=[0,25000])
    ax.grid()
    ax.legend()

    plt.savefig(figname)

filename = "results.csv"
df = pd.read_csv(filename)

random = df[df["Type"] == "random"]
size = np.array(random["Size"]) / 1000
get_graphics(random, size, "Random datasets", "random.png")

sorted = df[df["Type"] == "sorted"]
get_graphics(sorted, size, "Sorted datasets", "sorted.png", True)

inverted = df[df["Type"] == "inverted"]
get_graphics(inverted, size, "Inverted datasets", "inverted.png", True)

same = df[df["Type"] == "same"]
get_graphics(same, size, "Same datasets", "same.png", True)

random2 = df[df["Type"] == "random2"]
get_graphics(random2, size, "Random 2 datasets", "random2.png")