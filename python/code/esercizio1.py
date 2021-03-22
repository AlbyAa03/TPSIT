'''
Implementare i metodi enqueue() e dequeue()  e creare un programma che permetta
all’utente di riempire una coda di numeri interi di lunghezza arbitraria. Successivamente
testare la funzione dequeue per svuotare la coda.
'''


def enqueue(coda,elemento):
    coda.insert(0,elemento)

def dequeue(coda):
    coda = coda[0:-1]
    return coda

def main():
    coda = []    
    for numero in range(10):
        enqueue(coda,numero)
    
    print(coda)

    while(len(coda)!= 0):
        print(f"{coda[-1]} ",end="") 
        coda = dequeue(coda)

if __name__ == "__main__":
    main()