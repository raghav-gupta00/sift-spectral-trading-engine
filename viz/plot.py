import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.dates as mdates

# Load CSV
df = pd.read_csv("../data_output/trade_signal.csv")

# Parse time
df['time'] = pd.to_datetime(df['time'])

# Create figure
plt.figure(figsize=(15, 6))
plt.plot(df['time'], df['price'], label='Price', color='black')

# Mark BUY and SELL signals
buy_signals = df[df['Trade Signal'] == 'BUY']
sell_signals = df[df['Trade Signal'] == 'SELL']

plt.scatter(buy_signals['time'], buy_signals['price'], color='green', marker='^', label='BUY', s=100)
plt.scatter(sell_signals['time'], sell_signals['price'], color='red', marker='v', label='SELL', s=100)

# Format x-axis as dates
plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%b %d'))
plt.gca().xaxis.set_major_locator(mdates.WeekdayLocator(interval=1))
plt.xticks(rotation=45)

# Decorations
plt.legend()
plt.grid(True)
plt.title("Trade Signals on Price Series")
plt.tight_layout()

# Save the figure
plt.savefig("../data_output/trade_signals_plot.png", dpi=300)

# Show plot
plt.show()
