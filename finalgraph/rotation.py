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
    plt.xlim(-30, 50)
    plt.ylim(-30, 50)

# Rotation matrix
def rotate(points, angle_degrees):
    theta = np.radians(angle_degrees)
    R = np.array([
        [np.cos(theta), -np.sin(theta)],
        [np.sin(theta),  np.cos(theta)]
    ])
    return points @ R.T

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

rotated = rotate(square, 50)

# Create subplots
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 6))

# Plot original shape
plt.sca(ax1)
draw_shape(square, "Original", 'red')
setup_plot()
plt.title("Before Rotation")

# Plot rotated shape
plt.sca(ax2)
draw_shape(rotated, "Rotated 50°", 'blue')
setup_plot()
plt.title("After Rotation at 50°")

plt.tight_layout()
plt.show()
