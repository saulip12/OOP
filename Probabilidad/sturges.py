import math
import tkinter as tk
from tkinter import ttk, messagebox, scrolledtext
 
 
# ----------------------------------------------------------------------
# Funciones auxiliares
# ----------------------------------------------------------------------
 
def contar_decimales_texto(token: str) -> int:
    """Cuenta los decimales de un token de texto."""
    if "." in token:
        return len(token.split(".")[1])
    return 0
 
 
def contar_decimales_valor(valor: float, tol: float = 1e-9, max_dec: int = 8) -> int:
    """Cuenta los decimales 'reales' que necesita un valor calculado."""
    for dec in range(0, max_dec + 1):
        if abs(round(valor, dec) - valor) < tol:
            return dec
    return max_dec
 
 
def separar_tokens(texto: str):
    """Convierte el texto ingresado en una lista de tokens numéricos (str)."""
    # Se aceptan espacios, comas (como separador de lista) y saltos de línea
    # como separadores. Pero si una coma aparece PEGADA a dígitos en ambos
    # lados sin espacio (ej. 3,5) se interpretará como coma decimal -> error.
    crudo = texto.strip()
    if not crudo:
        return []
 
    # Detectar posibles comas decimales: patrón dígito,dígito
    import re
    if re.search(r"\d,\d", crudo):
        raise ValueError(
            "Se detectó una coma como separador decimal (ej. 3,5). "
            "Los decimales deben escribirse con PUNTO (ej. 3.5)."
        )
 
    # Reemplazar comas (de lista) y saltos de línea por espacios
    crudo = crudo.replace(",", " ").replace("\n", " ").replace("\t", " ")
    tokens = [t for t in crudo.split(" ") if t.strip() != ""]
    return tokens
 
 
def validar_y_convertir(tokens):
    """Valida que cada token sea un número válido (solo punto decimal)."""
    valores = []
    for t in tokens:
        t = t.strip()
        # Solo se permiten dígitos, un punto y un signo negativo opcional
        if not es_numero_valido(t):
            raise ValueError(f"El dato '{t}' no es un número válido (use solo punto '.' para decimales).")
        valores.append(float(t))
    return valores
 
 
def es_numero_valido(token: str) -> bool:
    if token.count(".") > 1:
        return False
    cuerpo = token[1:] if token.startswith("-") else token
    if cuerpo == "":
        return False
    return all(c.isdigit() or c == "." for c in cuerpo) and cuerpo != "."
 
 
# ----------------------------------------------------------------------
# Lógica del método de Sturges 
# ----------------------------------------------------------------------
 
class ResultadoSturges:
    def __init__(self):
        self.n = 0
        self.minimo = 0.0
        self.maximo = 0.0
        self.rango = 0.0
        self.d = 0.0
        self.decimales_datos = 0
        self.k_float = 0.0
        self.candidatos = []       # lista de (k, C, decimales_C)
        self.k_elegido = 0
        self.C = 0.0
        self.uso_respaldo = False
        self.limites = []          # límites reales
        self.clases = []           # lista de dicts con la info de cada clase
 
 
