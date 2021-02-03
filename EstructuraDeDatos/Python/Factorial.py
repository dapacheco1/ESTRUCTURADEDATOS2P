# Factorial.py
def FacR(X):
    if X < 2:
        return 1
    return X * FacR(X - 1)
# Funcion principal:
while 1:
    n = int(input('Ingresar un entero (salir < 0 o > 20): '))
    if n < 0 or n > 20:
        break
    print('Factorial(', n, ') = ', FacR(n))
