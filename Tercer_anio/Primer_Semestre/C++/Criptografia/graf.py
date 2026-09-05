import matplotlib.pyplot as plt

# Eje X: Cantidad de caracteres
caracteres = [10, 100, 1000, 10000, 100000, 1000000]

# Datos de Encriptación (ms)
encr_20_hilos = [0.0006, 0.0024, 0.0162, 0.1348, 0.1419, 1.2584]
encr_10_hilos = [0.0006, 0.0020, 0.0131, 0.1272, 0.1455, 1.4652] # Corregido 100k

# Datos de Desencriptación (ms)
dcr_20_hilos = [0.0038, 0.0062, 0.0165, 0.1225, 0.1612, 1.4462]
dcr_10_hilos = [0.0040, 0.0053, 0.0157, 0.3169, 0.3842, 1.6165] # Corregido 100k

# Crear figura con dos subgráficos lado a lado
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(15, 6))

# --- Gráfico 1: Encriptación ---
ax1.plot(caracteres, encr_20_hilos, marker='o', label='20 Hilos', linewidth=2, color='#1f77b4')
ax1.plot(caracteres, encr_10_hilos, marker='s', label='10 Hilos', linewidth=2, color='#ff7f0e')
ax1.set_xscale('log')
ax1.set_title('Tiempo de Encriptación ECC', fontsize=14, fontweight='bold')
ax1.set_xlabel('Cantidad de Caracteres (Escala Logarítmica)', fontsize=12)
ax1.set_ylabel('Tiempo (ms)', fontsize=12)
ax1.grid(True, which="both", ls="--", alpha=0.6)
ax1.legend(fontsize=12)

# --- Gráfico 2: Desencriptación ---
ax2.plot(caracteres, dcr_20_hilos, marker='o', label='20 Hilos', linewidth=2, color='#2ca02c')
ax2.plot(caracteres, dcr_10_hilos, marker='s', label='10 Hilos', linewidth=2, color='#d62728')
ax2.set_xscale('log')
ax2.set_title('Tiempo de Desencriptación ECC', fontsize=14, fontweight='bold')
ax2.set_xlabel('Cantidad de Caracteres (Escala Logarítmica)', fontsize=12)
ax2.set_ylabel('Tiempo (ms)', fontsize=12)
ax2.grid(True, which="both", ls="--", alpha=0.6)
ax2.legend(fontsize=12)

# Ajustar espaciado y guardar
plt.tight_layout()
plt.savefig('graficos_rendimiento_ecc_corregido.png', dpi=300, bbox_inches='tight')

print("Exito: Gráficos guardados como 'graficos_rendimiento_ecc_corregido.png'")