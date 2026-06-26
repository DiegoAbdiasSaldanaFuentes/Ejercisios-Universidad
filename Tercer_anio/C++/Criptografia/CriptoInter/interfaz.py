import tkinter as tk
from tkinter import filedialog, messagebox
import subprocess
import time
import os

EJECUTABLES = {
    "AES-256": "aes.exe",
    "ChaCha20": "chacha.exe",
    "RSA": "rsa.exe",
    "ECC": "ecc.exe"
}

def cargar_archivo():
    ruta = filedialog.askopenfilename(title="Seleccionar archivo")
    if ruta:
        try:
            # Leemos en binario primero para evitar el crasheo de UTF-8
            with open(ruta, "rb") as f:
                datos_crudos = f.read()
            
            try:
                # Intentamos leerlo como texto normal
                contenido = datos_crudos.decode("utf-8")
            except UnicodeDecodeError:
                # Si crashea, significa que es un archivo encriptado binario. Lo mostramos como Hexadecimal.
                contenido = datos_crudos.hex()
                
            txt_input.delete(1.0, tk.END)
            txt_input.insert(tk.END, contenido)
        except Exception as e:
            messagebox.showerror("Error", f"No se pudo leer el archivo: {e}")

def ejecutar_criptografia():
    algoritmo = var_algoritmo.get()
    modo = var_modo.get()
    hilos = spin_hilos.get()
    texto_entrada = txt_input.get(1.0, tk.END).strip()

    if not texto_entrada:
        messagebox.showwarning("Advertencia", "Ingresa texto o carga un archivo primero.")
        return

    try:
        if modo == "Encriptar":
            # Guardamos texto normal para que el C/C++ lo encripte
            with open("input.txt", "w", encoding="utf-8") as f:
                f.write(texto_entrada)
        else:
            # Si vamos a desencriptar, la entrada de la UI debería ser Hexadecimal.
            # Lo convertimos a binario real para que el C/C++ lo pueda leer.
            try:
                # Limpiamos espacios o saltos de línea por si acaso
                hex_limpio = texto_entrada.replace(" ", "").replace("\n", "")
                datos_binarios = bytes.fromhex(hex_limpio)
                with open("input.txt", "wb") as f:
                    f.write(datos_binarios)
            except ValueError:
                # Si falla, asumimos que no es hex y lo guardamos como texto normal
                with open("input.txt", "w", encoding="utf-8") as f:
                    f.write(texto_entrada)
                    
    except Exception as e:
        messagebox.showerror("Error de I/O", f"No se pudo escribir input.txt: {e}")
        return

    exe_file = EJECUTABLES[algoritmo]
    if not os.path.exists(exe_file):
        messagebox.showerror("Error", f"No se encontró el ejecutable: {exe_file}\nCompila tu código C/C++ primero.")
        return

    argumento_modo = "-e" if modo == "Encriptar" else "-d"
    tiempo_inicio = time.perf_counter()
    
    try:
        subprocess.run([f"./{exe_file}", argumento_modo, str(hilos)], check=True, capture_output=True, text=True)
        tiempo_fin = time.perf_counter()
        tiempo_total_ms = (tiempo_fin - tiempo_inicio) * 1000

        if os.path.exists("output.txt"):
            if modo == "Encriptar":
                # Al encriptar, el archivo generado es binario. Lo pasamos a Hexadecimal para mostrarlo en Tkinter sin crashear.
                with open("output.txt", "rb") as f:
                    resultado_binario = f.read()
                resultado = resultado_binario.hex()
            else:
                # Al desencriptar, el archivo debería ser texto humano de nuevo.
                with open("output.txt", "rb") as f:
                    resultado_binario = f.read()
                resultado = resultado_binario.decode("utf-8", errors="ignore")
            
            txt_output.config(state=tk.NORMAL)
            txt_output.delete(1.0, tk.END)
            txt_output.insert(tk.END, resultado)
            txt_output.config(state=tk.DISABLED)
            
            lbl_tiempo.config(text=f"Tiempo de ejecución ({algoritmo}): {tiempo_total_ms:.4f} ms", fg="#00ff00")
        else:
            messagebox.showerror("Error", "El ejecutable no generó el archivo 'output.txt'.")

    except subprocess.CalledProcessError as e:
        messagebox.showerror("Error del Algoritmo", f"El programa en C/C++ falló.\nSalida: {e.stderr}")