def calcular_sturges(datos, d, decimales_datos) -> ResultadoSturges:
    res = ResultadoSturges()
    res.n = len(datos)
    res.minimo = min(datos)
    res.maximo = max(datos)
    res.rango = res.maximo - res.minimo
    res.d = d
    res.decimales_datos = decimales_datos
 
    res.k_float = 1 + math.log2(res.n)
    k_piso = math.floor(res.k_float)
    k_techo = math.ceil(res.k_float)
 
    candidatos_k = [k_piso] if k_piso == k_techo else [k_piso, k_techo]
    candidatos_k = [k for k in candidatos_k if k > 0]
 
    for k in candidatos_k:
        C = (res.rango + res.d) / k
        dec_C = contar_decimales_valor(C)
        res.candidatos.append((k, C, dec_C))
 
    elegido = None
    for k, C, dec_C in res.candidatos:
        if dec_C <= res.decimales_datos:
            elegido = (k, C)
            break
 
    if elegido is None:
        # Ningún candidato cumple exactamente: se usa el que tenga menos
        # decimales y se redondea C a los decimales de los datos.
        k, C, dec_C = min(res.candidatos, key=lambda r: r[2])
        C = round(C, res.decimales_datos)
        elegido = (k, C)
        res.uso_respaldo = True
 
    res.k_elegido, res.C = elegido
 
    # Límites reales
    li0 = res.minimo - res.d / 2
    limites = [li0]
    for _ in range(res.k_elegido):
        limites.append(limites[-1] + res.C)
    res.limites = limites
 
    # Frecuencias
    eps = 1e-9
    conteos = [0] * res.k_elegido
    for x in datos:
        idx = None
        for i in range(res.k_elegido):
            li, ls = limites[i], limites[i + 1]
            es_ultima = (i == res.k_elegido - 1)
            if es_ultima:
                if (li - eps) <= x <= (ls + eps):
                    idx = i
                    break
            else:
                if (li - eps) <= x < (ls - eps):
                    idx = i
                    break
        if idx is None:
            # Por seguridad se asigna a la clase más cercana
            distancias = [abs(x - (limites[i] + limites[i + 1]) / 2) for i in range(res.k_elegido)]
            idx = distancias.index(min(distancias))
        conteos[idx] += 1
 
    Fi_acum = 0
    Hi_acum = 0.0
    for i in range(res.k_elegido):
        li, ls = limites[i], limites[i + 1]
        xi = (li + ls) / 2
        fi = conteos[i]
        hi = fi / res.n
        Fi_acum += fi
        Hi_acum += hi
        res.clases.append({
            "clase": i + 1,
            "li": li,
            "ls": ls,
            "xi": xi,
            "fi": fi,
            "hi": hi,
            "Fi": Fi_acum,
            "Hi": Hi_acum,
        })
 
    return res
 
 
# ----------------------------------------------------------------------
# Interfaz gráfica
# ----------------------------------------------------------------------
 
