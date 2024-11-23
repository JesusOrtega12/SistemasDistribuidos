import requests
import socket

def geonamesSocket(city):
    
    # Parámetros de la conexión
    host = "api.geonames.org"
    port = 80

    # Crear el socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect((host, port))

    # Crear la solicitud HTTP GET
    request = f"GET /searchJSON?q={city}&maxRows=1&username=jesusortega HTTP/1.1\r\n"
    request += f"Host: {host}\r\n"
    request += "Connection: close\r\n\r\n"

    # Enviar la solicitud
    sock.send(request.encode())

    # Recibir la respuesta
    response = sock.recv(4096)

    # Mostrar la respuesta
    print(response.decode())

    # Cerrar el socket
    sock.close()

def geonamesWS(city):

    response = requests.get(f"http://api.geonames.org/searchJSON?q={city}&maxRows=1&username=jesusortega")

    # Comprobar si la solicitud fue exitosa
    if response.status_code == 200:
        data = response.json()  # Parsear la respuesta JSON
        # Imprimir la información obtenida
        for geoname in data.get('geonames', []):
            print(f"Nombre: {geoname['name']}")
            print(f"País: {geoname['countryName']}")
            print(f"Latitud: {geoname['lat']}")
            print(f"Longitud: {geoname['lng']}")
    else:
        print(f"Error al hacer la solicitud: {response.status_code}")


if __name__ == '__main__':
    city = input("Enter city name: ")
    service =input("Quiere hacerlo con sockets o con Web Service?:")
    if service == "sockets":
        geonamesSocket(city)
    elif service =="Web Service":
        geonamesWS(city)
    else:
        print("Opción invalida")