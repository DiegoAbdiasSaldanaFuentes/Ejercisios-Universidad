import tkinter as tk
from tkinter import filedialog, messagebox
import subprocess
import time
import os
import shutil

EJECUTABLES = {
    "aes_test": "aes.exe",
    "chacha_test": "chacha.exe",
    "rsa_test": "rsa.exe",
    "ecc_test": "ecc.exe"
}

ruta_archivo_cargado = None

def al_modificar_texto(event):
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
            try:
                with open(ruta, "r", encoding="utf-8") as f:
                    contenido = f.read()
                    cantidad_caracteres = len(contenido)
                    info_tamano = f"Caracteres: {cantidad_caracteres} (Tamaño en disco: {tamano_bytes} bytes)"
            except UnicodeDecodeError:
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

def toggle_clave():
    if var_tipo_clave.get() == "Personalizada":
        entry_clave.config(state=tk.NORMAL)
    else:
        entry_clave.delete(0, tk.END)
        entry_clave.config(state=tk.DISABLED)

def ejecutar_criptografia():
    global ruta_archivo_cargado
    algoritmo = var_algoritmo.get()
    modo = var_modo.get()
    hilos = spin_hilos.get()
    texto_entrada = txt_input.get(1.0, tk.END).strip()
    
    if var_tipo_clave.get() == "Personalizada":
        clave_final = entry_clave.get().strip()
        if not clave_final:
            messagebox.showwarning("Advertencia", "Ingresa una clave personalizada o selecciona Predeterminada.")
            return
    else:
        clave_final = "123456"

    if not ruta_archivo_cargado and not texto_entrada:
        messagebox.showwarning("Advertencia", "Ingresa texto o carga un archivo primero.")
        return

    # Bloqueo de archivos extremadamente pesados para evitar cuelgues
    if ruta_archivo_cargado and os.path.getsize(ruta_archivo_cargado) > 50000000:
        messagebox.showwarning("Advertencia", "El archivo supera los 50MB. Riesgo de cuelgue.")
        return

    try:
        if ruta_archivo_cargado:
            shutil.copy2(ruta_archivo_cargado, "input.txt")
        else:
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
        messagebox.showerror("Error", f"No se encontró el ejecutable: {exe_file}")
        return

    argumento_modo = "-e" if modo == "Encriptar" else "-d"
    tiempo_inicio = time.perf_counter()
    
    try:
        # Se envía la clave como cuarto argumento y se aplica un freno de 10 segundos
        subprocess.run([f"./{exe_file}", argumento_modo, str(hilos), clave_final], check=True, capture_output=True, text=True, timeout=10)
        tiempo_fin = time.perf_counter()
        tiempo_total_ms = (tiempo_fin - tiempo_inicio) * 1000

        if os.path.exists("output.txt"):
            tamano_out = os.path.getsize("output.txt")
            with open("output.txt", "rb") as f:
                resultado_binario = f.read(150)
            
            if modo == "Encriptar":
                preview = resultado_binario.hex()
            else:
                preview = resultado_binario.decode("utf-8", errors="ignore")
            
            mensaje_salida = (f"--- PROCESO COMPLETADO ---\n"
                              f"Se generó 'output.txt' ({tamano_out} bytes).\n\n"
                              f"Vista previa:\n{preview}...")
            
            txt_output.config(state=tk.NORMAL)
            txt_output.delete(1.0, tk.END)
            txt_output.insert(tk.END, mensaje_salida)
            txt_output.config(state=tk.DISABLED)
            lbl_tiempo.config(text=f"Tiempo de ejecución ({algoritmo}): {tiempo_total_ms:.4f} ms", fg="#00ff00")
        else:
            messagebox.showerror("Error", "El ejecutable no generó 'output.txt'.")
            
    except subprocess.TimeoutExpired:
        messagebox.showerror("Freno de Seguridad", "El cálculo sobrepasó el límite de tiempo de 10 segundos y fue abortado por la interfaz para evitar que la laptop se trabe.")
    except subprocess.CalledProcessError as e:
        messagebox.showerror("Error del Algoritmo", f"El programa falló. Verifica si la clave es válida para este algoritmo.\nSalida: {e.stderr}")

ventana = tk.Tk()
ventana.title("Prototipo Criptográfico")
ventana.geometry("600x800")
ventana.configure(bg="#2b2b2b")

