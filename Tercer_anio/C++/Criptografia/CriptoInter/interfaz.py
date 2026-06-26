import tkinter as tk
from tkinter import filedialog, messagebox
import subprocess
import time
import os
import shutil  # Importante para copiar el archivo rápidamente

EJECUTABLES = {
    "AES-256": "aes.exe",
    "ChaCha20": "chacha.exe",
    "RSA": "rsa.exe",
    "ECC": "ecc.exe"
}

# Variable global para rastrear si vamos a procesar un archivo en lugar de texto manual
ruta_archivo_cargado = None

def al_modificar_texto(event):
    """Si el usuario escribe algo a mano en el cuadro, desvinculamos el archivo cargado."""
    global ruta_archivo_cargado
    if ruta_archivo_cargado is not None:
        ruta_archivo_cargado = None

def cargar_archivo():
    global ruta_archivo_cargado
    ruta = filedialog.askopenfilename(title="Seleccionar archivo")
    if ruta:
        try:
            tamano_bytes = os.path.getsize(ruta)
            ruta_archivo_cargado = ruta
            
            # Intentamos contar los caracteres asumiendo que es un archivo de texto
            try:
                with open(ruta, "r", encoding="utf-8") as f:
                    contenido = f.read()
                    cantidad_caracteres = len(contenido)
                    info_tamano = f"Caracteres: {cantidad_caracteres} (Tamaño en disco: {tamano_bytes} bytes)"
            except UnicodeDecodeError:
                # Si falla, es porque es un archivo binario (ej. ya encriptado)
                info_tamano = f"Tamaño en disco: {tamano_bytes} bytes (Archivo binario / encriptado)"

            txt_input.delete(1.0, tk.END)
            mensaje = (f"--- ARCHIVO SELECCIONADO ---\n"
                       f"Ruta: {ruta}\n"
                       f"{info_tamano}\n\n"
                       f"(Para optimizar el rendimiento, el contenido no se muestra.\n"
                       f"Se procesará directamente al ejecutar.)")
            txt_input.insert(tk.END, mensaje)
        except Exception as e:
            messagebox.showerror("Error", f"No se pudo acceder al archivo: {e}")
def ejecutar_criptografia():
    global ruta_archivo_cargado
    algoritmo = var_algoritmo.get()
    modo = var_modo.get()
    hilos = spin_hilos.get()
    texto_entrada = txt_input.get(1.0, tk.END).strip()

    if not ruta_archivo_cargado and not texto_entrada:
        messagebox.showwarning("Advertencia", "Ingresa texto o carga un archivo primero.")
        return

    try:
        if ruta_archivo_cargado:
            # Si se cargó un archivo, evitamos la UI y lo copiamos directamente a input.txt
            shutil.copy2(ruta_archivo_cargado, "input.txt")
        else:
            # Lógica para texto ingresado manualmente
            if modo == "Encriptar":
                with open("input.txt", "w", encoding="utf-8") as f:
                    f.write(texto_entrada)
            else:
                try:
                    hex_limpio = texto_entrada.replace(" ", "").replace("\n", "")
                    datos_binarios = bytes.fromhex(hex_limpio)
                    with open("input.txt", "wb") as f:
                        f.write(datos_binarios)
                except ValueError:
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
            tamano_out = os.path.getsize("output.txt")
            
            # Leer únicamente un fragmento del output (150 bytes) para no colapsar la UI
            with open("output.txt", "rb") as f:
                resultado_binario = f.read(150)
            
            if modo == "Encriptar":
                preview = resultado_binario.hex()
            else:
                preview = resultado_binario.decode("utf-8", errors="ignore")
            
            # Informar al usuario sin sobrecargar el Textbox
            mensaje_salida = (f"--- PROCESO COMPLETADO ---\n"
                              f"Se generó 'output.txt' ({tamano_out} bytes).\n\n"
                              f"Vista previa (primeros bytes):\n{preview}...")
            
            txt_output.config(state=tk.NORMAL)
            txt_output.delete(1.0, tk.END)
            txt_output.insert(tk.END, mensaje_salida)
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

# Evento para detectar si el usuario escribe y resetear el archivo cargado
txt_input.bind("<KeyPress>", al_modificar_texto)

tk.Button(frame_entrada, text="Cargar desde archivo", command=cargar_archivo, bg="#1f77b4", fg="white").pack(anchor="e")

tk.Button(ventana, text="▶ EJECUTAR", command=ejecutar_criptografia, font=("Helvetica", 12, "bold"), bg="#2ca02c", fg="white", height=2).pack(fill="x", padx=10, pady=10)

frame_salida = tk.Frame(ventana, bg=bg_color)
frame_salida.pack(fill="both", expand=True, padx=10, pady=5)
tk.Label(frame_salida, text="5. Resultado (output.txt):", bg=bg_color, fg=fg_color, font=fuente_lbl).pack(anchor="w")
txt_output = tk.Text(frame_salida, height=7, bg="#1e1e1e", fg="#00ff00", font=("Consolas", 10), state=tk.DISABLED)
txt_output.pack(fill="x", pady=5)

lbl_tiempo = tk.Label(ventana, text="Tiempo de ejecución: -- ms", bg=bg_color, fg="#aaaaaa", font=("Helvetica", 11, "bold"))
lbl_tiempo.pack(pady=5)

ventana.mainloop()