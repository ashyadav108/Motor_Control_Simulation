import matplotlib.pyplot as plt
import csv

steps = []
speed = []

with open('output.csv') as file:
    reader = csv.DictReader(file)
    for row in reader:
        steps.append(int(row['Step']))
        speed.append(float(row['Speed']))

# Setpoint line
setpoint = [100]*len(steps)

plt.plot(steps, speed, label="Motor Speed")
plt.plot(steps, setpoint, linestyle='--', label="Setpoint")

plt.xlabel("Time Step")
plt.ylabel("Speed")
plt.title("DC Motor PID Response")

plt.legend()
plt.grid()

plt.show()