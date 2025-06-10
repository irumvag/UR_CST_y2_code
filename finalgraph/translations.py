import numpy as np
import matplotlib.pyplot as plt

def draw_shape(points, label="", color='blue'):
    # Close the shape
    closed = np.vstack([points, points[0]])
    plt.plot(closed[:, 0], closed[:, 1], marker='o', label=label, color=color)

def setup_plot():
    plt.axhline(0, color='gray', lw=1)
    plt.axvline(0, color='gray', lw=1)
    plt.grid(True)
    plt.gca().set_aspect('equal', adjustable='box')
    plt.legend()
    plt.xlim(0, 70)
    plt.ylim(-10, 70)
# Original triangle
triangle = np.array([
      [5, 0],
    [5, 15],
    [8, 18],
    [8,25],
    [12,25],
    [12,18],
    [15,15],
    [15,0]
])

# Translation vector
tx, ty = 25,25 
translated = triangle + np.array([tx, ty])
line1=0
# Create subplots
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 6))

# Plot original shape
plt.sca(ax1)
draw_shape(triangle, "Original", 'blue')
setup_plot()
plt.title("Before Translation")
plt.xlabel("X-axis")
plt.ylabel("Y-axis")

# Plot translated shape
plt.sca(ax2)
draw_shape(translated, "Translated", 'red')
setup_plot()
plt.title("After Translation at (25,25)")
plt.xlabel("X-axis")
plt.ylabel("Y-axis")

plt.tight_layout()
plt.show()
