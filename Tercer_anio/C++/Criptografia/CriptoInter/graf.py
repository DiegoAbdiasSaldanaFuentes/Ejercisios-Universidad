import matplotlib.pyplot as plt

# Datos extraídos
tamanos = ['100K', '300K', '500K', '700K', '900K', '1.2M']
encriptacion_ms = [18.06, 25.70, 33.48, 38.08, 44.32, 53.84]
desencriptacion_ms = [15.69, 18.17, 20.13, 28.44, 30.22, 39.02]

# Configuración del gráfico
plt.figure(figsize=(10, 6))

# Trazado de las líneas
plt.plot(tamanos, encriptacion_ms, marker='o', linestyle='-', color='#d62728', label='Encriptación')
plt.plot(tamanos, desencriptacion_ms, marker='s', linestyle='--', color='#1f77b4', label='Desencriptación')

# Etiquetas y título
plt.title('Rendimiento ECC: Tiempos de Encriptación vs Desencriptación', fontsize=14, fontweight='bold')
plt.xlabel('Cantidad de Caracteres / Bytes', fontsize=12)
plt.ylabel('Tiempo de ejecución (ms)', fontsize=12)

# Añadir valores numéricos sobre los puntos para mayor claridad
for i in range(len(tamanos)):
    plt.text(i, encriptacion_ms[i] + 1, f'{encriptacion_ms[i]}', ha='center', color='#d62728', fontsize=9)
    plt.text(i, desencriptacion_ms[i] - 1.5, f'{desencriptacion_ms[i]}', ha='center', color='#1f77b4', fontsize=9)

# Estilos adicionales
plt.legend()
plt.grid(True, linestyle=':', alpha=0.7)
plt.tight_layout()

# Mostrar la gráfica
plt.show()