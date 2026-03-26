# CLASE
class CuentaBancaria:
    
    # CONSTRUCTOR (__init__)
    def __init__(self, titular, saldo_inicial):
        self._titular = titular      # atributo protegido
        self._saldo = saldo_inicial  # atributo protegido

    # MÉTODOS GETTERS (de instancia)
    def get_titular(self):
        return self._titular

    def get_saldo(self):
        return self._saldo

    # MÉTODO normal (de instancia)
    def depositar(self, monto):
        if monto > 0:
            self._saldo += monto

    # MÉTODO normal (de instancia)
    def retirar(self, monto):
        if monto > 0 and monto <= self._saldo:
            self._saldo -= monto

    # MÉTODO normal (de instancia)
    def mostrar(self):
        print("Titular =", self._titular)
        print("Saldo =", self._saldo)
# Código principal
# OBJETO (instancia de la clase CuentaBancaria)
c1 = CuentaBancaria("Maria", 100000.0)

c1.mostrar()

c1.depositar(25000.0)
c1.retirar(10000.0)

print("\nDespues de operaciones:")
c1.mostrar()
