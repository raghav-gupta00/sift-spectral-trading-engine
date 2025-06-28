import matplotlib.pyplot as plt
import csv
import os

# Make sure output dir exists
os.makedirs("../output", exist_ok=True)

spectrum = []
with open("../data_output/output_data.csv", "r") as file:
    reader = csv.reader(file)
    next(reader)  # ✅ skip the header
    for row in reader:
        spectrum.append(float(row[1]))

# Plot half the spectrum
N = len(spectrum)
plt.figure(figsize=(10, 4))
plt.plot(spectrum[:N // 2], color='cyan')
plt.title("FFT Magnitude Spectrum of returns")
plt.xlabel("Frequency Bin")
plt.ylabel("Magnitude")
plt.grid(True)
plt.tight_layout()
plt.savefig("../data_output/spectrum_plot.png")
plt.show()