class App(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("Agrupación de datos - Método de Sturges")
        self.geometry("980x680")
        self.minsize(860, 600)
        self.configure(bg="#f2f4f7")
 
        self._construir_widgets()
 
    # ------------------------------------------------------------------
    def _construir_widgets(self):
        estilo = ttk.Style(self)
        try:
            estilo.theme_use("clam")
        except tk.TclError:
            pass
        estilo.configure("Treeview.Heading", font=("Segoe UI", 9, "bold"))
        estilo.configure("Treeview", rowheight=24, font=("Segoe UI", 9))
 
        titulo = tk.Label(
            self, text="Agrupación de datos por el método de Sturges",
            font=("Segoe UI", 14, "bold"), bg="#f2f4f7", fg="#1f2937"
        )
        titulo.pack(pady=(12, 4))
 
        subtitulo = tk.Label(
            self,
            text="Ingrese los datos (separados por espacio, coma o salto de línea). "
                 "Use PUNTO para decimales, ej: 12.5",
            font=("Segoe UI", 9), bg="#f2f4f7", fg="#4b5563"
        )
        subtitulo.pack(pady=(0, 10))
 
        # --- Panel superior: entradas ---
        panel_entrada = tk.Frame(self, bg="#f2f4f7")
        panel_entrada.pack(fill="x", padx=16)
 
        # Caja de texto de datos
        frame_datos = tk.LabelFrame(panel_entrada, text="Datos", bg="#f2f4f7",
                                     font=("Segoe UI", 9, "bold"))
        frame_datos.pack(side="left", fill="both", expand=True, padx=(0, 10))
 
        self.txt_datos = scrolledtext.ScrolledText(frame_datos, height=6, width=50,
                                                     font=("Consolas", 10))
        self.txt_datos.pack(fill="both", expand=True, padx=6, pady=6)
 
        # Panel derecho: d, botones
        frame_derecha = tk.Frame(panel_entrada, bg="#f2f4f7")
        frame_derecha.pack(side="left", fill="y")
 
        frame_d = tk.LabelFrame(frame_derecha, text="Parámetro d\n(diferencia mínima entre datos)",
                                 bg="#f2f4f7", font=("Segoe UI", 9, "bold"))
        frame_d.pack(fill="x", pady=(0, 10))
 
        vcmd = (self.register(self._validar_entrada_numerica), "%P")
        self.entry_d = tk.Entry(frame_d, font=("Consolas", 11), width=15,
                                 validate="key", validatecommand=vcmd, justify="center")
        self.entry_d.pack(padx=8, pady=8)
 
        btn_frame = tk.Frame(frame_derecha, bg="#f2f4f7")
        btn_frame.pack(fill="x")
 
        self.btn_calcular = tk.Button(
            btn_frame, text="Calcular", command=self.procesar,
            bg="#2563eb", fg="white", font=("Segoe UI", 10, "bold"),
            activebackground="#1d4ed8", activeforeground="white",
            relief="flat", padx=12, pady=8, cursor="hand2"
        )
        self.btn_calcular.pack(fill="x", pady=(4, 4))
 
        self.btn_limpiar = tk.Button(
            btn_frame, text="Limpiar", command=self.limpiar,
            bg="#e5e7eb", fg="#111827", font=("Segoe UI", 10),
            relief="flat", padx=12, pady=8, cursor="hand2"
        )
        self.btn_limpiar.pack(fill="x")
 
        # --- Panel de resumen de cálculos ---
        frame_resumen = tk.LabelFrame(self, text="Resumen del cálculo", bg="#f2f4f7",
                                       font=("Segoe UI", 9, "bold"))
        frame_resumen.pack(fill="x", padx=16, pady=(12, 8))
 
        self.lbl_resumen = tk.Label(
            frame_resumen, text="Ingrese los datos y presione «Calcular».",
            justify="left", anchor="w", bg="#f2f4f7", fg="#111827",
            font=("Consolas", 9), wraplength=920
        )
        self.lbl_resumen.pack(fill="x", padx=8, pady=8)
 
        # --- Tabla de resultados ---
        frame_tabla = tk.LabelFrame(self, text="Tabla de frecuencias", bg="#f2f4f7",
                                     font=("Segoe UI", 9, "bold"))
        frame_tabla.pack(fill="both", expand=True, padx=16, pady=(0, 16))
 
        columnas = ("clase", "intervalo", "xi", "fi", "hi", "Fi", "Hi")
        self.tabla = ttk.Treeview(frame_tabla, columns=columnas, show="headings", height=10)
 
        encabezados = {
            "clase": "Clase",
            "intervalo": "Li - Ls",
            "xi": "xi (marca de clase)",
            "fi": "fi (frec. absoluta)",
            "hi": "hi (frec. relativa)",
            "Fi": "Fi (frec. acumulada)",
            "Hi": "Hi (frec. rel. acumulada)",
        }
        anchos = {
            "clase": 60, "intervalo": 190, "xi": 150,
            "fi": 130, "hi": 140, "Fi": 140, "Hi": 170,
        }
        for col in columnas:
            self.tabla.heading(col, text=encabezados[col])
            self.tabla.column(col, width=anchos[col], anchor="center")
 
        scrollbar = ttk.Scrollbar(frame_tabla, orient="vertical", command=self.tabla.yview)
        self.tabla.configure(yscrollcommand=scrollbar.set)
 
        self.tabla.pack(side="left", fill="both", expand=True, padx=(6, 0), pady=6)
        scrollbar.pack(side="left", fill="y", pady=6)
 
    # ------------------------------------------------------------------
    def _validar_entrada_numerica(self, texto_propuesto: str) -> bool:
        """Restringe el campo 'd' a dígitos y un único punto decimal (sin comas)."""
        if texto_propuesto == "":
            return True
        if "," in texto_propuesto:
            return False
        if texto_propuesto.count(".") > 1:
            return False
        cuerpo = texto_propuesto
        return all(c.isdigit() or c == "." for c in cuerpo)
 
    # ------------------------------------------------------------------
    def limpiar(self):
        self.txt_datos.delete("1.0", tk.END)
        self.entry_d.delete(0, tk.END)
        self.lbl_resumen.config(text="Ingrese los datos y presione «Calcular».")
        for item in self.tabla.get_children():
            self.tabla.delete(item)
 
    # ------------------------------------------------------------------
    def procesar(self):
        texto_datos = self.txt_datos.get("1.0", tk.END)
        texto_d = self.entry_d.get().strip()
 
        # --- Validar datos ---
        try:
            tokens = separar_tokens(texto_datos)
        except ValueError as e:
            messagebox.showerror("Error en los datos", str(e))
            return
 
        if len(tokens) < 2:
            messagebox.showerror("Error en los datos", "Ingrese al menos 2 datos.")
            return
 
        try:
            datos = validar_y_convertir(tokens)
        except ValueError as e:
            messagebox.showerror("Error en los datos", str(e))
            return
 
        # --- Validar d ---
        if texto_d == "":
            messagebox.showerror("Error en 'd'", "Debe ingresar el valor de d.")
            return
        if not es_numero_valido(texto_d):
            messagebox.showerror("Error en 'd'", "El valor de d no es válido (use solo punto para decimales).")
            return
        d = float(texto_d)
        if d <= 0:
            messagebox.showerror("Error en 'd'", "El valor de d debe ser mayor que 0.")
            return
 
        decimales_datos = max(contar_decimales_texto(t) for t in tokens)
 
        # --- Calcular ---
        try:
            res = calcular_sturges(datos, d, decimales_datos)
        except Exception as e:
            messagebox.showerror("Error en el cálculo", f"Ocurrió un error: {e}")
            return
 
        self._mostrar_resumen(res, decimales_datos)
        self._mostrar_tabla(res)
 
    # ------------------------------------------------------------------
    def _mostrar_resumen(self, res: ResultadoSturges, decimales_datos: int):
        cand_txt = "; ".join(
            f"k={k} -> C={C:.6g} ({dec} decimales)" for k, C, dec in res.candidatos
        )
        aviso_respaldo = ""
        if res.uso_respaldo:
            aviso_respaldo = ("\n⚠ Ningún candidato cumplió exactamente la condición de decimales; "
                               "se usó el mejor candidato y se redondeó C.")
 
        texto = (
            f"n = {res.n}   |   mínimo = {res.minimo:g}   |   máximo = {res.maximo:g}   |   "
            f"Rango (R) = {res.rango:g}   |   d = {res.d:g}   |   decimales de los datos = {decimales_datos}\n"
            f"k = 1 + log2({res.n}) = {res.k_float:.4f}\n"
            f"Candidatos evaluados: {cand_txt}\n"
            f"→ k elegido = {res.k_elegido}   |   C (ancho de intervalo) = {res.C:g}\n"
            f"Primer límite real: Li(1) = {res.minimo:g} - {res.d:g}/2 = {res.limites[0]:g}"
            f"{aviso_respaldo}"
        )
        self.lbl_resumen.config(text=texto)
 
    # ------------------------------------------------------------------
    def _mostrar_tabla(self, res: ResultadoSturges):
        for item in self.tabla.get_children():
            self.tabla.delete(item)
 
        dec = res.decimales_datos if res.decimales_datos > 0 else 2
 
        for c in res.clases:
            intervalo = f"[{c['li']:.{dec}f}  -  {c['ls']:.{dec}f}]"
            self.tabla.insert("", "end", values=(
                c["clase"],
                intervalo,
                f"{c['xi']:.{dec}f}",
                c["fi"],
                f"{c['hi']:.4f}",
                c["Fi"],
                f"{c['Hi']:.4f}",
            ))
 
 
if __name__ == "__main__":
    app = App()
    app.mainloop()
 
