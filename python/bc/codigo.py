# Nome: José Carlos Andrade do Nascimento
# NUSP: 12549450

import pyDes

# Exercicio b)
def encriptar_mensagem(mensagem_b: str, k) -> str:
    d = k.encrypt(mensagem_b)
    return d

def decriptar mensagem(mesagem_encriptada: str, k ) -> str:
    d = k.decrypt(mensagem_encriptada)
    return d

# Exercicio c), d), e)
from Crypto.Hash import SHA256
import hashlib
from socket import *

def gerar_hash(data):
    return hashlib.sha256(str(data).encode('utf-8')).hexdigest()

def checar_hash(teste, data_enc):
    return gerar_hash(teste) == data_enc

cadeia1 = 'SSC0541_'
cadeia2 = 'SSC0541-'
cadeia_hash = gerar_hash(cadeia1)
print("hash da primera cadeia: ", cadeia_hash)
cadeia_hash = gerar_hash(cadeia2)
print("hash da segunda cadeia: ", cadeia_hash)
verificador = checar_hash(cadeia1, cadeia_hash)
print("Cadeias iguais? ", verificador)

serverName = "172.0.0.1"
serverPort = 12000

clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverName,serverPort))

clientSocket.send(bytes(gerar_hash(cadeia1)), 'utf_8')

# Exercicio f)
# Basta adicionarmos um parametro de dificuldade no construtor da classe Blockchain
class Blockchain:
    # difficulty of our PoW algorithm
    difficulty = 5 # padrao

    def __init__(self, difficulty=5): # valor padrao caso nao seja passado é 5
        self.unconfirmed_transactions = []
        self.chain = []
        self.create_genesis_block()
        Blockchain.difficulty = difficulty


