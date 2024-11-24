import matplotlib.pyplot as plt
import numpy as np

exact_area = 0.944517
step = 500
start_points = 100
max_points = 100000

with open("data.txt", "r") as file:
    estimated_areas = [float(line.strip()) for line in file]

points = np.arange(start_points, max_points, step)

relative_errors = [(abs(area - exact_area) / exact_area) * 100 for area in estimated_areas]

plt.figure(figsize=(10, 6))
plt.plot(points, estimated_areas, label="Приближённая площадь", color="blue")
plt.axhline(y=exact_area, color="red", linestyle="--", label="Точная площадь")
plt.xlabel("Количество точек")
plt.ylabel("Площадь")
plt.title("Изменение приближённого значения площади")
plt.legend()
plt.grid(True)
plt.show()

plt.figure(figsize=(10, 6))
plt.plot(points, relative_errors, label="Относительное отклонение (%)", color="green")
plt.axhline(y=0, color="red", linestyle="--", label="Нулевое отклонение")
plt.xlabel("Количество точек")
plt.ylabel("Отклонение (%)")
plt.title("Изменение относительного отклонения приближённой площади")
plt.legend()
plt.grid(True)
plt.show()
