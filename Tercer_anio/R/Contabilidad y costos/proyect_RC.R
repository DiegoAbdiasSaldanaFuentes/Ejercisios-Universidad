library(dplyr)


# datos 
ventas_mayor <- BD_04_Vestuario_Calzado %>% #preparar tabla de ventas por mayor
  filter(tipo_venta == "Mayor") %>%
  group_by(anio) %>%
  summarise(ingreso_total = sum(monto_venta_total_con_iva, na.rm = TRUE))

ventas_detal <- BD_04_Vestuario_Calzado %>% #preparar tabla de ventas al menor
  filter(tipo_venta == "Detal") %>%
  group_by(anio) %>%
  summarise(ingreso_total = sum(monto_venta_total_con_iva, na.rm = TRUE))

# crear modelo estadístico 
modelo_mayor <- lm(ingreso_total ~ anio, data = ventas_mayor) #tendencia de negocio
modelo_detal <- lm(ingreso_total ~ anio, data = ventas_detal)

# Calculo de los 10 años
ultimo_anio <- max(BD_04_Vestuario_Calzado$anio, na.rm = TRUE)
anios_futuros <- data.frame(anio = (ultimo_anio + 1):(ultimo_anio + 10))

prediccion_mayor <- predict(modelo_mayor, newdata = anios_futuros)
prediccion_detal <- predict(modelo_detal, newdata = anios_futuros)

#  Dibujar  la historia del negocio

par(mfrow = c(1, 2))

# Grafico para venta al mayor

plot(ventas_mayor$anio, ventas_mayor$ingreso_total, 
     type = "b", col = "blue", pch = 16,
     xlim = c(min(ventas_mayor$anio), ultimo_anio + 10),
     ylim = c(0, max(c(ventas_mayor$ingreso_total, prediccion_mayor), na.rm = TRUE)),
     main = "Proyección 10 Años - Mayor",
     xlab = "Año", ylab = "Ingreso Total")
lines(anios_futuros$anio, prediccion_mayor, col = "red", lwd = 2, lty = 2)

# Grafico de ventas al detal
plot(ventas_detal$anio, ventas_detal$ingreso_total, 
     type = "b", col = "green", pch = 16,
     xlim = c(min(ventas_detal$anio), ultimo_anio + 10),
     ylim = c(0, max(c(ventas_detal$ingreso_total, prediccion_detal), na.rm = TRUE)),
     main = "Proyección 10 Años - Detal",
     xlab = "Año", ylab = "Ingreso Total")
lines(anios_futuros$anio, prediccion_detal, col = "red", lwd = 2, lty = 2)