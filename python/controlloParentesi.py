def push_(pila,elemento):
    pila.append(elemento)

def pop_(pila):
    return pila.pop()



def controllaGiusto(stringa):
    parentesi = ["(", ")" , "[", "]", "{", "}"]
    assegnazioni = {"(" :  ")" , "[": "]", "{" : "}",  ")" :"(", "]" : "[", "}": "{"}
    parentesiChiuse = ["]","}", ")"]
    corretto = True
    pila = []
    for lettera in stringa:        
        if(lettera in parentesi):
            if(lettera in parentesiChiuse):
                if(len(pila) != 0):
                    if(lettera != assegnazioni[pop_(pila)]):
                        corretto = False
                else:
                    corretto = False
            else:
                push_(pila,lettera)
    
     
    if len(pila)>0:
        return False
    return corretto



def main():
    stringa = "{    }()[]"
    print(controllaGiusto(stringa))

if ( __name__ == "__main__"):
    main()