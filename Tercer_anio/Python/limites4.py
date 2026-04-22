import sympy as sp
import numpy as np
import matplotlib.pyplot as plt

def analizar_y_graficar_limite(expresion_str, valor_tendencia):
    x = sp.Symbol('x')
    
    formula = sp.sympify(expresion_str)
    
    print("="*50)
    print(f" ANALIZANDO LÍMITE: x -> {valor_tendencia}")
    print(f" Fórmula: {formula}")
    print("="*50)

    num, den = sp.fraction(formula)
    
    eval_num = num.subs(x, valor_tendencia)
    eval_den = den.subs(x, valor_tendencia)
    print(f"\n[PASO 1] Sustitución Directa: {eval_num} / {eval_den}")

    if eval_num == 0 and eval_den == 0:
        print("\n[!] ALERTA: Indeterminación 0/0 detectada (Discontinuidad Evitable).")
        culpable = x - valor_tendencia
        print(f"    -> El 'Culpable' que debemos tachar es: ({culpable})")
        
        # Factorizamos
        num_fact = sp.factor(num)
        den_fact = sp.factor(den)
        print(f"\n[PASO 2] Factorizando polinomios:")
        print(f"    Numerador factorizado:   {num_fact}")
        print(f"    Denominador factorizado: {den_fact}")
        
    elif eval_den == 0:
        print("\nALERTA: División por cero (Número / 0).")
        print("    -> Esto indica una Asíntota Vertical (Discontinuidad Inevitable). No se puede tachar.")
    else:
        print("\nPASO 2: No hay problema. Es una sustitución limpia (Función Continua).")

    limite_real = sp.limit(formula, x, valor_tendencia)
    print(f"\nRESULTADO El Límite es: {limite_real}")
    
    print("\nGenerando gráfico...")
    
    f_numerica = sp.lambdify(x, formula, modules=['numpy'])
    
    x_vals = np.linspace(float(valor_tendencia) - 10, float(valor_tendencia) + 10, 400)
    y_vals = f_numerica(x_vals)
    
    plt.figure(figsize=(8, 5))
    plt.plot(x_vals, y_vals, label=f"f(x) = {expresion_str}", color='blue')
    
    if limite_real.is_real:
        plt.plot(float(valor_tendencia), float(limite_real), 'o', 
                 markeredgecolor='red', markerfacecolor='white', markersize=8, 
                 label=f'Límite en ({valor_tendencia}, {limite_real})')
        plt.axhline(y=float(limite_real), color='r', linestyle='--', alpha=0.4)
    
    plt.axvline(x=float(valor_tendencia), color='g', linestyle='--', alpha=0.4, label=f'x -> {valor_tendencia}')
    
    plt.title("Análisis del Límite")
    plt.xlabel("Eje X")
    plt.ylabel("Eje Y")
    plt.grid(True)
    plt.legend()
    plt.show()
#primero a la izquierda

#mi_formula = "(x**2 + 8*x + 15) / (x**2 - x - 12)"
mi_formula = "(4 - sqrt(x**2 + 7)) / (3*x + 9)"
mi_tendencia = -3

analizar_y_graficar_limite(mi_formula, mi_tendencia)