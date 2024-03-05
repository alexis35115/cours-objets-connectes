from gpiozero import CPUTemperature
from time import sleep, strftime, time
import matplotlib.pyplot as plt

cpu = CPUTemperature()

plt.ion()
x = []
y = []

with open("/home/pi/cpu_temp.csv", "a") as log:
    while True:
        temp = cpu.temperature
        print(temp)
        
        """
        #Partie 2
        log.write("{0},{1}\n".format(strftime("%Y-%m-%d %H:%M:%S"),str(temp)))
        sleep(1)
        """

        y.append(temp)
        x.append(time())

        plt.clf()
        plt.scatter(x,y)
        plt.plot(x,y)

        plt.pause(1)
        plt.draw()