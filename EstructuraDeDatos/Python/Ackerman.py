# Ackerman.py
MaxX = 4
MaxY = 20
def Ack(X, Y):
    if X == 0:
        return Y + 1
    elif Y == 0:
        return Ack(X - 1, 1)
    else:
        return Ack(X - 1, Ack(X, Y - 1))
# Funcion principal:
while 1:
    x = int(input('Ingresar x (salir < 0 o > ' + str(MaxX)+ '): '))
    if x < 0 or x > MaxX:
        break
    y = int(input('Ingresar y (salir < 0 o > ' + str(MaxY)+ '): '))
    if y < 0 or y > MaxY:
        break
    print('Ackerman(', x, ', ', y, ') = ', Ack(x, y))