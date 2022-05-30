import matplotlib.animation as animation
import matplotlib.pyplot as plt
import itertools
import keyboard
import pandas as pd
import serial
import sys

# Inicializamos puerto serie
serial_port = '/dev/cu.usbmodem14101'
ser = serial.Serial(serial_port, timeout=1)
ser.reset_input_buffer()


def animate():
    i = 0
    counter = itertools.count()  #Contador

    while True:
        data_reader = ser.readline().decode() #Lectura de los datos

        if i < 10: # Tiempo de inicialización
            i += 1
            continue

        t = next(counter)
        list_data = data_reader.replace("\r\n", "").split(",")
        x = float(list_data[1])
        y = float(list_data[2])
        z = float(list_data[3])

        g_x = float(list_data[5])
        g_y = float(list_data[6])
        g_z = float(list_data[7])

        yield t, x, y, z, g_x, g_y, g_z


def run(data):
    t, x, y, z, g_x, g_y, g_z = data
    t_list.append(t)
    x_list.append(x)
    y_list.append(y)
    z_list.append(z)

    g_x_list.append(g_x)
    g_y_list.append(g_y)
    g_z_list.append(g_z)

    line_x.set_data(t_list[-plot_length:], x_list[-plot_length:])
    line_y.set_data(t_list[-plot_length:], y_list[-plot_length:])
    line_z.set_data(t_list[-plot_length:], z_list[-plot_length:])

    line_g_x.set_data(t_list[-plot_length:], g_x_list[-plot_length:])
    line_g_y.set_data(t_list[-plot_length:], g_y_list[-plot_length:])
    line_g_z.set_data(t_list[-plot_length:], g_z_list[-plot_length:])

    if t > plot_length:
        lim = ax.set_xlim(t - plot_length, t)
    else:
        lim = ax.set_xlim(0, plot_length)

    return line_x, line_y, line_z, line_g_x, line_g_y, line_g_z


def save_tocsv():

    path = "./extracts"
    filename = f"{path}/extract{saved_t}_{end_t}.csv"

    df = pd.DataFrame({"t": t_list[saved_t:end_t],
                       "x": x_list[saved_t:end_t],
                       "y": y_list[saved_t:end_t],
                       "z": z_list[saved_t:end_t],
                       "g_x": g_x_list[saved_t:end_t],
                       "g_y": g_y_list[saved_t:end_t],
                       "g_z": g_z_list[saved_t:end_t]
                       })

    df.to_csv(filename, index=False)
    print("Saved file")


def keyboard_pres(event):
    global saved_t, end_t

    if event.name == "f":
        saved_t = len(t_list)
        print("saving time ", saved_t)
    elif event.name == "j":
        end_t = len(t_list)
        print("Saving to .csv file from ", saved_t, " to ", end_t)
        save_tocsv()
    elif event.name == "q":
        sys.exit()


if __name__ == '__main__':
    fig, ax = plt.subplots()  # Setup figure and axis
    line_x, = ax.plot([], [], color="r", lw=1)  # Setup line
    line_y, = ax.plot([], [], color="b", lw=1)  # Setup line
    line_z, = ax.plot([], [], color="g", lw=1)  # Setup line

    line_g_x, = ax.plot([], [], color="purple", lw=1)  # Setup line
    line_g_y, = ax.plot([], [], color="brown", lw=1)  # Setup line
    line_g_z, = ax.plot([], [], color="orange", lw=1)  # Setup line

    global plot_length
    plot_length = 100
    ax.set_ylim(-200, 200)  # Set limitation in y
    ax.set_xlim(0, plot_length)  # Set limitation in x
    ax.grid()  # Create grid

    global x_list, y_list, z_list, t_list, g_x_list, g_y_list, g_z_list, saved_t

    x_list = []
    y_list = []
    z_list = []
    t_list = []

    g_x_list = []
    g_y_list = []
    g_z_list = []

    saved_t = 0

    keyboard.on_press(keyboard_pres)

    ani = animation.FuncAnimation(fig, run, frames=animate(), blit=False, interval=10)
    plt.show()
