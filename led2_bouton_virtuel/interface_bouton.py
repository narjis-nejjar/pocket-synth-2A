import tkinter as tk
import serial
import time


stm32 = serial.Serial(
    port="COM9",
    baudrate=115200,
    timeout=1
)

time.sleep(2)


# 🔥 fonction envoi propre
def envoyer(cmd):
    stm32.write((cmd + "\n").encode())
    stm32.flush()   # IMPORTANT pour éviter blocage


def allumer_led():
    envoyer("ON")
    label_status.config(text="LED allumée")


def eteindre_led():
    envoyer("OFF")
    label_status.config(text="LED éteinte")


# GUI
fenetre = tk.Tk()
fenetre.title("Commande LED STM32")
fenetre.geometry("400x300")


tk.Label(fenetre, text="Contrôle LED LD2 STM32", font=("Arial", 18)).pack(pady=20)


tk.Button(
    fenetre,
    text="💡 Allumer LED",
    font=("Arial", 14),
    width=20,
    height=2,
    command=allumer_led
).pack(pady=10)


tk.Button(
    fenetre,
    text="Éteindre LED",
    font=("Arial", 14),
    width=20,
    height=2,
    command=eteindre_led
).pack(pady=10)


label_status = tk.Label(fenetre, text="LED inconnue", font=("Arial", 12))
label_status.pack(pady=20)


fenetre.mainloop()

stm32.close()