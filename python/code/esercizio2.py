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
    print("INSERIRE NUMERI INTERI.\nPER FERMARSI INSERIRE 0")
    coda = []
    n = int(input())
    while(n != 0):
        enqueue(coda,n)
        n = int(input())
        
    
    while(len(coda) != 0):
        print(coda[-1],end=" ")
        coda = dequeue(coda)
        

    




    

if "__main__" == __name__:
    main()

