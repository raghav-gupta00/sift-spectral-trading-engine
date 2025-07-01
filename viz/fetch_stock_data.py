import yfinance as yf

# Download daily NVDA prices for the past 1 year
nvda = yf.download("NVDA", start="2024-06-01", end="2025-06-01")

# Save it as a CSV file
nvda.to_csv("../data/nvda_data.csv")

print("✅ Download complete: saved to ../data/nvda_data.csv")
