import matplotlib.pyplot as plt
import numpy as np

def translate(points, tx, ty):
    return points + np.array([tx, ty])

def rotate(points, angle_deg):
    theta = np.radians(angle_deg)
    rot_matrix = np.array([[np.cos(theta), -np.sin(theta)],
                           [np.sin(theta), np.cos(theta)]])
    return points @ rot_matrix.T

def scale(points, sx, sy):
    scale_matrix = np.array([[sx, 0], [0, sy]])
    return points @ scale_matrix.T

# Define a square
square = np.array([[1, 1], [2, 1], [2, 2], [1, 2], [1, 1]])

# Apply transformations
translated = translate(square, 3, 1)
rotated = rotate(square, 45)
scaled = scale(square, 1.5, 0.5)

# Plot all
plt.figure()
plt.plot(square[:, 0], square[:, 1], label='Original')
plt.plot(translated[:, 0], translated[:, 1], label='Translated')
plt.plot(rotated[:, 0], rotated[:, 1], label='Rotated')
plt.plot(scaled[:, 0], scaled[:, 1], label='Scaled')
plt.axis('equal')
plt.legend()
plt.title('2D Transformations with Matplotlib')
plt.show()
