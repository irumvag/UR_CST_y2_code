import numpy as np
import math

def pendulum_system(t, y):
    """Define the system of ODEs for the pendulum"""
    y1, y2 = y
    dy1dt = y2
    dy2dt = -math.sin(y1)
    return np.array([dy1dt, dy2dt])

def rk4_system(f, t0, y0, h, num_steps, verbose=True):
    """RK4 method for systems of ODEs with detailed output"""
    t = t0
    y = np.copy(y0)    
    results = []
    
    if verbose:
        print("\nRUNGE-KUTTA 4th ORDER METHOD FOR SYSTEMS")
        print(f"Initial conditions: t0 = {t0:.4f}, y1 = {y0[0]:.6f}, y2 = {y0[1]:.6f}")
        print(f"Step size h = {h}, Number of steps = {num_steps}\n")
        print("Step\tTime\t\tk1\t\t\tk2\t\t\tk3\t\t\tk4\t\t\ty1\t\t\ty2")
        print("-"*120)
    i=0
    for step in range(num_steps):
        # Compute k1
        k1 = h * f(t, y)
        k1_1 = k1[0]
        k1_2 = k1[1]
        if verbose:  # Only show detailed output for first 3 steps for brevity
            print(f"\nStep {step+1}:")
            print(f"k1_1 = h * f(x{i}, y1_{i}) = {h} * f({t:.4f}, [{y[0]:.6f}]) = [{k1[0]:.6f}]")
            print(f"k1_2 = h * f(x{i}, y2_{i}) = {h} * f({t:.4f}, [{y[1]:.6f}]) = [{k1[1]:.6f}]")
        # Compute k2
        k2 = h * f(t + h/2, y + k1/2)
        k2_1 = k2[0]
        k2_2 = k2[1]
        if verbose:
            print(f"k2_1 = h * f(x{i} + h/2, y1_{i} + k1_1/2) = {h} * f({t + h/2:.4f}, [{y[0] + k1[0]/2:.6f}]) = [{k2[0]:.6f}]")
            print(f"k2_2 = h * f(x{i} + h/2, y2_{i} + k1_2/2) = {h} * f({t + h/2:.4f}, [{y[1] + k1[1]/2:.6f}]) = [{k2[1]:.6f}]")
        # Compute k3
        k3 = h * f(t + h/2, y + k2/2)
        k3_1 = k3[0]
        k3_2 = k3[1]
        if verbose:
            print(f"k3_1 = h * f(x{i} + h/2, y1_{i} + k2_1/2) = {h} * f({t + h/2:.4f}, [{y[0] + k2[0]/2:.6f}]) = [{k3[0]:.6f}]")
            print(f"k3_2 = h * f(x{i} + h/2, y2_{i} + k2_2/2) = {h} * f({t + h/2:.4f}, [{y[1] + k2[1]/2:.6f}]) = [{k3[1]:.6f}]")
        # Compute k3
        
        # Compute k4
        k4 = h * f(t + h, y + k3)
        k4_1 = k4[0]
        k4_2 = k4[1]
        if verbose:
            print(f"k4 = h * f(x{i} + h, y1_{i} + k3_1) = {h} * f({t + h:.4f}, [{y[0] + k3[0]:.6f}]) = [{k4[0]:.6f}]")
            print(f"k4 = h * f(x{i} + h, y2_{i} + k3_2) = {h} * f({t + h:.4f}, [{y[1] + k3[1]:.6f}]) = [{k4[1]:.6f}]")
        
        # Update y
        y1_1 = y + (k1_1 + 2*k2_1 + 2*k3_1 + k4_1) / 6
        y2_2 = y + (k1_2 + 2*k2_2 + 2*k3_2 + k4_2) / 6
        y_new = y + (k1 + 2*k2 + 2*k3 + k4) / 6
        if verbose:
            print(f"y1_{i+1}= y1_{i} + (k1_1 + 2k2_1 + 2k3_1 + k4_1)/6 = [{y[0]:.6f}] + ([{k1_1:.6f} + 2*{k2_1:.6f} + 2*{k3_1:.6f} + {k4_1:.6f}]/6)")
            print(f"      = [{y_new[0]:.6f}]")
            print(f"y2_{i+1}= y2_{i} + (k1_2 + 2k2_2 + 2k3_2 + k4_2)/6 = [{y[1]:.6f}] + ([{k1_2:.6f} + 2*{k2_2:.6f} + 2*{k3_2:.6f} + {k4_2:.6f}]/6)")
            print(f"      = [{y_new[1]:.6f}]")
        
        # Update t
        t_new = t + h
        
        # Store results
        results.append([t, y[0], y[1], k1[0], k1[1], k2[0], k2[1], k3[0], k3[1], k4[0], k4[1]])
        
        # Prepare for next step
        t = t_new
        y = y_new
        
        if verbose:
            if step < 21:
                print(f"\nResults after step {step+1}: t = {t:.4f}, y1 = {y[0]:.6f}, y2 = {y[1]:.6f}")
                print("-"*120)
            else:
                print(f"{step+1}\t{t:.4f}\t...\t...\t...\t...\t{y[0]:.6f}\t{y[1]:.6f}")
        i=i+1
    
    return np.array(results)

# Parameters
t0 = math.pi
y0 = np.array([0.0, 1.0])  # y(π)=0, y'(π)=1
h = 0.2
num_steps = 20

# Solve the system
results = rk4_system(pendulum_system, t0, y0, h, num_steps)

# Print final table
print("\n\nFULL RESULTS TABLE:")
print("Step\tTime\t\ty1 (angle)\ty2 (velocity)")
print("-"*50)
for i, row in enumerate(results):
    print(f"{i+1}\t{row[0]:.4f}\t{row[1]:.6f}\t{row[2]:.6f}")

# For plotting (optional)
import matplotlib.pyplot as plt
plt.figure(figsize=(12, 5))

# Angle vs Time
plt.subplot(1, 2, 1)
plt.plot(results[:, 0], results[:, 1], 'b-o')
plt.xlabel('Time')
plt.ylabel('Angle y1')
plt.title('Pendulum Angle vs Time')

# Phase portrait (y2 vs y1)
plt.figure(figsize=(6, 5))
plt.plot(results[:, 1], results[:, 2], 'r-o')
plt.xlabel('Angle y1')
plt.ylabel('Angular velocity y2')
plt.title('Phase Portrait')
plt.tight_layout()
plt.show()
plt.plot(results[:, 1], results[:, 2], 'r-o')
plt.xlabel('Angle y1')
plt.ylabel('Angular velocity y2')
plt.title('Phase Portrait')

plt.tight_layout()
plt.show()