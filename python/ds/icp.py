import sys
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import animation, rc 
from math import sin, cos, atan2, pi
from IPython.display import display, Math, Latex, Markdown, HTML


# Source:  https://nbviewer.org/github/niosus/notebooks/blob/master/icp.ipynb
def plot_data(data_1, data_2, label_1, label_2, markersize_1=8, markersize_2=8):
    fig = plt.figure(figsize=(10, 6))
    ax = fig.add_subplot(111)
    ax.axis('equal')
    if data_1 is not None:
        x_p, y_p = data_1
        ax.plot(x_p, y_p, color='#336699', markersize=markersize_1, marker='o', linestyle=":", label=label_1)
    if data_2 is not None:
        x_q, y_q = data_2
        ax.plot(x_q, y_q, color='orangered', markersize=markersize_2, marker='o', linestyle=":", label=label_2)
    ax.legend()
    return ax

def plot_values(values, label):
    fig = plt.figure(figsize=(10, 4))
    ax = fig.add_subplot(111)
    ax.plot(values, label=label)
    ax.legend()
    ax.grid(True)
    plt.show()
    
def animate_results(P_values, Q, corresp_values, xlim, ylim, correspondences):
    """A function used to animate the iterative processes we use."""
    fig = plt.figure(figsize=(10, 6))
    anim_ax = fig.add_subplot(111)
    anim_ax.set(xlim=xlim, ylim=ylim)
    anim_ax.set_aspect('equal')
    plt.close()
    x_q, y_q = Q
    # draw initial correspondeces
    corresp_lines = []
    for i, j in correspondences:
        corresp_lines.append(anim_ax.plot([], [], 'grey')[0])
    # Prepare Q data.
    Q_line, = anim_ax.plot(x_q, y_q, 'o', color='orangered')
    # prepare empty line for moved data
    P_line, = anim_ax.plot([], [], 'o', color='#336699')

    def animate(i):
        P_inc = P_values[i]
        x_p, y_p = P_inc
        P_line.set_data(x_p, y_p)
        draw_inc_corresp(P_inc, Q, corresp_values[i])
        return (P_line,)
    
    def draw_inc_corresp(points_from, points_to, correspondences):
        for corr_idx, (i, j) in enumerate(correspondences):
            x = [points_from[0, i], points_to[0, j]]
            y = [points_from[1, i], points_to[1, j]]
            corresp_lines[corr_idx].set_data(x, y)
    
    anim = animation.FuncAnimation(fig, animate,
                                   frames=len(P_values), 
                                   interval=500, 
                                   blit=True)
    return HTML(anim.to_jshtml())

# End of display configuration


# initialize pertrubation rotation
angle = pi / 4
R_true = np.array([[cos(angle), -sin(angle)], 
                   [sin(angle),  cos(angle)]])
t_true = np.array([[-2], [5]])

# Generate data as a list of 2d points
num_points = 30
true_data = np.zeros((2, num_points))
true_data[0, :] = range(0, num_points)
true_data[1, :] = 0.2 * true_data[0, :] * np.sin(0.5 * true_data[0, :]) 
# Move the data
moved_data = R_true.dot(true_data) + t_true

# Assign to variables we use in formulas.
Q = true_data
P = moved_data
print(type(P))

plot_data(moved_data, true_data, "P: moved data", "Q: true data")
plt.show()

# Achar pontos correspondentes
def get_correspondece_indices(P :np.ndarray, Q :np.ndarray):
    p_size = P.shape[1]
    q_size = Q.shape[1]
    correspondences = []

    print("\nP: \n")
    print(P)

    for i in range(p_size): # cicle through P points
        p_point = P[: , i]
        min_dist = sys.maxsize # the largest value a variable can store
        chosen_idx = -1 # chosen id starts at -1
        for j in range(q_size): # cicle through Q points
            q_point = Q[: , j]

            dist = np.linalg.norm(q_point - p_point) # distancia entre os pontos
            if dist < min_dist:
                min_dist = dist
                chosen_idx = j
        
        correspondences.append((i, chosen_idx))
    return correspondences

# Q = true_data
# P = moved_data

def draw_correspondences(P, Q, correspondences, ax : plt.Axes):
    label_added = False
    for i, j in correspondences:
        x = [P[0, i], Q[0, j]]
        y = [P[1, i], Q[1, j]]

        if not label_added:
            ax.plot(x,y, color='blue', label='correspondences')
            label_added = True
        else:
            ax.plot(x,y, color='blue')

    ax.legend()
    

# Centralizando as datas (pelo centro de massa)
def center_data(data, exclude_indices=[]):
    reduced_data = np.delete(data, exclude_indices, axis=1)
    center = np.array([reduced_data.mean(axis=1)]).T
    return center, data-center

center_of_P, P_centered = center_data(P)
center_of_Q, Q_centered = center_data(Q)
ax = plot_data(P_centered, Q_centered, label_1='moved centered', label_2='true centered')
plt.show()

correspondences = get_correspondece_indices(P_centered, Q_centered)
ax = plot_data(P_centered, Q_centered, label_1='P centered', label_2='Q centered')

draw_correspondences(P_centered, Q_centered, correspondences, ax)

plt.show()
"""
P = np.zeros((2, 5)) :
array([[0, 0, 0, 0, 0],
       [0, 0, 0, 0, 0]])

portanto: 
P[1, :] -> [0 0 0 0 0]
P[:, 1] -> [0 0]
P[1, :] = range(5) -> [0, 1, 2, 3, 4]
P[1, 2] = 2

>>> P
array([[0., 0., 0., 0., 0.],
       [0., 1., 2., 3., 4.]])

>>> P.mean(axis=1)
array([0., 2.])
>>> P
array([[0., 0., 0., 0., 0.],
       [0., 1., 2., 3., 4.]])
>>> P.mean(axis=0)
array([0. , 0.5, 1. , 1.5, 2. ])

>>> P.T
array([[0., 0.],
       [0., 1.],
       [0., 2.],
       [0., 3.],
       [0., 4.]])

"""