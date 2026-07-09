import customtkinter as ctk
import tkinter as tk
from tkinter import messagebox, filedialog
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg, NavigationToolbar2Tk
import numpy as np
import sympy as sp

# ==========================================
# CLASE AUXILIAR: TOOLTIPS (Para Criterio 2)
# ==========================================
class ToolTip:
    def __init__(self, widget, text):
        self.widget = widget
        self.text = text
        self.tooltip_window = None
        self.widget.bind("<Enter>", self.show_tooltip)
        self.widget.bind("<Leave>", self.hide_tooltip)

    def show_tooltip(self, event=None):
        x = self.widget.winfo_rootx() + 25
        y = self.widget.winfo_rooty() + 25
        self.tooltip_window = tk.Toplevel(self.widget)
        self.tooltip_window.wm_overrideredirect(True)
        self.tooltip_window.wm_geometry(f"+{x}+{y}")
        label = tk.Label(self.tooltip_window, text=self.text, background="#ffffe0", 
                         relief="solid", borderwidth=1, font=("Arial", 10))
        label.pack(ipadx=3, ipady=1)

    def hide_tooltip(self, event=None):
        if self.tooltip_window:
            self.tooltip_window.destroy()
            self.tooltip_window = None

# ==========================================
# BLOQUE 1: MOTOR MATEMÁTICO
# ==========================================
class CalculadoraRiemann:
    def __init__(self):
        self.x = sp.Symbol('x')
        # SINTAXIS AMIGABLE (Criterio 1): Soporta In, ln, sen, e, pi
        self.diccionario_reemplazos = {'sen': 'sin', 'ln': 'log', 'In': 'log', 'e': 'E', 'pi': 'pi'}

    def traducir_texto(self, texto):
        try:
            # Reemplazar el símbolo de intercalación por potencia de Python (Criterio 1)
            texto = texto.replace('^', '**')
            for es, en in self.diccionario_reemplazos.items():
                texto = texto.replace(es, en)
            return sp.sympify(texto)
        except Exception as e:
            raise ValueError(f"Sintaxis inválida. Verifique la función ingresada.")

    def evaluar(self, formula, a, b, n, calcular_area_real=False):
        f_num = sp.lambdify(self.x, formula, 'numpy')
        ancho_dx = (b - a) / n
        
        # Puntos X
        x_izq = np.linspace(a, b - ancho_dx, n)
        x_der = np.linspace(a + ancho_dx, b, n)
        x_medio = (x_izq + x_der) / 2
        
        # Evaluar en Y
        y_izq = f_num(x_izq)
        y_der = f_num(x_der)
        y_medio = f_num(x_medio)

        # CÁLCULO DE ÁREA REAL (Novedad 1)
        if calcular_area_real:
            y_izq, y_der, y_medio = np.abs(y_izq), np.abs(y_der), np.abs(y_medio)
            int_exacta = sp.integrate(sp.Abs(formula), (self.x, a, b)).evalf()
        else:
            int_exacta = sp.integrate(formula, (self.x, a, b)).evalf()
            
        # Sumas
        suma_izq = np.sum(y_izq) * ancho_dx
        suma_der = np.sum(y_der) * ancho_dx
        suma_medio = np.sum(y_medio) * ancho_dx
        
        # Alerta de valores negativos
        hay_negativos = np.any(y_izq < 0) or np.any(y_der < 0)
        
        return {
            'sum_izq': suma_izq, 'sum_der': suma_der, 'sum_med': suma_medio,
            'x_izq': x_izq, 'y_izq': y_izq,
            'x_der': x_der, 'y_der': y_der,
            'x_med': x_medio, 'y_med': y_medio,
            'exacta': float(int_exacta), 'dx': ancho_dx,
            'alerta_negativo': hay_negativos, 'f_num': f_num,
            'area_real_activa': calcular_area_real
        }

