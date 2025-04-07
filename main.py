class No:
    def __init__(self, valor=0):
        self.valor = valor
        self.proximo = None
        self.anterior = None


class Lista:
    def __init__(self):
        self.tamanho = 0
        self.cabeca = No()
        self.cabeca.proximo = self.cabeca
        self.cabeca.anterior = self.cabeca

    def imprimir_lista(self):
        item = self.cabeca.proximo
        print("Soldados: ", end="")
        for _ in range(self.tamanho):
            print(item.valor, end=" ")
            item = item.proximo
        print()

    def inserir_item(self, valor):
        item = No(valor)
        item.proximo = self.cabeca
        item.anterior = self.cabeca.anterior
        self.cabeca.anterior.proximo = item
        self.cabeca.anterior = item
        self.tamanho += 1

    def remover_item(self, valor):
        item = self.cabeca.proximo
        for _ in range(self.tamanho):
            if item.valor == valor:
                item.anterior.proximo = item.proximo
                item.proximo.anterior = item.anterior
                self.tamanho -= 1
                return
            item = item.proximo

    def josefo(self, pulo):
        item = self.cabeca.proximo
        c = 1

        while True:
            if item.valor != 0:  # Ignora o nó cabeça
                if self.tamanho == 1:
                    print(f"O último soldado foi {item.valor}")
                    break

                if c == pulo:
                    aux = item.proximo
                    self.remover_item(item.valor)
                    print(f"Soldado {item.valor} foi removido")
                    item = aux
                    break
                else:
                    item = item.proximo
                    c += 1
            else:
                item = item.proximo


def main():
    lista = Lista()

    max_soldados = int(input("Quantos soldados deseja inserir? "))
    for c in range(1, max_soldados + 1):
        lista.inserir_item(c)
    lista.imprimir_lista()

    while True:
        if lista.tamanho == 1:
            print("Só restou um soldado")
            break

        pulo = int(input("Qual o tamanho do pulo? "))
        lista.josefo(pulo)
        lista.imprimir_lista()


if __name__ == "__main__":
    main()