# --- CONFIGURACIÓN DE LA INTERFAZ ---
ventana = tk.Tk()
ventana.title("Prototipo Criptográfico")
ventana.geometry("600x700")
ventana.configure(bg="#2b2b2b")

var_algoritmo = tk.StringVar(value="AES-256")
var_modo = tk.StringVar(value="Encriptar")

fuente_lbl = ("Helvetica", 10, "bold")
bg_color = "#2b2b2b"
fg_color = "#ffffff"

frame_algos = tk.LabelFrame(ventana, text="1. Seleccionar Algoritmo", bg=bg_color, fg=fg_color, font=fuente_lbl)
frame_algos.pack(fill="x", padx=10, pady=5)
for alg in EJECUTABLES.keys():
    tk.Radiobutton(frame_algos, text=alg, variable=var_algoritmo, value=alg, bg=bg_color, fg=fg_color, selectcolor="#444444").pack(side="left", padx=10)

frame_modo = tk.LabelFrame(ventana, text="2. Seleccionar Acción", bg=bg_color, fg=fg_color, font=fuente_lbl)
frame_modo.pack(fill="x", padx=10, pady=5)
tk.Radiobutton(frame_modo, text="Encriptar (-e)", variable=var_modo, value="Encriptar", bg=bg_color, fg=fg_color, selectcolor="#444444").pack(side="left", padx=10)
tk.Radiobutton(frame_modo, text="Desencriptar (-d)", variable=var_modo, value="Desencriptar", bg=bg_color, fg=fg_color, selectcolor="#444444").pack(side="left", padx=10)

frame_hilos = tk.LabelFrame(ventana, text="3. Configuración de Hilos", bg=bg_color, fg=fg_color, font=fuente_lbl)
frame_hilos.pack(fill="x", padx=10, pady=5)
tk.Label(frame_hilos, text="Cantidad de hilos a usar:", bg=bg_color, fg=fg_color).pack(side="left", padx=10)
spin_hilos = tk.Spinbox(frame_hilos, from_=1, to=64, width=5, font=("Helvetica", 10))
spin_hilos.pack(side="left", padx=10, pady=5)

frame_entrada = tk.Frame(ventana, bg=bg_color)
frame_entrada.pack(fill="both", expand=True, padx=10, pady=5)
tk.Label(frame_entrada, text="4. Texto a procesar:", bg=bg_color, fg=fg_color, font=fuente_lbl).pack(anchor="w")
txt_input = tk.Text(frame_entrada, height=7, bg="#1e1e1e", fg="#ffffff", font=("Consolas", 10))
txt_input.pack(fill="x", pady=5)
tk.Button(frame_entrada, text="Cargar desde archivo (.txt)", command=cargar_archivo, bg="#1f77b4", fg="white").pack(anchor="e")

tk.Button(ventana, text="▶ EJECUTAR", command=ejecutar_criptografia, font=("Helvetica", 12, "bold"), bg="#2ca02c", fg="white", height=2).pack(fill="x", padx=10, pady=10)

frame_salida = tk.Frame(ventana, bg=bg_color)
frame_salida.pack(fill="both", expand=True, padx=10, pady=5)
tk.Label(frame_salida, text="5. Resultado (output.txt):", bg=bg_color, fg=fg_color, font=fuente_lbl).pack(anchor="w")
txt_output = tk.Text(frame_salida, height=7, bg="#1e1e1e", fg="#00ff00", font=("Consolas", 10), state=tk.DISABLED)
txt_output.pack(fill="x", pady=5)

lbl_tiempo = tk.Label(ventana, text="Tiempo de ejecución: -- ms", bg=bg_color, fg="#aaaaaa", font=("Helvetica", 11, "bold"))
lbl_tiempo.pack(pady=5)

ventana.mainloop()