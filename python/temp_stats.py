# Python file to extrapolate temperature readings

with open("temperature_feed.csv", "r") as file:
    lines = file.readlines()

temperatures = []

for i in range(1, len(lines)):
    line = lines[i].strip()
    if line == "":
        continue

    parts = line.split(",")

    if len(parts) > 1:
        temp_str = parts[1].strip()
        try:
            temp = float(temp_str)
            temperatures.append(temp)
        except:
            pass

if len(temperatures) > 0:
    min_temp = temperatures[0]
    max_temp = temperatures[0]
    total = 0.0

    for temp in temperatures:
        if temp < min_temp:
            min_temp = temp
        if temp > max_temp:
            max_temp = temp
        total += temp

    avg_temp = total / len(temperatures)

    print("temperature Report")
    print("------------------")
    print("Minimum Temperature:", min_temp)
    print("Maximum Temperature:", max_temp)
    print("Average Temperature:", avg_temp)
else:
    print("No temperature data found.")
