import pandas as pd
import matplotlib.pyplot as plt 
import seaborn as sea
import numpy as np
from matplotlib.animation import FuncAnimation 


df = pd.read_csv('cones.csv') 
print(df.head())   
df['z'] = (df['x']+ df['y'])*(0.5)
#sea.displot(data = df, hue = 'color', x = 'x',y ='y', height = 9, aspect= 1,) 
#sea.displot(data = df, color='blue')  
df_blue = df[df['color'] =='blue']
df_yellow = df[df['color'] =='yellow'] 
print(df_blue.head()) 
print(df_yellow.head())
#plt.scatter(df['x'],df['y'],color = df['color'])
#plt.scatter(0,0) 
distance_blue  = ((df_blue['x'][0])**2 +(df_blue['x'[0]])**2)**(0.5)
print(distance_blue) 
print(len(df)) 

#Conclusion Equal number of  blue and yellow cones 
print(len(df_blue))
print(len(df_yellow))  

#Getting the angle 
df['theta'] = np.arctan(df['y']/df['x'])
print(df.head())
print(df.tail())
print(df['theta'].value_counts) 



centre_points = pd.DataFrame({
    'x': (df_blue['x'].values + df_yellow['x'].values) / 2,
    'y': (df_blue['y'].values + df_yellow['y'].values) / 2
})
centre_points.loc[len(centre_points)] = {
    'x': centre_points.iloc[0]['x'],
    'y': centre_points.iloc[0]['y']
}
print(centre_points.tail())

print(centre_points.head()) 

from matplotlib.animation import FuncAnimation

x_c = centre_points['x'].values
y_c = centre_points['y'].values

fig, ax = plt.subplots()
ax.scatter(df['x'], df['y'], c=df['color'], alpha=0.6)
ax.plot(x_c, y_c, color='green', linestyle='--', marker='o', alpha=0.5)
ax.set_aspect('equal')
ax.grid(True)

red_dot, = ax.plot([], [], 'ro', markersize=8)
ax.set_xlim(min(df['x']) - 1, max(df['x']) + 1)
ax.set_ylim(min(df['y']) - 1, max(df['y']) + 1)

def init():
    red_dot.set_data([], [])
    return red_dot,

def update(i):
    red_dot.set_data([x_c[i]], [y_c[i]])  
    return red_dot,

ani = FuncAnimation(fig, update, frames=len(x_c), init_func=init, interval=150, blit=False,)

ani = FuncAnimation(
    fig,
    update,
    frames=len(x_c),
    init_func=init,
    interval=150,
    blit=True
)

ani.save(
    "cones_animation.mp4",
    writer="ffmpeg",
    fps=6,
    dpi=200
)



plt.show()
