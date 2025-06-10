import numpy as np
import matplotlib.pyplot as plt

def draw_shape(points, label="", color='blue'):
    closed = np.vstack([points, points[0]])  # Close the shape
    plt.plot(closed[:, 0], closed[:, 1], marker='o', label=label, color=color)

def setup_plot():
    plt.axhline(0, color='gray', lw=1)
    plt.axvline(0, color='gray', lw=1)
    plt.grid(True)
    plt.gca().set_aspect('equal', adjustable='box')
    plt.legend()
    plt.xlim(0, 30)
    plt.ylim(-10, 30)

# Define a triangle
square = np.array([
      [5, 0],
    [5, 15],
    [8, 18],
    [8,25],
    [12,25],
    [12,18],
    [15,15],
    [15,0]
])

# Apply scaling (double width, double height)
scale_factors = [1]
scaled = square * scale_factors

# Create subplots
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 6))

# Plot original shape
plt.sca(ax1)
draw_shape(square, "Original Square", 'blue')
setup_plot()
plt.title("Before Scaling")
plt.xlabel("X-axis")
plt.ylabel("Y-axis")

# Plot scaled shape
plt.sca(ax2)
draw_shape(scaled, "Scaled Square 0.5", 'orange')
setup_plot()
plt.title("After Scaling with 0.5  --")
plt.xlabel("X-axis")
plt.ylabel("Y-axis")

plt.tight_layout()
plt.show()
