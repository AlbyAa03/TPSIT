'''
Implementare le pile e i metodi pop() e push() utilizzando una coda con i suoi metodi
enqueue() and dequeue().
'''


def enqueue(coda,elemento):
    coda.insert(0,elemento)

def dequeue(coda):
    return coda[0:-1],coda[-1]


def pop():
    pass

def push(pila,elemento):
    temp = [elemento]
    
    cnt = 0
    while(len(pila) > cnt):
        pila,t =dequeue(pila)
        enqueue(temp,t)
        cnt += 1
    print(temp)
        


def main():
    pila = [0]
    
    for numero in range(10):
        pila = push(pila,numero)

    while(len(pila) != 0):
        pila,temp = dequeue(pila)
        print(temp)        

    


if "__main__" == __name__:
    main()