# ==========================================
# BLOQUE 2: INTERFAZ DE USUARIO (GUI)
# ==========================================
class AppVisualizador(ctk.CTk):
    def __init__(self):
        super().__init__()
        self.title("Visualizador Suma de Riemann - Proyecto Final")
        self.geometry("1200x750")
        ctk.set_appearance_mode("Dark")
        ctk.set_default_color_theme("blue")
        
        self.calculadora = CalculadoraRiemann()
        self.configurar_interfaz()

    def configurar_interfaz(self):
        # --- PANEL IZQUIERDO SCROLLABLE (Evita que se corten opciones) ---
        self.panel_izq = ctk.CTkScrollableFrame(self, width=320)
        self.panel_izq.pack(side="left", fill="y", padx=10, pady=10)
        
        ctk.CTkLabel(self.panel_izq, text="Parámetros", font=("Arial", 20, "bold")).pack(pady=10)
        
        # Entradas con Tooltips (Criterio 2)
        self.input_f = self.crear_campo(self.panel_izq, "Función f(x) [ej: x^2, sen(x)]", "Soporta x^2, sen(x), ln(x), e^x, pi")
        self.input_a = self.crear_campo(self.panel_izq, "Límite inferior (a)", "Punto de inicio en el eje X")
        self.input_b = self.crear_campo(self.panel_izq, "Límite superior (b)", "Punto de fin en el eje X")
        
        # COMPARADOR EN TIEMPO REAL (Novedad 2)
        self.lbl_n = ctk.CTkLabel(self.panel_izq, text="Cantidad de rectángulos (n): 20")
        self.lbl_n.pack(pady=(10,0))
        self.slider_n = ctk.CTkSlider(self.panel_izq, from_=1, to=100, number_of_steps=99, command=self.actualizar_slider)
        self.slider_n.set(20)
        self.slider_n.pack(pady=5, fill="x", padx=20)
        ToolTip(self.slider_n, "Desliza para cambiar n en tiempo real")

        # MULTIPLES GRÁFICOS SIMULTÁNEOS (Criterio 1)
        ctk.CTkLabel(self.panel_izq, text="Métodos a visualizar:", font=("Arial", 12, "bold")).pack(pady=(10,0), anchor="w", padx=20)
        self.var_izq = ctk.BooleanVar(value=False)
        self.var_der = ctk.BooleanVar(value=False)
        self.var_med = ctk.BooleanVar(value=True)
        ctk.CTkCheckBox(self.panel_izq, text="Izquierdo (Azul)", variable=self.var_izq, command=self.ejecutar_calculo).pack(pady=2, anchor="w", padx=20)
        ctk.CTkCheckBox(self.panel_izq, text="Derecho (Rojo)", variable=self.var_der, command=self.ejecutar_calculo).pack(pady=2, anchor="w", padx=20)
        ctk.CTkCheckBox(self.panel_izq, text="Punto Medio (Verde)", variable=self.var_med, command=self.ejecutar_calculo).pack(pady=2, anchor="w", padx=20)

        # CÁLCULO DE ÁREA REAL (Novedad 1)
        self.var_area_real = ctk.BooleanVar(value=False)
        self.chk_real = ctk.CTkCheckBox(self.panel_izq, text="Calcular Área Real ∫|f(x)|dx", variable=self.var_area_real, text_color="orange", command=self.ejecutar_calculo)
        self.chk_real.pack(pady=10, anchor="w", padx=20)
        ToolTip(self.chk_real, "Aplica valor absoluto si la curva baja del 0")

        # Botones de Acción
        ctk.CTkButton(self.panel_izq, text="Calcular Manual", command=self.ejecutar_calculo, fg_color="green", hover_color="darkgreen").pack(pady=10, fill="x", padx=20)
        ctk.CTkButton(self.panel_izq, text="Limpiar", command=self.limpiar_datos).pack(pady=5, fill="x", padx=20)
        
        # EXPORTACIÓN PDF/PNG (Novedad 3)
        btn_exportar = ctk.CTkButton(self.panel_izq, text="📄 Exportar Gráfico a PDF", command=self.exportar_grafico, fg_color="#A2142F", hover_color="#7A0F23")
        btn_exportar.pack(pady=5, fill="x", padx=20)
        ToolTip(btn_exportar, "Guarda el gráfico actual como PDF de alta calidad")

        # Resultados
        self.lbl_resultados = ctk.CTkLabel(self.panel_izq, text="Resultados:\nEsperando datos...", justify="left", font=("Consolas", 12))
        self.lbl_resultados.pack(pady=15, padx=10)

        # HISTORIAL DE CÁLCULOS (Novedad 4)
        ctk.CTkLabel(self.panel_izq, text="Historial de Funciones:", font=("Arial", 12, "bold")).pack(anchor="w", padx=20)
        self.caja_historial = ctk.CTkTextbox(self.panel_izq, height=100)
        self.caja_historial.pack(pady=5, fill="x", padx=20)

        self.switch_tema = ctk.CTkSwitch(self.panel_izq, text="Modo Claro", command=self.cambiar_tema)
        self.switch_tema.pack(pady=10)

        # --- PANEL DERECHO (Gráfico) ---
        self.panel_der = ctk.CTkFrame(self)
        self.panel_der.pack(side="right", fill="both", expand=True, padx=10, pady=10)
        
        self.figura, self.eje = plt.subplots(figsize=(8, 6), dpi=100)
        self.canvas = FigureCanvasTkAgg(self.figura, master=self.panel_der)
        self.canvas.get_tk_widget().pack(fill="both", expand=True)
        
        self.toolbar = NavigationToolbar2Tk(self.canvas, self.panel_der)
        self.toolbar.update()

    def crear_campo(self, padre, placeholder, tooltip_text):
        campo = ctk.CTkEntry(padre, placeholder_text=placeholder)
        campo.pack(pady=5, fill="x", padx=20)
        ToolTip(campo, tooltip_text)
        return campo

    def cambiar_tema(self):
        ctk.set_appearance_mode("Light" if self.switch_tema.get() == 1 else "Dark")

    def limpiar_datos(self):
        self.input_f.delete(0, 'end')
        self.input_a.delete(0, 'end')
        self.input_b.delete(0, 'end')
        self.slider_n.set(20)
        self.lbl_n.configure(text="Cantidad de rectángulos (n): 20")
        self.lbl_resultados.configure(text="Resultados:\nEsperando datos...")
        self.eje.clear()
        self.canvas.draw()

    def actualizar_slider(self, valor):
        n = int(valor)
        self.lbl_n.configure(text=f"Cantidad de rectángulos (n): {n}")
        if self.input_f.get() and self.input_a.get() and self.input_b.get():
            self.ejecutar_calculo()

    def exportar_grafico(self):
        try:
            ruta = filedialog.asksaveasfilename(defaultextension=".pdf", filetypes=[("PDF files", "*.pdf"), ("PNG files", "*.png")], title="Exportar Gráfico")
            if ruta:
                self.figura.savefig(ruta, bbox_inches='tight')
                messagebox.showinfo("Éxito", f"Gráfico exportado correctamente en:\n{ruta}")
        except Exception as e:
            messagebox.showerror("Error", f"No se pudo guardar: {e}")

    # ==========================================
    # BLOQUE 3: CONTROLADOR Y DIBUJO
    # ==========================================
    def ejecutar_calculo(self):
        try:
            texto_f = self.input_f.get()
            if not texto_f: return
            
            a = float(self.input_a.get())
            b = float(self.input_b.get())
            n = int(self.slider_n.get())

            if a >= b:
                messagebox.showerror("Error", "El límite inferior 'a' debe ser menor que 'b'")
                return

            formula = self.calculadora.traducir_texto(texto_f)
            area_real = self.var_area_real.get()
            datos = self.calculadora.evaluar(formula, a, b, n, calcular_area_real=area_real)

            if datos['alerta_negativo'] and not area_real:
                messagebox.showwarning("Advertencia", "La función toma valores negativos.\nActiva 'Calcular Área Real' para obtener el área geométrica neta.", icon="warning")

            # Construir texto de resultados y guardar historial
            exacta = datos['exacta']
            texto_res = f"Ancho Δx: {datos['dx']:.4f}\nIntegral Exacta: {exacta:.6f}\n\n"
            historial_str = f"f(x)={texto_f} | n={n}\nExacta: {exacta:.4f}\n"

            if self.var_izq.get():
                err = abs(exacta - datos['sum_izq'])
                rel = (err / abs(exacta)) * 100 if exacta != 0 else 0
                texto_res += f"Suma Izq: {datos['sum_izq']:.6f} (Err: {rel:.2f}%)\n"
            if self.var_der.get():
                err = abs(exacta - datos['sum_der'])
                rel = (err / abs(exacta)) * 100 if exacta != 0 else 0
                texto_res += f"Suma Der: {datos['sum_der']:.6f} (Err: {rel:.2f}%)\n"
            if self.var_med.get():
                err = abs(exacta - datos['sum_med'])
                rel = (err / abs(exacta)) * 100 if exacta != 0 else 0
                texto_res += f"Suma Medio: {datos['sum_med']:.6f} (Err: {rel:.2f}%)\n"

            self.lbl_resultados.configure(text=texto_res)
            
            # Evitar repetir en historial si es lo mismo
            if historial_str not in self.caja_historial.get("1.0", "end"):
                self.caja_historial.insert("1.0", historial_str + "-"*20 + "\n")

            # Dibujar Gráfico
            self.eje.clear()
            x_curva = np.linspace(a, b, 500)
            y_curva = datos['f_num'](x_curva)
            
            if area_real: y_curva = np.abs(y_curva)
            
            # RENDERIZADO MATEMÁTICO LaTeX (Criterio 2)
            lbl_funcion = f"${sp.latex(formula)}$"
            if area_real: lbl_funcion = f"$|{sp.latex(formula)}|$"
            
            self.eje.plot(x_curva, y_curva, color='black', linewidth=2.5, label=f"f(x) = {lbl_funcion}")
            self.eje.axhline(0, color='gray', linewidth=1) 

            # Múltiples Gráficos Simultáneos con transparencias (Criterio 1)
            if self.var_izq.get():
                self.eje.bar(datos['x_izq'], datos['y_izq'], width=datos['dx'], align='edge', alpha=0.3, edgecolor='blue', facecolor='cyan', linewidth=1.5, label="Izq")
            if self.var_der.get():
                self.eje.bar(datos['x_der'], datos['y_der'], width=-datos['dx'], align='edge', alpha=0.3, edgecolor='red', facecolor='lightcoral', linewidth=1.5, label="Der")
            if self.var_med.get():
                self.eje.bar(datos['x_med'], datos['y_med'], width=datos['dx'], align='center', alpha=0.4, edgecolor='green', facecolor='lightgreen', linewidth=1.5, label="Medio")

            self.eje.set_title(f"Aproximación de Área: {lbl_funcion}", fontsize=14)
            self.eje.legend(loc='upper right')
            self.eje.grid(True, linestyle='--', alpha=0.5)
            self.canvas.draw()

        except ValueError as e:
            messagebox.showerror("Error", str(e))
        except Exception as e:
            pass # Evita crashes por inputs a medias durante el slide

if __name__ == "__main__":
    app = AppVisualizador()
    app.mainloop()