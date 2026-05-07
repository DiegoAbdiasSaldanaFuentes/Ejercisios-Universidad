
SELECT LAST_NAME AS 'apellido', SALARY * 12 AS 'Salario anual', SALARY + 300 AS 'Sueldo Proyectado'
FROM OEHR_EMPLOYEES;

SELECT 'El trabajdor ' || LAST_NAME ||
    'Tiene el salario: ' || SALARY ||
    'Con un salario anual de: '|| (SALARY * 12) ||
    'con sueldo proyectado de: '|| (SALARY + 300) AS "Detalle Completo"
FROM OEHR_EMPLOYEES;




