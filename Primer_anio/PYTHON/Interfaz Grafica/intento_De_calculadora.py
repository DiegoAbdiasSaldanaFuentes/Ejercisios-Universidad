#Hecho por Perplexity


import tkinter as tk

# Función para manejar clics
def on_click(boton):
    if boton == 'C':
        entrada.delete(0, tk.END)  # Limpia la entrada
    elif boton == '=':
        try:
            resultado = eval(entrada.get())  # Evalúa la expresión
            entrada.delete(0, tk.END)  # Limpia la entrada
            entrada.insert(0, str(resultado))  # Muestra el resultado
        except:
            entrada.delete(0, tk.END)
            entrada.insert(0, "Error")  # Muestra error en caso de excepción
    else:
        entrada.insert(tk.END, boton)  # Agrega el botón presionado a la entrada

# Crear la ventana principal
ventana = tk.Tk()
ventana.title("Calculadora")

# Crear un campo de entrada
# Width es el  ancho
# Font es el tamaño donde se veran los numeros
# Borderwidth añade un borde donde ingresas los numeros
entrada = tk.Entry(ventana, width=16, font=('Arial', 24), borderwidth=9, relief='ridge')
# row si se pone otro numero que no sea 0 no se vera
entrada.grid(row=0, column=0, columnspan=4)

# Crear botones
#el orden de la lista es igual a la interfaz, quizas aqui se hacen las pociones; si, si se cambia un numero  cambia la interfaz y el resultado
botones = [
    '7', '8', '9', '/',
    '4', '5', '6', '*',
    '1', '2', '3', '-',
    '0', 'C', '=', '+'
]

fila = 1
col = 0

for boton in botones:
    tk.Button(ventana, text=boton, width=5, height=2, font=('Arial', 18),
              command=lambda b=boton: on_click(b)).grid(row=fila, column=col)
    col += 1
    if col > 3:
        col = 0
        fila += 1

# Iniciar el bucle principal
ventana.mainloop()