# Calificaciones1.py
TMAX = 50
import Estudiantes as est
# Funcion Principal
A, tl = est.LeerNomina()
est.EscribirNomina(A, tl, "NOMINA INGRESADA:")
A = est.Ordenar(A, tl, "Ascendente", 0)
est.EscribirNomina(A, tl, "NOMINA ORDENADA ASCENDENTEMENTE POR CEDULA:")
A = est.Ordenar(A, tl, "Descendente", 0)
est.EscribirNomina(A, tl, "NOMINA ORDENADA DESCENDENTEMENTE POR CEDULA:")
A = est.Ordenar(A, tl, "Ascendente", 1)
est.EscribirNomina(A, tl, "NOMINA ORDENADA ASCENDENTEMENTE POR NOMBRE:")
A = est.Ordenar(A, tl, "Descendente", 1)
est.EscribirNomina(A, tl, "NOMINA ORDENADA DESCENDENTEMENTE POR NOMBRE:")