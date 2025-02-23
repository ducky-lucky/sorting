import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

def get_graphics(df, size, title, figname, quick_sort = False):
    fig, ax = plt.subplots()
    ax.plot(size, df["Merge Sort"], label="Merge Sort")
    ax.plot(size, df["Standar Sort"], label="Standar Sort")
    if quick_sort:
        ax.plot(size, df["Quick Sort"], label="Quick Sort")

    ax.set(ylabel="Time [ms]", xlabel="Dataset Size (x10$^6$)", title=title, ylim=[0,1100])
    ax.grid()
    ax.legend()

    plt.savefig(figname)

filename = "results_xl.csv"
df = pd.read_csv(filename)

random = df[df["Type"] == "random"]
size = np.array(random["Size"]) / 1000000
get_graphics(random, size, "Random datasets", "xl_random.png", True)

sorted = df[df["Type"] == "sorted"]
get_graphics(sorted, size, "Sorted datasets", "xl_sorted.png")

inverted = df[df["Type"] == "inverted"]
get_graphics(inverted, size, "Inverted datasets", "xl_inverted.png")

same = df[df["Type"] == "same"]
get_graphics(same, size, "Same datasets", "xl_same.png")

random2 = df[df["Type"] == "random2"]
get_graphics(random2, size, "Random 2 datasets", "xl_random2.png", True)