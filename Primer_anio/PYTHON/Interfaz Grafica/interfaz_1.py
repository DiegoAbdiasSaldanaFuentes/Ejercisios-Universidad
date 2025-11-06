
import tkinter as tk

def saludo():
    print("¡Hola, mundo!")

ventana = tk.Tk()
ventana.title("Mi Primera intefazzzz!!")

etiqueta = tk.Label(ventana, text="¡Bienvenido a Tkinter!")
etiqueta.pack()

boton = tk.Button(ventana, text="Presioname", command=saludo)
boton.pack()

ventana.mainloop()