import requests

def obtener_informacion_ubicacion(geonames_username, lugar):
    url = f"http://api.geonames.org/searchJSON?name={lugar}&maxRows=1&username={geonames_username}"
    api_key = "f640ec59c506fd00ace1026b544f0779" # api key
    ciudad=""

    try:
        response = requests.get(url)
        data = response.json()
        if "geonames" in data and data["geonames"]:
            ubicacion = data["geonames"][0]
            #print(f"{ubicacion}")
            #print(f"Nombre: {ubicacion['name']}")
            ciudad=ubicacion['name']
            codigo=ubicacion['countryCode']
            obtener_datos_meteorologicos(api_key,ciudad,codigo)
        else:
            print("Ubicación no encontrada.")
    except Exception as e:
        print(f"Error: {str(e)}")


def obtener_datos_meteorologicos(api_key,ciudad,codigo):
    url = f"http://api.openweathermap.org/data/2.5/weather?q={ciudad}&appid={api_key}"

    try:
        response = requests.get(url)
        data = response.json()
        if "main" in data and "weather" in data:
            temperatura = data["main"]["temp"] - 273.15  # Convertir de Kelvin a Celsius
            condiciones_climaticas = data["weather"][0]["description"]
            print(f"Temperatura en {ciudad}, {codigo}: {temperatura:.2f}°C")
            print(f"Condiciones Climáticas en {ciudad}, {codigo}: {condiciones_climaticas}")
        else:
            print("Datos meteorológicos no disponibles.")
    except Exception as e:
        print(f"Error: {str(e)}")


if __name__ == "__main__":
    #Coloca tu usuario de geonames
    geonames_username = "jesusortega"
    lugar = "Paris"  # Cambia esto a la ubicación que desees consultar
    obtener_informacion_ubicacion(geonames_username, lugar)