var_algoritmo = tk.StringVar(value="AES-256")
var_modo = tk.StringVar(value="Encriptar")
var_tipo_clave = tk.StringVar(value="Predeterminada")

fuente_lbl = ("Helvetica", 10, "bold")
bg_color = "#2b2b2b"
fg_color = "#ffffff"

frame_algos = tk.LabelFrame(ventana, text="1. Algoritmo", bg=bg_color, fg=fg_color, font=fuente_lbl)
frame_algos.pack(fill="x", padx=10, pady=5)
for alg in EJECUTABLES.keys():
    tk.Radiobutton(frame_algos, text=alg, variable=var_algoritmo, value=alg, bg=bg_color, fg=fg_color, selectcolor="#444444").pack(side="left", padx=10)

frame_modo = tk.LabelFrame(ventana, text="2. Acción", bg=bg_color, fg=fg_color, font=fuente_lbl)
frame_modo.pack(fill="x", padx=10, pady=5)
tk.Radiobutton(frame_modo, text="Encriptar (-e)", variable=var_modo, value="Encriptar", bg=bg_color, fg=fg_color, selectcolor="#444444").pack(side="left", padx=10)
tk.Radiobutton(frame_modo, text="Desencriptar (-d)", variable=var_modo, value="Desencriptar", bg=bg_color, fg=fg_color, selectcolor="#444444").pack(side="left", padx=10)

frame_clave = tk.LabelFrame(ventana, text="3. Configuración de Clave", bg=bg_color, fg=fg_color, font=fuente_lbl)
frame_clave.pack(fill="x", padx=10, pady=5)
tk.Radiobutton(frame_clave, text="Predeterminada", variable=var_tipo_clave, value="Predeterminada", command=toggle_clave, bg=bg_color, fg=fg_color, selectcolor="#444444").pack(side="left", padx=10)
tk.Radiobutton(frame_clave, text="Personalizada", variable=var_tipo_clave, value="Personalizada", command=toggle_clave, bg=bg_color, fg=fg_color, selectcolor="#444444").pack(side="left", padx=10)
entry_clave = tk.Entry(frame_clave, bg="#1e1e1e", fg="#ffffff", state=tk.DISABLED)
entry_clave.pack(side="left", padx=10, fill="x", expand=True)

frame_hilos = tk.LabelFrame(ventana, text="4. Hilos", bg=bg_color, fg=fg_color, font=fuente_lbl)
frame_hilos.pack(fill="x", padx=10, pady=5)
tk.Label(frame_hilos, text="Cantidad:", bg=bg_color, fg=fg_color).pack(side="left", padx=10)
spin_hilos = tk.Spinbox(frame_hilos, from_=1, to=64, width=5)
spin_hilos.pack(side="left", padx=10, pady=5)

frame_entrada = tk.Frame(ventana, bg=bg_color)
frame_entrada.pack(fill="both", expand=True, padx=10, pady=5)
tk.Label(frame_entrada, text="5. Texto:", bg=bg_color, fg=fg_color, font=fuente_lbl).pack(anchor="w")
txt_input = tk.Text(frame_entrada, height=7, bg="#1e1e1e", fg="#ffffff")
txt_input.pack(fill="x", pady=5)
txt_input.bind("<KeyPress>", al_modificar_texto)
tk.Button(frame_entrada, text="Cargar Archivo", command=cargar_archivo, bg="#1f77b4", fg="white").pack(anchor="e")

tk.Button(ventana, text="▶ EJECUTAR", command=ejecutar_criptografia, font=("Helvetica", 12, "bold"), bg="#2ca02c", fg="white").pack(fill="x", padx=10, pady=10)

frame_salida = tk.Frame(ventana, bg=bg_color)
frame_salida.pack(fill="both", expand=True, padx=10, pady=5)
tk.Label(frame_salida, text="6. Resultado:", bg=bg_color, fg=fg_color, font=fuente_lbl).pack(anchor="w")
txt_output = tk.Text(frame_salida, height=7, bg="#1e1e1e", fg="#00ff00", state=tk.DISABLED)
txt_output.pack(fill="x", pady=5)
lbl_tiempo = tk.Label(ventana, text="Tiempo: -- ms", bg=bg_color, fg="#aaaaaa", font=("Helvetica", 11, "bold"))
lbl_tiempo.pack(pady=5)

ventana.mainloop()