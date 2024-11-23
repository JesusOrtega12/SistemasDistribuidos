import requests
import socket

def OpenWeatherSocket(city):
        
    host = "api.openweathermap.org"
    puerto = 80 

    # Formar la solicitud HTTP
    ruta = f"/data/2.5/weather?q={city}&appid=f640ec59c506fd00ace1026b544f0779&units=metric"  # Usamos 'metric' para Celsius

    # Crear un socket TCP
    cliente_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Conectar al servidor OpenWeather
    cliente_socket.connect((host, puerto))

   # Preparar la solicitud HTTP
    mensaje_http = f"GET {ruta} HTTP/1.1\r\nHost: {host}\r\nConnection: close\r\n\r\n"

    # Enviar la solicitud HTTP al servidor
    cliente_socket.sendall(mensaje_http.encode())

    # Recibir la respuesta del servidor
    respuesta = b""
    while True:
        data = cliente_socket.recv(4096)
        if not data:
            break
        respuesta += data

    # Cerrar la conexión del socket
    cliente_socket.close()

    # Decodificar la respuesta en formato JSON (esto sería en formato UTF-8)
    try:
        # El primer bloque de la respuesta es la cabecera HTTP, y el segundo es el cuerpo con los datos en JSON
        cuerpo = respuesta.split(b'\r\n\r\n')[1]
        datos = cuerpo.decode('utf-8')

        # Buscar el valor de la temperatura en el JSON
        import json
        json_datos = json.loads(datos)
        temperatura = json_datos['main']['temp']
        return temperatura
    except Exception as e:
        print("Error al procesar la respuesta:", e)
        return None

def OpenWeatherWS(city):
    # URL base de la API de OpenWeather
    url = "http://api.openweathermap.org/data/2.5/weather"
    
    # Parámetros para la solicitud (incluyendo ciudad y clave de API)
    parametros = {
        'q': city,          # Nombre de la ciudad
        'appid': 'f640ec59c506fd00ace1026b544f0779',     
        'units': 'metric'     # Unidades de temperatura en Celsius
    }
    
    # Realizar la solicitud GET al web service
    respuesta = requests.get(url, params=parametros)
    
    # Verificar si la solicitud fue exitosa
    if respuesta.status_code == 200:
        # Convertir la respuesta JSON a un diccionario
        datos = respuesta.json()
        # Obtener la temperatura
        temperatura = datos['main']['temp']
        return temperatura
    else:
        # Si la solicitud no fue exitosa, imprimir el error
        print(f"Error al obtener datos: {respuesta.status_code}")
        return None


if __name__ == '__main__':
    city = input("Enter city name: ")
    service =input("Quiere hacerlo con sockets o con Web Service?:")
    if service == "sockets":
        temperatura = OpenWeatherSocket(city)
        if temperatura is not None:
            print(f"La temperatura actual en {city} es {temperatura}°C.")
        else:
            print("No se pudo obtener la temperatura.")
    elif service =="Web Service":
        temperatura = OpenWeatherWS(city)
        if temperatura is not None:
            print(f"La temperatura actual en {city} es {temperatura}°C.")
        else:
            print("No se pudo obtener la temperatura.")
    else:
        print("Opción invalida")