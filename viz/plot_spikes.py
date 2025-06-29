import csv
import matplotlib.pyplot as plt

spike_file = "../data_output/spikes.csv"

bins = []
cycle_lengths = []
magnitudes = []

with open(spike_file, "r") as f:
    reader = csv.reader(f)
    next(reader)  # Skip header
    for row in reader:
        bins.append(int(row[0]))
        cycle_lengths.append(float(row[1]))
        magnitudes.append(float(row[2]))

# Bar plot: Magnitude vs Cycle Length
plt.figure(figsize=(10, 6))
plt.bar(cycle_lengths, magnitudes, width=0.8, color='skyblue', edgecolor='black')
plt.xlabel("Cycle Length (in days)")
plt.ylabel("Magnitude")
plt.title("Detected Spectral Spikes")
plt.grid(True)
plt.tight_layout()

plt.savefig("../data_output/spikes_plot.png")
plt.show()
