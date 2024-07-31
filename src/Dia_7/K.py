palabra = str(input())

palabra = palabra.lower()

palabra = palabra.replace("a","").replace("e","").replace("i","").replace("o","").replace("u","").replace("y","")

aux = ""
for char in palabra:
    aux += "." + char

print(aux)

