from random_class import Random

# Como rodar o programa:
# executar o codigo adivinha.py com o interpretador de python 3 e digitar o numero
# maximo N que pode ser pensado ( de 0 a N )

# a partir disso, a cada passo do loop o codigo vai sugerir um numero aleatorio 
# de 0 a N (pro primeiro passo). Caso seja o numero pensado, digitar 's' no terminal.
# Caso o numero pensado seja maior que o numero sugerido, digitar '+'. Caso menor, '-'.


class Adivinha:
    def __init__(self, maximo):
        # começa com minimo em -1 pois nao é inclusivo
        self.minimo = 0
        self.maximo = maximo

    def adivinhar_numero(self):
        r = Random()
        #  get int rand (x) -> 0-(x-1)
        num = r.getIntRand(self.maximo - self.minimo -1 )

        return (num +self.minimo+1 )
    
    def maior(self, min):
        self.minimo = min 

    def menor(self, max):
        self.maximo = max 



if __name__ == "__main__":
    maximo = int(input("Digite o número máximo N (0 a N): "))
    adivinha = Adivinha(maximo)

    print(f"Pense em um número de o a {maximo}!")
    while True:
        palpite = adivinha.adivinhar_numero()
        print(f"Seu número é {palpite}? - 's' -> Sim; '+' -> Não, é maior; '-' -> Não, é menor;\n")
        controle = input()

        if controle == 's':
            print("O número foi acertado.")
            break
        elif controle == '+':
            adivinha.maior(palpite)
        elif controle == '-':
            adivinha.menor(palpite)
        else:
            print("Por favor, insira um caractere válido.")